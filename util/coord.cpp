
/*
//
// miniscsim library, Copyright (C) 200,20094 - Bernd H Stramm
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

#include "coord.h"
#include <math.h>
#include <string>
#include <sstream>

namespace berndsutil {

  using namespace std;

Coord::Coord()
  :myX(0.0),myY(0.0),myZ(0.0)
{}

Coord::Coord(double X, double Y, double Z)
  :myX(X),myY(Y),myZ(Z)
{}

Coord::Coord(const Coord& c)
  :myX(c.myX),myY(c.myY),myZ(c.myZ)
{}

Coord::~Coord()
{}

double
Coord::Abs()
{
  return sqrt((myX*myX)+(myY*myY)+(myZ*myZ));
}

double
Abs ( Coord c )
{
  return c.Abs();
}


void
Coord::Rotate2 (double theta)
{
  double sint = sin(theta), cost = cos(theta);
  double newX = cost * myX - sint * myY;
  double newY = sint * myX + cost * myY;
  myX = newX; myY = newY;
}

Coord
Rotate2 (Coord c, double theta)
{
  double sint = sin(theta), cost = cos(theta);
  double newX = cost * c.myX - sint * c.myY;
  double newY = sint * c.myX + cost * c.myY;
  return Coord (newX,newY,c.myZ);
}

Coord
Coord::Unit()
{  
  double x = myX, y = myY , z = myZ;
  double l = sqrt(x*x+ y*y + z*z);
  x = x/l;
  y = y/l;
  z = z/l;

  return Coord (x,y,z);
}

Coord
Unit (Coord c)
{
  double x = c.X(), y = c.Y() , z = c.Z();
  double l = sqrt(x*x+ y*y + z*z);
  if (l > 0.0) {
    x = x/l;
    y = y/l;
    z = z/l;
  } else {
    x = y = z = 0.0;
  }

  return Coord (x,y,z);
}

double
Dist (const Coord c1, const Coord c2)
{
  double dX = c1.myX - c2.myX;
  double dY = c1.myY - c2.myY;
  double dZ = c1.myZ - c2.myZ;
  return sqrt((dX*dX)+(dY*dY)+(dZ*dZ));
}

std::string
Coord::String()
{
  ostringstream sX, sY, sZ;
  sX << myX; sY << myY; sZ << myZ;
  return string("(") + sX.str() 
      + string(",") + sY.str() 
      + string(",") +  sZ.str()  
      + string(")");
}

int
operator== (const Coord c1, const Coord c2)
{
  return c1.myX == c2.myX 
         && c1.myY == c2.myY
         && c1.myZ == c2.myZ;
}

int
operator!= (const Coord c1, const Coord c2)
{ return !(c1==c2) ; }

Coord 
operator+ (const Coord c1, const Coord c2)
{
  return Coord(c1.myX+c2.myX,c1.myY+c2.myY,c1.myZ+c2.myZ);
}


Coord
operator- (const Coord c1, const Coord c2)
{
  return Coord (c1.myX - c2.myX, c1.myY - c2.myY, c1.myZ-c2.myZ);
}

Coord
operator* (const Coord c1, const double f)
{
  return Coord (c1.myX*f, c1.myY*f,c1.myZ*f);
}




Coord 
operator* (const double f, const Coord c2)
{ return c2*f ; }


Coord 
operator* (const float f, const Coord c2)
{ return c2*double(f); }

Coord 
operator* (const Coord c1, const float f)
{ return c1*double(f); }

std::ostream& 
operator<< (std::ostream& out, const Coord c)
{ 
  out << "( " << c.X() << " , " << c.Y() << " , " << c.Z() << " )";
  return out;
}

bool
LexicalLessCoord::operator() (Coord c1, Coord c2) 
{
  if (c1.myX > c2.myX) return false;
  if (c1.myY > c2.myY) return false;
  if (c1.myZ > c2.myZ) return false;
  // at this point, c1 < c2 or c1 == c2
  return c1 != c2;
}

} // namespace
