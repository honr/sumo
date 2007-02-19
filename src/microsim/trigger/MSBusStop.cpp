/****************************************************************************/
/// @file    MSBusStop.cpp
/// @author  Daniel Krajzewicz
/// @date    Mon, 13.12.2005
/// @version $Id$
///
// A point vehicles can halt at.
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

#include <cassert>
#include "MSTrigger.h"
#include "MSBusStop.h"


// ===========================================================================
// method definitions
// ===========================================================================
MSBusStop::MSBusStop(const std::string &id,
                     const std::vector<std::string> &lines,
                     MSLane &lane,
                     SUMOReal begPos, SUMOReal endPos)
        : MSTrigger(id), myLines(lines), myLane(lane),
        myBegPos(begPos), myEndPos(endPos), myLastFreePos(endPos)
{
    computeLastFreePos();
}


MSBusStop::~MSBusStop()
{}


const MSLane &
MSBusStop::getLane() const
{
    return myLane;
}


SUMOReal
MSBusStop::getBeginLanePosition() const
{
    return myBegPos;
}


SUMOReal
MSBusStop::getEndLanePosition() const
{
    return myEndPos;
}


void
MSBusStop::enter(void *what, SUMOReal beg, SUMOReal end)
{
    myEndPositions[what] = std::pair<SUMOReal, SUMOReal>(beg, end);
    computeLastFreePos();
//    myLeftPlace = myEndPos - myLastFreePos;
}


SUMOReal
MSBusStop::getLastFreePos() const
{
    return myLastFreePos;
}


void
MSBusStop::leaveFrom(void *what)
{
    assert(myEndPositions.find(what)!=myEndPositions.end());
    myEndPositions.erase(myEndPositions.find(what));
    computeLastFreePos();
}


void
MSBusStop::computeLastFreePos()
{
    myLastFreePos = myEndPos;
    std::map<void*, std::pair<SUMOReal, SUMOReal> >::iterator i;
    for (i=myEndPositions.begin(); i!=myEndPositions.end(); i++) {
        if (myLastFreePos>(*i).second.second) {
            myLastFreePos = (*i).second.second;
        }
    }
}



/****************************************************************************/

