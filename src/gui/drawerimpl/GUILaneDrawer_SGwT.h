#ifndef GUILaneDrawer_SGwT_h
#define GUILaneDrawer_SGwT_h
//---------------------------------------------------------------------------//
//                        GUILaneDrawer_SGwT.cpp -
//  Class for drawing lanes with simple geometry and tooltips
//                           -------------------
//  project              : SUMO - Simulation of Urban MObility
//  begin                : Tue, 02.09.2003
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
// $Log$
// Revision 1.2  2003/09/17 06:45:11  dkrajzew
// some documentation added/patched
//
// Revision 1.1  2003/09/05 14:50:39  dkrajzew
// implementations of artefact drawers moved to folder "drawerimpl"
//
//
//
/* =========================================================================
 * included modules
 * ======================================================================= */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif // HAVE_CONFIG_H

#include <map>
#include <utils/gfx/RGBColor.h>
#include "GUIBaseLaneDrawer.h"


/* =========================================================================
 * class declarations
 * ======================================================================= */
class GUILaneWrapper;
class Position2D;


/* =========================================================================
 * class definitions
 * ======================================================================= */
/**
 * Draws lanes as simple, one-colored straights
 */
class GUILaneDrawer_SGwT : public GUIBaseLaneDrawer {
public:
    /// constructor
    GUILaneDrawer_SGwT(std::vector<GUIEdge*> &edges);

    /// destructor
    ~GUILaneDrawer_SGwT();

private:
    /// draws a single vehicle;
    void drawLane(const GUILaneWrapper &lane,
        GUISUMOAbstractView::LaneColoringScheme scheme, double width);

};


/**************** DO NOT DEFINE ANYTHING AFTER THE INCLUDE *****************/
//#ifndef DISABLE_INLINE
//#include "GUILaneDrawer_SGwT.icc"
//#endif

#endif

// Local Variables:
// mode:C++
// End:

