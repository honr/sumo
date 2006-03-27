//---------------------------------------------------------------------------//
//                        GeomConvHelper.h -
//  Some helping functions for geometry parsing
//                           -------------------
//  project              : SUMO - Simulation of Urban MObility
//  begin                : Sept 2003
//  copyright            : (C) 2003 by Daniel Krajzewicz
//  organisation         : IVF/DLR http://ivf.dlr.de
//  email                : Daniel.Krajzewicz@dlr.de
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//---------------------------------------------------------------------------//
namespace
{
    const char rcsid[] =
    "$Id$";
}
// $Log$
// Revision 1.7  2006/03/27 07:33:01  dkrajzew
// added projection information to the network
//
// Revision 1.6  2005/10/07 11:44:16  dkrajzew
// THIRD LARGE CODE RECHECK: patched problems on Linux/Windows configs
//
// Revision 1.5  2005/09/23 06:07:01  dkrajzew
// SECOND LARGE CODE RECHECK: converted doubles and floats to SUMOReal
//
// Revision 1.4  2005/09/15 12:18:19  dkrajzew
// LARGE CODE RECHECK
//
// Revision 1.3  2005/04/28 09:02:48  dkrajzew
// level3 warnings removed
//
// Revision 1.2  2003/12/09 11:32:50  dkrajzew
// documentation added
//
/* =========================================================================
 * compiler pragmas
 * ======================================================================= */
#pragma warning(disable: 4786)


/* =========================================================================
 * included modules
 * ======================================================================= */
#ifdef HAVE_CONFIG_H
#ifdef WIN32
#include <windows_config.h>
#else
#include <config.h>
#endif
#endif // HAVE_CONFIG_H

#include <string>
#include <utils/geom/Position2DVector.h>
#include <utils/common/MsgHandler.h>
#include <utils/common/StringTokenizer.h>
#include <utils/common/TplConvert.h>
#include "GeomConvHelper.h"

#ifdef _DEBUG
#include <utils/dev/debug_new.h>
#endif // _DEBUG


/* =========================================================================
 * method definitions
 * ======================================================================= */
Position2DVector
GeomConvHelper::parseShape(const std::string &shpdef)
{
    StringTokenizer st(shpdef, " ");
    Position2DVector shape;
    while(st.hasNext()) {
        StringTokenizer pos(st.next(), ",");
        SUMOReal x = TplConvert<char>::_2SUMOReal(pos.next().c_str());
        SUMOReal y = TplConvert<char>::_2SUMOReal(pos.next().c_str());
        shape.push_back(
            Position2D(x, y));
    }
    return shape;
}


Boundary
GeomConvHelper::parseBoundary(const std::string &def)
{
    StringTokenizer st(def, ",");
    if(st.size()!=4) {
        MsgHandler::getErrorInstance()->inform("Could not parse '" + def + "' as boundary.");
        throw ProcessError();
    }
    SUMOReal xmin = TplConvert<char>::_2SUMOReal(st.next().c_str());
    SUMOReal ymin = TplConvert<char>::_2SUMOReal(st.next().c_str());
    SUMOReal xmax = TplConvert<char>::_2SUMOReal(st.next().c_str());
    SUMOReal ymax = TplConvert<char>::_2SUMOReal(st.next().c_str());
    return Boundary(xmin, ymin, xmax, ymax);
}


/**************** DO NOT DEFINE ANYTHING AFTER THE INCLUDE *****************/

// Local Variables:
// mode:C++
// End:

