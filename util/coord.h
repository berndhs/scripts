
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

#ifndef COORD_H
#define COORD_H


#include <iostream>
#include <string>



namespace berndsutil {

/** @ingroup BerndsUtils */

/** @brief Coord is a vector of 3 components. Lazy people can use it as a 2-component.
 *  These work as points, differences or whatever pleases the user. All the arithmetic
 *  done by the operators is cartesian stuff, no polar.
 */

class Coord {

 public:

  Coord();
  Coord (double X, double Y, double Z=0.0);
  Coord (const Coord& c);

  ~Coord();

  static Coord Zero() { return Coord(0.0,0.0,0.0);}


  double X() const { return myX; }
  double Y() const { return myY; }
  double Z() const { return myZ; }
  double X(double x) { return myX = x; }
  double Y(double y) { return myY = y; }
  double Z(double z) { return myZ = z; }
  double Abs();

  void Rotate2 (double theta); 
  friend Coord Rotate2 (Coord c, double theta);

  Coord Unit ();
  friend Coord Unit (Coord c);
  void Add (const Coord c) { myX += c.myX; myY += c.myY; myZ += c.myZ; }

  std::string String();

  friend double Abs(Coord c1);

 
  friend double Dist (const Coord c1, const Coord c2);

  friend int operator== (const Coord c1, 
			 const Coord c2);

  friend Coord operator+ (const Coord c1,
                          const Coord c2);

  friend Coord operator- (const Coord c1,
                          const Coord c2);
 
  friend Coord operator* (const Coord c1,
                          const double  f);
friend Coord operator* (const double f, const Coord c2);

friend Coord operator* (const float f, const Coord c2);

friend Coord operator* (const Coord c1, const float f);

friend std::ostream& operator<<(std::ostream& out, const Coord c);
friend int operator!= (const Coord c1, const Coord c2);

 friend class LexicalLessCoord;

 private:

    double myX;
    double myY;
    double myZ;


};

 class LexicalLessCoord {
 public:
   bool operator() (Coord c1, Coord c2);
 };


} // namespace

#endif
