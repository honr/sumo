/****************************************************************************/
/// @file    MSInductLoop.cpp
/// @author  Christian Roessel
/// @date    dev.writeString("<interval begin=\"").writeString(
/// @version $Id$
///
// * @author Christian Roessel
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
// copyright : (C) 2001-2007
//  by DLR (http://www.dlr.de/) and ZAIK (http://www.zaik.uni-koeln.de/AFS)
/****************************************************************************/
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
// ===========================================================================
// compiler pragmas
// ===========================================================================
#ifdef _MSC_VER
#pragma warning(disable: 4786)
#endif


// ===========================================================================
// included modules
// ===========================================================================
#ifdef WIN32
#include <windows_config.h>
#else
#include <config.h>
#endif

#include "MSInductLoop.h"
#include <cassert>
#include <numeric>
#include <utility>
#include <utils/helpers/WrappingCommand.h>
#include <utils/common/ToString.h>
#include <microsim/MSEventControl.h>
#include <microsim/MSLane.h>
#include <utils/common/MsgHandler.h>
#include <utils/common/UtilExceptions.h>

#ifdef CHECK_MEMORY_LEAKS
#include <foreign/nvwa/debug_new.h>
#endif // CHECK_MEMORY_LEAKS


// ===========================================================================
// used namespaces
// ===========================================================================
using namespace std;


// ===========================================================================
// member variable definitions
// ===========================================================================
string MSInductLoop::xmlHeaderM(
    "<?xml version=\"1.0\" standalone=\"yes\"?>\n\n"
    "<!--\n"
    "- nVehContrib is the number of vehicles that passed the detector during the\n"
    "  current interval.\n"
    "- flow [veh/h] denotes the same quantity in [veh/h]\n"
    "- occupancy [%] is the time the detector was occupied by vehicles.\n"
    "- speed [m/s] is the average speed of the nVehContib vehicles.\n"
    "  If nVehContrib==0, speed is set to -1.\n"
    //"- speedsquare [(m/s)^2]\n"
    //"  If nVehContrib==0, speedsquare is set to -1.\n"
    "- length [m] is the average vehicle length of the nVehContrib vehicles.\n"
    "  If nVehContrib==0, length is set to -1.\n"
    "-->\n\n");

string MSInductLoop::xmlDetectorInfoEndM("</detector>\n");


// ===========================================================================
// method definitions
// ===========================================================================
MSInductLoop::MSInductLoop(const string& id,
                           MSLane* lane,
                           SUMOReal positionInMeters,
                           SUMOTime deleteDataAfterSeconds)
        : MSMoveReminder(lane), Named(id),
        posM(positionInMeters),
        deleteDataAfterStepsM(MSNet::getSteps((SUMOReal) deleteDataAfterSeconds)),
        lastLeaveTimestepM(0),
        vehiclesOnDetM(),
        vehicleDataContM()
{
    assert(posM >= 0 && posM <= laneM->length());
    // start old-data removal through MSEventControl
    Command* deleteOldData = new WrappingCommand< MSInductLoop >(
                                 this, &MSInductLoop::deleteOldData);
    MSNet::getInstance()->getEndOfTimestepEvents().addEvent(
        deleteOldData, deleteDataAfterStepsM, MSEventControl::ADAPT_AFTER_EXECUTION);
}


MSInductLoop::~MSInductLoop()
{
    vehiclesOnDetM.clear();
    vehicleDataContM.clear();
}


bool
MSInductLoop::isStillActive(MSVehicle& veh,
                            SUMOReal oldPos,
                            SUMOReal newPos,
                            SUMOReal newSpeed)
{
    SUMOReal entryTimestep = (SUMOReal) MSNet::getInstance()->getCurrentTimeStep();
    SUMOReal leaveTimestep = entryTimestep;

    if (newPos < posM) {
        // detector not reached yet
        return true;
    }
    SUMOReal speed = SPEED2DIST(newSpeed);
    if (vehiclesOnDetM.find(&veh) == vehiclesOnDetM.end()) {
        // entered the detector by move
        entryTimestep -= 1 - (posM - oldPos) / speed;
        if (newPos - veh.getLength() > posM) {
            // entered and passed detector in a single timestep
            leaveTimestep -= (newPos - veh.getLength() - posM) / speed;
            enterDetectorByMove(veh, entryTimestep);
            leaveDetectorByMove(veh, leaveTimestep);
            return false;
        }
        // entered detector, but not passed
        enterDetectorByMove(veh, entryTimestep);
        return true;
    } else {
        // vehicle has been on the detector the previous timestep
        if (newPos - veh.getLength() >= posM) {
            // vehicle passed the detector
            leaveTimestep -= (newPos - veh.getLength() - posM) / speed;
            leaveDetectorByMove(veh, leaveTimestep);
            return false;
        }
        // vehicle stays on the detector
        return true;
    }
}


void
MSInductLoop::dismissByLaneChange(MSVehicle& veh)
{
    if (veh.getPositionOnLane() > posM && veh.getPositionOnLane() - veh.getLength() <= posM) {
        // vehicle is on detector during lane change
        leaveDetectorByLaneChange(veh);
    }
}


bool
MSInductLoop::isActivatedByEmitOrLaneChange(MSVehicle& veh)
{
    if (veh.getPositionOnLane() > posM) {
        // vehicle-front is beyond detector. Ignore
        return false;
    }
    // vehicle is in front of detector
    return true;
}


SUMOReal
MSInductLoop::getFlow(SUMOTime lastNTimesteps) const
{
    // return unit is [veh/h]
    assert(lastNTimesteps > 0);
    MSInductLoop::DismissedCont::const_iterator mend = dismissedContM.end();
    return MSNet::getVehPerHour(
               (getNVehContributed(lastNTimesteps) + distance(
                    getDismissedStartIterator(lastNTimesteps), mend))
               / (SUMOReal) lastNTimesteps);
}


SUMOReal
MSInductLoop::getMeanSpeed(SUMOTime lastNTimesteps) const
{
    // return unit is [m/s]
    assert(lastNTimesteps > 0);
    SUMOReal nVeh = getNVehContributed(lastNTimesteps);
    if (nVeh == 0) {
        return -1;
    }
    SUMOReal speedS = accumulate(getStartIterator(lastNTimesteps),
                                 vehicleDataContM.end(),
                                 (SUMOReal) 0.0,
                                 speedSum);
    return MSNet::getMeterPerSecond(speedS / nVeh);
}


SUMOReal
MSInductLoop::getOccupancy(SUMOTime lastNTimesteps) const
{
    // unit is [%]
    assert(lastNTimesteps > 0);
    SUMOReal nVeh = getNVehContributed(lastNTimesteps);
    if (nVeh == 0) {
        return 0;
    }
    return accumulate(getStartIterator(lastNTimesteps),
                      vehicleDataContM.end(),
                      (SUMOReal) 0.0,
                      occupancySum) /
           static_cast<SUMOReal>(lastNTimesteps);
}


SUMOReal
MSInductLoop::getMeanVehicleLength(SUMOTime lastNTimesteps) const
{
    assert(lastNTimesteps > 0);
    SUMOReal nVeh = getNVehContributed(lastNTimesteps);
    if (nVeh == 0) {
        return -1;
    }
    SUMOReal lengthS = accumulate(getStartIterator(lastNTimesteps),
                                  vehicleDataContM.end(),
                                  (SUMOReal) 0.0,
                                  lengthSum);
    return lengthS / nVeh;
}


SUMOReal
MSInductLoop::getTimestepsSinceLastDetection() const
{
    // This method was formely called  getGap()
    if (vehiclesOnDetM.size() != 0) {
        // detetctor is occupied
        return 0;
    }
    return MSNet::getInstance()->getCurrentTimeStep() - lastLeaveTimestepM;
}


SUMOReal
MSInductLoop::getNVehContributed(SUMOTime lastNTimesteps) const
{
    return (SUMOReal) distance(getStartIterator(lastNTimesteps),
                               vehicleDataContM.end());
}


void
MSInductLoop::writeXMLHeader(XMLDevice &dev) const
{
    dev.writeString(xmlHeaderM);
}


void
MSInductLoop::writeXMLDetectorInfoStart(XMLDevice &dev) const
{
    dev.writeString("<detector type=\"inductionloop\" id=\"" + getID() +
                    "\" lane=\"" + laneM->getID() + "\" pos=\"" +
                    toString(posM) + "\" >");
}


void
MSInductLoop::writeXMLDetectorInfoEnd(XMLDevice &dev) const
{
    dev.writeString(xmlDetectorInfoEndM);
}


void
MSInductLoop::writeXMLOutput(XMLDevice &dev,
                             SUMOTime startTime, SUMOTime stopTime)
{
    SUMOTime t(stopTime-startTime+1);
    MSInductLoop::DismissedCont::const_iterator mend = dismissedContM.end();
    size_t nVehCrossed = ((size_t) getNVehContributed(t))
                         + distance(
                             getDismissedStartIterator(t), mend);
    dev.writeString("<interval begin=\"").writeString(
        toString(startTime)).writeString("\" end=\"").writeString(
            toString(stopTime)).writeString("\" ");
    if (dev.needsDetectorName()) {
        dev.writeString("id=\"").writeString(getID()).writeString("\" ");
    }
    dev.writeString("nVehContrib=\"").writeString(
        toString(getNVehContributed(t))).writeString("\" flow=\"").writeString(
            toString(getFlow(t))).writeString("\" occupancy=\"").writeString(
                toString(getOccupancy(t))).writeString("\" speed=\"").writeString(
                    toString(getMeanSpeed(t))).writeString("\" length=\"").writeString(
                        toString(getMeanVehicleLength(t))).writeString("\" nVehCrossed=\"").writeString(
                            toString(nVehCrossed)).writeString("\"/>");
}


void
MSInductLoop::enterDetectorByMove(MSVehicle& veh,
                                  SUMOReal entryTimestep)
{
    vehiclesOnDetM.insert(make_pair(&veh, entryTimestep));
}


void
MSInductLoop::leaveDetectorByMove(MSVehicle& veh,
                                  SUMOReal leaveTimestep)
{
    VehicleMap::iterator it = vehiclesOnDetM.find(&veh);
    assert(it != vehiclesOnDetM.end());
    SUMOReal entryTimestep = it->second;
    vehiclesOnDetM.erase(it);
    assert(entryTimestep < leaveTimestep);
    vehicleDataContM.push_back(VehicleData(veh.getLength(), entryTimestep, leaveTimestep));
    lastLeaveTimestepM = leaveTimestep;
}


void
MSInductLoop::leaveDetectorByLaneChange(MSVehicle& veh)
{
    // Discard entry data
    vehiclesOnDetM.erase(&veh);
    dismissedContM.push_back((SUMOReal) MSNet::getInstance()->getCurrentTimeStep());
}


SUMOTime
MSInductLoop::deleteOldData(SUMOTime)
{
    SUMOReal deleteBeforeTimestep =
        (SUMOReal)(MSNet::getInstance()->getCurrentTimeStep() - deleteDataAfterStepsM);
    if (deleteBeforeTimestep > 0) {
        vehicleDataContM.erase(
            vehicleDataContM.begin(),
            lower_bound(vehicleDataContM.begin(),
                        vehicleDataContM.end(),
                        VehicleData(5, 0.0f, deleteBeforeTimestep),
                        leaveTimeLesser()));
        dismissedContM.erase(
            dismissedContM.begin(),
            lower_bound(dismissedContM.begin(),
                        dismissedContM.end(),
                        deleteBeforeTimestep));
    }
    return deleteDataAfterStepsM;
}


MSInductLoop::VehicleDataCont::const_iterator
MSInductLoop::getStartIterator(SUMOTime lastNTimesteps) const
{
    SUMOReal startTime = 0;
    if (lastNTimesteps < MSNet::getInstance()->getCurrentTimeStep()) {
        startTime = static_cast< SUMOReal >(
                        MSNet::getInstance()->getCurrentTimeStep() - lastNTimesteps) *
                    MSNet::deltaT();
    }
    return lower_bound(vehicleDataContM.begin(),
                       vehicleDataContM.end(),
                       VehicleData(5, 0.0f, startTime),
                       leaveTimeLesser());
}


MSInductLoop::DismissedCont::const_iterator
MSInductLoop::getDismissedStartIterator(SUMOTime lastNTimesteps) const
{
    SUMOReal startTime = 0;
    if (lastNTimesteps < MSNet::getInstance()->getCurrentTimeStep()) {
        startTime = static_cast< SUMOReal >(
                        MSNet::getInstance()->getCurrentTimeStep() - lastNTimesteps) *
                    MSNet::deltaT();
    }
    return lower_bound(dismissedContM.begin(),
                       dismissedContM.end(),
                       startTime);
}



/****************************************************************************/

