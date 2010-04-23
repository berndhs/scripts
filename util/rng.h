#ifndef RNG_H
#define RNG_H

//
//  Copyright (C) 2009 - Bernd H Stramm 
//
// This program is distributed under the terms of 
// the GNU General Public License version 3 
//
// This software is distributed in the hope that it will be useful, 
// but WITHOUT ANY WARRANTY; without even the implied warranty 
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
//

namespace deliberate {

  class Rng_LCG_GN {
    
  public:

    Rng_LCG_GN ();

    void Seed (unsigned long long int s) { Xn = s; }

    unsigned int  OneTo4();

  private:
    unsigned long long int  A;
    unsigned long long int  C;
    unsigned long long int  M;

    unsigned long long int  Xn;

  };

} // namespace


#endif
