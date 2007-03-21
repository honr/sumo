/****************************************************************************/
/// @file    GUIAppEnum.h
/// @author  Daniel Krajzewicz
/// @date    Mon, 08.03.2004
/// @version $Id$
///
// Message and object IDs used by the FOX-version of the gui
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
#ifndef GUIAppEnum_h
#define GUIAppEnum_h
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

#include <fx.h>


// ===========================================================================
// enumeration
// ===========================================================================
enum {
    /// Show about - dialog
    ID_ABOUT=FXMainWindow::ID_LAST,

    //@{ Application specific
    /// Main window-ID
    MID_WINDOW,
    /// Main window closes
    MID_QUIT,
    //@}

    //@{ For some always used buttons
    /// Ok-button pressed
    MID_OK,
    /// Cancel-button pressed
    MID_CANCEL,
    //@}

    //@{ Main Window File Menu - IDs
    /// Open new file - ID
    MID_OPEN,
    /// Reload the previously loaded simulation
    MID_RELOAD,
    /// Loads a file previously loaded
    MID_RECENTFILE,
    /// Close simulation - ID
    MID_CLOSE,
    /// About SUMO - ID
    MID_ABOUT,
    //@}

    //@{ Main Window Simulation Control - IDs
    /// Start the simulation
    MID_START,
    /// Stop the simulation
    MID_STOP,
    /// Perform a single simulation step
    MID_STEP,
    //@}

    //@{ Main window windows control - IDs
    /// Open a new microscopic view
    MID_NEW_MICROVIEW,
#ifdef HAVE_MESOSIM
    /// Open a new mesoscopic view
    MID_NEW_MESOVIEW,
#endif
    //@}

    //@{ SubThread - IDs
    /// The loading thread
    ID_LOADTHREAD_EVENT,
    /// The Simulation execution thread
    ID_RUNTHREAD_EVENT,
    /// ID for message passing between threads
    ID_THREAD_EVENT,
    //@}


    //@{ Edit Menu Item - IDs
    /// Open chosen editor - ID
    MID_EDITCHOSEN,
    /// Edit additional weights - ID
    MID_EDIT_ADD_WEIGHTS,
    /// Edit simulation breakpoints
    MID_EDIT_BREAKPOINTS,

    MID_CONNECTIONS,
    //@}

    //@{ Settings Menu Item - IDs
    /// Application settings - menu entry
    MID_APPSETTINGS,
    /// Simulation settings - menu entry
    MID_SIMSETTINGS,
    /// The Simulation delay control
    MID_SIMDELAY,
    //@}

    //@{ Image Menu Item - IDs
    /// Street extraction - menu entry
    MID_EXTRACT_STREETS,
    /// Dilation - menu entry
    MID_DILATION,
    /// Erosion - menu entry
    MID_EROSION,
    /// Opening - menu entry
    MID_OPENING,
    /// Closing - menu entry
    MID_CLOSING,
    /// Close Gaps - menu entry
    MID_CLOSE_GAPS,
    /// Skeletonize - menu entry
    MID_SKELETONIZE,
    /// Rarify - menu entry
    MID_RARIFY,
    /// Rarify - menu entry
    MID_ERASE_STAINS,
    /// Create Graph - menu entry
    MID_CREATE_GRAPH,
    /// Opens a dialog window for image-filter configuration
    MID_OPEN_BMP_DIALOG,
    //@}
    // Clear simulation settings
    MID_CLEARMESSAGEWINDOW,

    // Create drawing canvas for an image
    ID_CANVAS,
    // Clear the drawing canvas
    ID_CLEAR,

    //@{ Graph menu item - IDs
    ///Show graph on empty bitmap - menu entry
    MID_SHOW_GRAPH_ON_EMPTY_BITMAP,
    ///Show graph on actual bitmap - menu entry
    MID_SHOW_GRAPH_ON_ACTUAL_BITMAP,
    ///Reduce vertexes - menu entry
    MID_REDUCE_VERTEXES,
    ///Reduce vertexes plus - menu entry
    MID_REDUCE_VERTEXES_PLUS,
    ///Reduce edges - menu entry
    MID_REDUCE_EDGES,
    ///Merge vertexes - menu entry
    MID_MERGE_VERTEXES,
    ///Export vertex XML -menu entry
    MID_EXPORT_VERTEXES_XML,
    ///Export edges XML - menu entry
    MID_EXPORT_EDGES_XML,
    //@}

    //@{ Common View Settings - IDs
    /// Recenter view - button
    MID_RECENTERVIEW,
    /// Allow rotation - button
    MID_ALLOWROTATION,
    /// Locate junction - button
    MID_LOCATEJUNCTION,
    /// Locate edge - button
    MID_LOCATEEDGE,
    /// Locate vehicle - button
    MID_LOCATEVEHICLE,
    /// Locate addtional structure - button
    MID_LOCATEADD,
    /// Open viewport editor - button
    MID_EDITVIEWPORT,
    /// Open view editor - button
    MID_EDITVIEWSCHEME,
    /// Show grid - button
    MID_SHOWGRID,
    /// Show tool tips - button
    MID_SHOWTOOLTIPS,
    /// Graph edit button
    MID_EDIT_GRAPH,
    /// Make snapshot - button
    MID_MAKESNAPSHOT,
    //@}

    //@{ Common view IDs
    /// GLCanvas - ID
    MID_GLCANVAS,
    //@}

    //@{ View settings - IDs
    /// Change coloring scheme - combo
    MID_COLOURSCHEMECHANGE,
    /// Change the aggregation time value - combo
    MID_LANEAGGTIME,
    /// The aggregation memory - dial
    MID_LANEAGGRMEM,
    //@}


    //@{ Object PopUp Entries - IDs
    /// Center view to object - menu entry
    MID_CENTER,
    /// Center view to object - menu entry
    MID_COPY_NAME,
    /// Center View to object - menu entry
    MID_COPY_TYPED_NAME,
    /// Show object parameter - menu entry
    MID_SHOWPARS,
    /// Show TLS phases - menu entry
    MID_SWITCH,
    MID_SHOWPHASES = MID_SWITCH + 20,
    /// Begin to track phases - menu entry
    MID_TRACKPHASES,
    /// Add to selected items - menu entry
    MID_ADDSELECT,
    /// Add successors to selected items - menu entry
    MID_ADDSELECT_SUCC,
    /// Remove from selected items - Menu Etry
    MID_REMOVESELECT,
    /// Open the object's manipulator
    MID_MANIP,
    /// Draw a vehicle's route
    MID_DRAWROUTE,
    /// Show vehicle's current route
    MID_SHOW_CURRENTROUTE,
    /// Hide vehicle's current route
    MID_HIDE_CURRENTROUTE,
    /// Show all vehicle's routes
    MID_SHOW_ALLROUTES,
    /// Hide all vehicle's routes
    MID_HIDE_ALLROUTES,
    /// Start to track a vehicle
    MID_START_TRACK,
    /// Stop to track a vehicle
    MID_STOP_TRACK,
    /// Rename the object
    MID_RENAME,
    /// Move object to another position
    MID_MOVETO,
    /// Change the color of an object
    MID_CHANGECOL,
    /// Change the type of an object
    MID_CHANGETYPE,
    /// Delete an object
    MID_DELETE,
    //@}

    //@{ IDs used by Trackers
    /// The Table
    MID_TABLE,
    /// A Simulation step was performed
    MID_SIMSTEP,
    /// A Tracker shall be opened
    MID_OPENTRACKER,
    //@}

    //@{ General Setting Dialogs - IDs
    /// Ok-button was pushed
    MID_SETTINGS_OK,
    /// Cancel-button was pushed
    MID_SETTINGS_CANCEL,
    /// Save-button was pushed
    MID_SETTINGS_SAVE,
    //@}

    //@{ Application Settings - Dialog IDs
    /// Close simulation at end - Option
    MID_QUITONSIMEND,
    /// Suppress end message - Option
    MID_SURPRESSENDINFO,
    /// Allow textures - Option
    MID_ALLOWTEXTURES,
    //@}

    //@{ GLObjChooser - Dialog IDs
    /// Center object
    MID_CHOOSER_CENTER,
    /// Text entry
    MID_CHOOSER_TEXT,
    /// Object list
    MID_CHOOSER_LIST,
    //@}

    //@{ GLChosenEditor - Dialog IDs
    /// Load set
    MID_CHOOSEN_LOAD,
    /// Save set
    MID_CHOOSEN_SAVE,
    /// Clear set
    MID_CHOOSEN_CLEAR,
    /// Deselect selected items
    MID_CHOOSEN_DESELECT,
    //@}


    MID_CLEARPREVIOUS,
    MID_SUBMIT,
    MID_PROBABILITY,
    MID_LEVEL,
    MID_PERIOD,
    MID_TIME_SLIDER,

    //@{ IDs for netedit
    /// Import a network - menu entry
    MID_IMPORT_NET,
    /// Open a bitmap file - menu entry
    MID_LOAD_IMAGE,
    /// Write a loaded bitmap file - menu entry
    MID_SAVE_IMAGE,
    /// ID for the imageviewer
    MID_MAP_IMAGEVIEWER,
    /// Save generated edges and nodes - menu entry
    MID_SAVE_EDGES_NODES,
    /// Save generated SUMO-network - menu entry
    MID_SAVE_NET,
    //@}

    MID_SIMPLE_VIEW_COLORCHANGE,
    MID_SIMPLE_VIEW_NAMECHANGE,


    MID_CUTSWELL,

    MID_LAST
};


#endif

/****************************************************************************/

