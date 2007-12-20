/****************************************************************************/
/// @file    MSVehicleQuitReminded.h
/// @author  Daniel Krajzewicz
/// @date    2004-02-05
/// @version $Id$
///
//	»missingDescription«
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
#ifndef MSVehicleQuitReminded_h
#define MSVehicleQuitReminded_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif


// ===========================================================================
// class declarations
// ===========================================================================
class MSVehicle;


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class MSVehicleQuitReminded
 * @brief Abstract class for things that shall be informed about a certain vehicle's quitting
 *
 * Because several classes track vehicles using own containers, it is necessary
 *  to inform them as soon one of these tracked vehicles disappears from
 *  the simulation. So it's besically a listener...
 *
 * For this, each vehicle holds a list of structures to be informed about its
 *  leaving from the net. Each element of this list has to be derived from 
 *  MSVehicleQuitReminded and will be informed about the vehicle's leaving
 *  via removeOnTripEnd.
 *
 * A vehicle has to be informed about a listener using "quitRemindedEnter". A
 *  listener may be removed from the vehicle using "quitRemindedLeft".
 */
class MSVehicleQuitReminded
{
public:
    /// @brief (Virtual) destructor
    virtual ~MSVehicleQuitReminded() {}


    /// @name Abstract Methods to be implemented by derived classes
    /// @{
    /** @brief Called when the observed vehicle leaves the simulation
     * 
     * @param[in] veh The vehicle that quits the simulation
     */
    virtual void removeOnTripEnd(MSVehicle *veh) = 0;
    /// @}

};


#endif

/****************************************************************************/

