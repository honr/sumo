#ifndef GUIBaseJunctionDrawer_h
#define GUIBaseJunctionDrawer_h
//---------------------------------------------------------------------------//
//                        GUIBaseJunctionDrawer.h -
//  Base class for drawing junctions
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

#include <vector>
#include <gui/GUISUMOAbstractView.h>

class GUIJunctionWrapper;

class GUIBaseJunctionDrawer :
    public GUISUMOAbstractView::GUIJunctionDrawer
{
public:
    GUIBaseJunctionDrawer(std::vector<GUIJunctionWrapper*> &junctions);
    virtual ~GUIBaseJunctionDrawer();
    virtual void drawGLJunctions(size_t *which, size_t maxJunctions,
        GUISUMOAbstractView::JunctionColoringScheme scheme) = 0;
};

#endif
