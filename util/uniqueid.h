/*
//
// miniscsim library, Copyright (C) 2004,2009 - Bernd H Stramm
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it may be useful,
// but WITHOUT ANY WARRANTY; WITHOUT EVEN THE IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
*/
#ifndef UNIQUEID_H
#define UNIQUEID_H

#if HAVE_CONFIG_H
#include <config.h>
#endif


#include <string>
#include <iostream>

namespace berndsutil {



/** @defgroup BerndsUtils
 * This is a collection of utilities. They don't fit in any specific group, and there isn't one
 * hierarchy for them. Perhaps one day they deserve their own namespace, when there are enough of them.
 * but for now, I leave them just as a doxygen module.
 */

/** @ingroup BerndsUtils */

/** @brief UniqueID is for everything that we want to identify. Useful for debugging,
 * for example. Also useful to track how objects travel through lists, tables
 * and such. 
 * Note however that if you use it too frivolously, your code might spend a lot of
 * time allocating and deallocating these small objects.
 * **/
class UniqueID {

 public:

    UniqueID () 
         :myID(lastID),original(true) 
         { lastID++ ; myName="?"; }

    UniqueID (const UniqueID& old)
         :myID(old.myID),original(false)
         { myName = old.myName; }

    UniqueID (UniqueID& old)
         :myID(old.myID),original(false)
         { myName = old.myName; }

    UniqueID& operator= (const UniqueID u);

    UniqueID& UID() { return *this; }

    bool Original() { return original; }

    int Id () const { return myID; }
    std::string UName() const { return myName; }
    std::string String();
    
    void SetUName(std::string n) { myName = n; }

    friend int operator== (UniqueID u1, UniqueID u2);
    friend int operator< (UniqueID u1, UniqueID u2);
    friend int SameOriginal (UniqueID uq, UniqueID u2);

    friend std::ostream& operator<< (std::ostream & out,
                          const UniqueID ui);

 protected:

  void ForceID (int id) { myID = id; original = false; }
 
private:

  static int      lastID;

  int  myID;
  bool original;
  std::string myName;
};
} // namespace

#endif
