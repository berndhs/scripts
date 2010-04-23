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
#include "uniqueid.h"
#include <sstream>

namespace berndsutil {

int UniqueID::lastID = 1;

UniqueID&
UniqueID::operator= (const UniqueID u)
{
  myID = u.myID;
  original = false;
  return *this;
}

std::string
UniqueID::String() 
{
  std::ostringstream sbuf;
  sbuf << myID;
  return std::string ("(UID " + sbuf.str() + this->UName() + ")");
}

int
operator== (UniqueID u1, UniqueID u2)
{
  return u1.myID == u2.myID;
}

int
operator< (UniqueID u1, UniqueID u2)
{
  return u1.myID < u2.myID;
}

int
SameOriginal (UniqueID u1, UniqueID u2)
{
  return (u1.myID == u2.myID) &&
         (u1.original && u2.original) ;
}

std::ostream& operator<< (std::ostream& out, const UniqueID ui)
{
   out << "<UID " << ui.Id() << " '" << ui.UName() << "'>";
   return out;
}

} // namespace concoct
