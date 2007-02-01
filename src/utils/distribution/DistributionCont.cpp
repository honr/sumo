/****************************************************************************/
/// @file    DistributionCont.cpp
/// @author  Daniel Krajzewicz
/// @date    Sept 2002
/// @version $Id: $
///
// A container for distributions
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
#pragma warning(disable: 4503)
#endif


// ===========================================================================
// included modules
// ===========================================================================
#ifdef WIN32
#include <windows_config.h>
#else
#include <config.h>
#endif

#include "DistributionCont.h"

#ifdef _DEBUG
#include <utils/dev/debug_new.h>
#endif // _DEBUG


// ===========================================================================
// static variable definitions
// ===========================================================================
DistributionCont::TypedDistDict DistributionCont::myDict;


// ===========================================================================
// method definitions
// ===========================================================================
bool
DistributionCont::dictionary(const std::string &type, const std::string &id,
                             Distribution *d)
{
    TypedDistDict::iterator i=myDict.find(type);

    if (i==myDict.end()) {
        myDict[type][id] = d;
        return true;
    }
    DistDict &dict = (*i).second;
    DistDict::iterator j=dict.find(id);
    if (j==dict.end()) {
        myDict[type][id] = d;
        return true;
    }
    return false;
}


Distribution *
DistributionCont::dictionary(const std::string &type,
                             const std::string &id)
{
    TypedDistDict::iterator i=myDict.find(type);
    if (i==myDict.end()) {
        return 0;
    }
    DistDict &dict = (*i).second;
    DistDict::iterator j=dict.find(id);
    if (j==dict.end()) {
        return 0;
    }
    return (*j).second;
}



/****************************************************************************/

