#ifndef GUIGlObjectStorage_h
#define GUIGlObjectStorage_h
//---------------------------------------------------------------------------//
//                        GUIGlObjectStorage.h -
//  A storage for retrival of displayed object using a numerical id
//                           -------------------
//  project              : SUMO - Simulation of Urban MObility
//  begin                : Oct 2002
//  copyright            : (C) 2002 by Daniel Krajzewicz
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
// Revision 1.2  2003/04/14 08:24:56  dkrajzew
// unneeded display switch and zooming option removed; new glo-objct concept implemented; comments added
//
//
/* =========================================================================
 * included modules
 * ======================================================================= */
#include <map>
#include <utils/qutils/NewQMutex.h>


/* =========================================================================
 * class declarations
 * ======================================================================= */
class GUIGlObject;


/* =========================================================================
 * class definitions
 * ======================================================================= */
/**
 * @class GUIGlObjectStorage
 * This is a container for GUIGlObjects - objects, which may are displayed
 * and due to this may generate tooltips or be grapped in other ways.
 * As in case of vehicles (other, later implemented objects may have this
 * property, too) they may be deleted by the simulation while being accessed
 * - for example using a property window or something like that - this
 * container posesses three storages: one containing all objects that are not
 * accessed at all, one for objects currently accessed and one for objects that
 * are accessed but shall be deleted.
 */
class GUIGlObjectStorage {
public:
    /// Constructor
    GUIGlObjectStorage();

    /// Destructor
    ~GUIGlObjectStorage();

    /** @brief registers an object
        This done within the constructor of the GUIGlObject */
    void registerObject(GUIGlObject *object);

    /** @brief Retunrs the object from the container locking it
        The lock prevents the object from being deleted while it is accessed */
    GUIGlObject *getObjectBlocking(size_t id);

    /// Removes the named object from this container
    void remove(size_t id);

    /// Clears this container
    void clear();

    /// Marks an object as unblocked
    void unblockObject(size_t id);

private:
    /// Definition of an associative container from numerical ids to objects
    typedef std::map<size_t, GUIGlObject *> ObjectMap;

    /// The known objects which are not accessed currently
    ObjectMap myMap;

    /// The accessed objects
    ObjectMap myBlocked;

    /// Objects to delete
    ObjectMap my2Delete;

    /** @brief The next id to give
        Initially zero, increased by one with each object registration */
    size_t myAktID;

    /// A lock to avoid parallel access on the storages
    NewQMutex _lock;

private:
    /// Invalidated copy constructor
    GUIGlObjectStorage(const GUIGlObjectStorage &s);

    /// Invalidate assignment operator
    GUIGlObjectStorage &operator=(const GUIGlObjectStorage &s);

};

/**************** DO NOT DEFINE ANYTHING AFTER THE INCLUDE *****************/
//#ifndef DISABLE_INLINE
//#include "GUIGlObjectStorage.icc"
//#endif

#endif

// Local Variables:
// mode:C++
// End:

