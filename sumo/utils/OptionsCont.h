#ifndef OptionsCont_h
#define OptionsCont_h
/***************************************************************************
                          OptionsCont.h
			  A container for options.
			  Allows the access of the values of the stored options
			  using different option names.
                             -------------------
    project              : SUMO
    begin                : Mon, 17 Dec 2001
    copyright            : (C) 2001 by DLR/IVF http://ivf.dlr.de/
    author               : Daniel Krajzewicz
    email                : Daniel.Krajzewicz@dlr.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
// $Log$
// Revision 1.6  2002/07/31 17:30:06  roessel
// Changes since sourceforge cvs request.
//
// Revision 1.6  2002/07/11 07:42:59  dkrajzew
// Usage of relative pathnames within configuration files implemented
//
// Revision 1.6  2002/06/11 15:58:24  dkrajzew
// windows eol removed
//
// Revision 1.5  2002/05/14 04:45:49  dkrajzew
// Bresenham added; some minor changes; windows eol removed
//
// Revision 1.4  2002/04/26 10:08:39  dkrajzew
// Windows eol removed
//
// Revision 1.3  2002/04/17 11:21:52  dkrajzew
// Windows-carriage returns removed
//
// Revision 1.2  2002/04/16 12:28:26  dkrajzew
// Usage of SUMO_DATA removed
//
// Revision 1.1.1.1  2002/04/09 14:18:27  dkrajzew
// new version-free project name (try2)
//
// Revision 1.1.1.1  2002/04/09 13:22:01  dkrajzew
// new version-free project name
//
// Revision 1.5  2002/03/20 08:50:37  dkrajzew
// Revisions patched
//
// Revision 1.4  2002/03/20 08:39:17  dkrajzew
// comments updated
//
// Revision 1.3  2002/03/20 08:38:14  dkrajzew
// isDefault - method added
//
// Revision 1.2  2002/03/11 10:07:52  traffic
// superflous collapse option removed.
//
// Revision 1.1  2002/02/13 15:48:19  croessel
// Merge between SourgeForgeRelease and tesseraCVS.
//
//
/* =========================================================================
 * included modules
 * ======================================================================= */
#include <map>
#include <string>
#include <vector>
#include <iostream>

/* =========================================================================
 * class definitions
 * ======================================================================= */
class Option;

/* =========================================================================
 * class definitions
 * ======================================================================= */
/**
 * OptionsCont
 * A storage for options.
 * Once stored inside this container, options will not be visible to the
 * world and are deleted by the container. Only values and stati of the
 * options may be returned. While accessing the options, the programmer
 * must assure that he asks for the right value (only Option_Bool is able
 * to return a boolean value, other option types do throw exceptions).
 * Further, options added to the container must not be deleted outside
 * this container as they get invalid and cause segmentation violations then.
 * Exceptions:
 * Only the exception "InvalidArgument" from "UtilExceptions" is thrown
 */
class OptionsCont {
 private:
    /** definition of the type that stores the addresses of used options */
    typedef std::vector<Option*> ItemAddressContType;
    /** definition of the type that realises the access to options */
    typedef std::map<std::string, Option*> KnownContType;
    /** storage for option-addresses */
    ItemAddressContType _addresses;
    /** access map of options */
    KnownContType       _values;
    /** the name of the enviroment-variable that stores the path */
    std::string         _path;
 public:
    /** constructor */
    OptionsCont();
    /** constructor */
    OptionsCont(std::string env);
    /** destructor */
    ~OptionsCont();
    /** adds an option under the given name */
    void doRegister(std::string name1, Option *v);
    /** adds an option under the given name and the given abbreviation */
    void doRegister(std::string name1, char abbr, Option *v);
    /** registers a system path (appends the value to the enviroment-path) */
    void doRegisterSystemPath(std::string name, std::string value);
    /** registers a system path (appends the value to the enviroment-path) */
    void doRegisterSystemPath(std::string name1, char abbr, std::string value);
    /** adds a synonymes for an options name (any order) */
    void addSynonyme(std::string name1, std::string name2);
    /** returns the information whether the named option is known */
    bool exists(std::string name) const;
    /** returns the information whether the named option is set */
    bool isSet(std::string name) const;
    /** returns the information whether the named option has still the default value */
    bool isDefault(std::string name) const;
    /** returns the string-value of the named option(only for Option_String) */
    std::string getString(std::string name) const;
    /** returns the float-value of the named option(only for Option_Float) */
    float getFloat(std::string name) const;
    /** returns the int-value of the named option(only for Option_Intger) */
    int getInt(std::string name) const;
    /** returns the long-value of the named option(only for Option_Long) */
    long getLong(std::string name) const;
    /** returns the boolean-value of the named option(only for Option_Bool) */
    bool getBool(std::string name) const;
    /** returns the information whether the option is a boolean option */
    bool isBool(std::string name) const;
    /** sets the given value for the named option */
    bool set(std::string name, std::string value, bool isDefault=false);
    /** sets the given boolean value for the named option (Option_Bool only) */
    bool set(std::string name, bool value, bool isDefault=false);
    /** returns the synonymes of an option name */
    std::vector<std::string> getSynonymes(std::string name) const;
    /** resets all options to be the default value */
    void resetDefaults();
    /// returns the information whether the named item is a file name
    bool isFileName(const std::string &name) const;
    /** output operator */
    friend std::ostream& operator<<( std::ostream& os, const OptionsCont& oc);
    /** returns the path (not the name) */
    std::string getPath() const;

 private:
    /** returns the named option */
   Option *getSecure(std::string name) const;
    /** writes the warning about double setting to cout */
   void reportDoubleSetting(std::string arg) const;
    /** converts an abbreviation into a name */
    std::string convertChar(char abbr) const;
    /** returns the system path */
    std::string getSystemPath(std::string ext) const;

 private:
    /** invalid copy constructor */
    OptionsCont(const OptionsCont &s);
    /** invalid assignment operator */
    OptionsCont &operator=(const OptionsCont &s);
};

/**************** DO NOT DECLARE ANYTHING AFTER THE INCLUDE ****************/
//#ifndef DISABLE_INLINE
//#include "OptionsCont.icc"
//#endif

#endif

// Local Variables:
// mode:C++
// End:



