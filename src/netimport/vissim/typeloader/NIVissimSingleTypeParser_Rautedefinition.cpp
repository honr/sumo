/****************************************************************************/
/// @file    NIVissimSingleTypeParser_Rautedefinition.cpp
/// @author  Daniel Krajzewicz
/// @date    Wed, 18 Dec 2002
/// @version $Id: NIVissimSingleTypeParser_Rautedefinition.cpp 4389 2007-08-28 10:21:00Z behrisch $
///
//
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
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <iostream>
#include <utils/common/TplConvert.h>
#include "../NIVissimLoader.h"
#include "../tempstructs/NIVissimSource.h"
#include "NIVissimSingleTypeParser_Rautedefinition.h"

#ifdef CHECK_MEMORY_LEAKS
#include <foreign/nvwa/debug_new.h>
#endif // CHECK_MEMORY_LEAKS


// ===========================================================================
// used namespaces
// ===========================================================================
using namespace std;


// ===========================================================================
// method definitions
// ===========================================================================
NIVissimSingleTypeParser_Rautedefinition::NIVissimSingleTypeParser_Rautedefinition(NIVissimLoader &parent)
        : NIVissimLoader::VissimSingleTypeParser(parent)
{}


NIVissimSingleTypeParser_Rautedefinition::~NIVissimSingleTypeParser_Rautedefinition()
{}


bool
NIVissimSingleTypeParser_Rautedefinition::parse(std::istream &from)
{
    string t;
    getline(from, t);
    return true;
}



/****************************************************************************/
