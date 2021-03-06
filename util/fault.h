
//
//  Copyright (C) 2009 - Bernd H Stramm
//
#ifndef FAULT_H
#define FAULT_H
#include <iostream>

using namespace std;

namespace berndsutil {

  /** @brief Exception class */

  class Fault  {
    public:
      Fault():msg("?"),ident(-1){}
	Fault(string m):msg(m),ident(-1){}
      Fault(string m,int id):msg(m),ident(id){}


    string String() { return msg; }
    int    Ident() { return ident; }

  private:
      string msg;
      int   ident;
  }; 

}

#endif
