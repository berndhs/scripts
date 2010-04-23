#include "rng.h"


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

  Rng_LCG_GN::Rng_LCG_GN ()
    :A(1103515245),
     C(12345),
     M(0xffffffff),
     Xn(12345)
  {
  }

  unsigned int
  Rng_LCG_GN::OneTo4()
  {
    Xn = (A*Xn + C) & M;
    unsigned long int bit1 = (Xn >> 30) & 0x1;
    unsigned long int bit2 = (Xn >> 27) & 0x1;
    return ((bit2 << 1) | bit1) + 1;
  }
    


} // namespace
