/***************************************************************************
                          MemDiff.cpp
			  A class that wraps the MS - memory counting methods
                             -------------------
    project              : SUMO
    begin                : Thu, 07 Jun 2002
    copyright            : (C) 2001 by DLR/IVF http://ivf.dlr.de/
    author               : ? + Daniel Krajzewicz
    email                : Daniel.Krajzewicz@dlr.de

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
// $Log$
// Revision 1.1  2002/10/16 15:09:09  dkrajzew
// initial commit for some utility classes common to most propgrams of the sumo-package
//
// Revision 1.5  2002/06/11 15:58:25  dkrajzew
// windows eol removed
//
// Revision 1.4  2002/06/07 14:58:46  dkrajzew
// Bugs on dead ends and junctions with too few outgoing roads fixed; Comments improved
//
//
/* =========================================================================
 * included modules
 * ======================================================================= */
#include "MemDiff.h"

/* =========================================================================
 * compiler settings
 * ======================================================================= */
#ifdef _DEBUG
   #undef THIS_FILE
   static char THIS_FILE[]=__FILE__;
   #define new DEBUG_NEW
#endif

#ifdef _DEBUG
#ifdef WIN32

#ifndef _INC_CRTDBG

#error Missing include "Supports debugging features of the C runtime library."

#endif

// initializers put in library initialization area
#pragma warning (disable : 4073)
#pragma init_seg(lib)

static CMemDiff gMemDiff;

/* =========================================================================
 * method definitions
 * ======================================================================= */
CMemDiff::CMemDiff()
{
   TRACE(_T("\n--> Started track memory leaks\n\n"));

   // If you remove comment below you would warned about memory
   //  leak without freed.
   // afxMemDF = allocMemDF | delayFreeMemDF | checkAlwaysMemDF;

   AfxEnableMemoryTracking(TRUE);
   Checkpoint();
}

CMemDiff::~CMemDiff()
{
   CMemoryState oMemoryState;
   CMemoryState diffMemoryState;

   oMemoryState.Checkpoint();

   if(diffMemoryState.Difference((*this),oMemoryState))
   {
      //Beep(1000,500);

      TRACE(_T("\n--> Detected memory leaks!\n"));
      diffMemoryState.DumpStatistics();

      // If you remove comment below you could tune output messages.
      // diffMemoryState.DumpAllObjectsSince();
      // TRACE(_T("--> Dump all objects still in heap\n"));
      // AfxDumpMemoryLeaks();
   }

   TRACE(_T("\n--> Finished track memory leaks\n\n"));
}

#endif
#endif
