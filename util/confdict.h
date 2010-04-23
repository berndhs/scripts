#ifndef CONFDICT_H
#define CONFDICT_H

//
//  Copyright (C) 2009 - Bernd H Stramm
//

//#include <config.h>
#include <map>
#include <string>
#include <iostream>

#include "coord.h"


using namespace std;


extern "C" {

#include "confdict_c.h"
}

namespace berndsutil {

/** @ingroup BerndsUtils */

/** @brief For programs that use configuration, this dictionary helps collect the myriad of
 * options, and perhaps longer term state. A CoinfDict maps strings (names) to specific values.
 * The values can be booleans, numbers (int, long int, double) or strings.
 */
/** @note confdict has a C interface, as well as C++.
 **/

class ConfDict {

 public:

  ConfDict();
  ~ConfDict();

  enum TypeTag {  T_none, T_bool, 
                  T_double, T_longlongint,
                  T_coord,
                  T_string };

  class NotFound {
  public :
      string    name;
      bool      foundIt;
      TypeTag   searchType;
      TypeTag   foundType;
      NotFound (string n,bool f,TypeTag st, TypeTag ft) 
	:name(n),foundIt(f),
         searchType(st),foundType(ft){} 
  };

  class NoDictionary {};

  static void CheckNull (ConfDict* p)
    { if (p==0) { throw NoDictionary(); } }


  void Dump (ostream& out);

  void Read (string fname);
  void Write (string fname);

  bool Set (const string& name, const double val)
      {
        return Set(name,T_double,ConfValue(val));
      }
  bool Set (const string& name, const long long int val)
      {
    return Set(name,T_longlongint, ConfValue(val));
      }    
  bool Set (const string& name, const int val)
  {
    return Set(name,T_longlongint, ConfValue(val));
  }

  bool Set (const string& name, const bool val)
  {
        return Set(name,T_bool, ConfValue(val));
  }

  bool Set (const string& name, const string& val);

  bool Set (const string& name, const Coord val);


  TypeTag FindType (const string& name);

  TypeTag IsKnown (const string& name);

  double FindD (const string& name)
      {
        return FindSpecific (name,T_double).val.dVal;
      }

  long long int  FindI (const string& name)
      {
        return FindSpecific (name,T_longlongint).val.llVal;
      }

  bool FindB (const string& name)
      {
        return FindSpecific (name,T_bool).val.bVal;
      }
 
  string FindS (const string& name)
      {
        return Find (name);
      }

  Coord FindC (const string& name)
  {
    return FindCoord (name);
  }
  

  union ConfValue {
    bool           bVal;
    double         dVal;
    long long int  llVal;
  
    ConfValue (){}
    ConfValue (const bool v) { bVal = v; }
    ConfValue (const double v) { dVal = v; }
    ConfValue (const long long int v) { llVal = v; }
    ConfValue (const int v) { llVal = v; }

  };

  struct ConfRec {
    TypeTag     tag;
    ConfValue   val;
    Coord       cVal;
    string      strVal;
    string      key;

    ConfRec ():tag(T_none),val(false),strVal(""){}
    ConfRec (string s):tag(T_string),
                       strVal(s){}
    ConfRec (const bool v):tag(T_bool),
                           val(v){}
    ConfRec (const double v):tag(T_double),
                             val(v){}
    ConfRec (const long long int v):tag(T_longlongint),
                                    val(v){}
    ConfRec (const Coord c):tag(T_coord),cVal(c){}
  };

  bool Insert (const ConfRec& r);
  
  friend ostream& operator<< (ostream& out, const ConfRec r);
  friend istream& operator>> (istream& in, ConfRec& r);

 private: 

  typedef map<string,ConfRec>     ConfList;
  typedef ConfList::iterator        ConfIter;

  bool Set (const string name, 
            const TypeTag tt,
            const ConfValue val);

  ConfRec FindUntyped (const string& name);
  ConfRec FindSpecific (const string& name, 
                const TypeTag tt);
  string Find (const string& name);
  Coord  FindCoord (const string& name);

  ConfList myConf;

};

ostream& operator<< (ostream& out, const ConfDict::TypeTag t);
istream& operator>> (istream& in, ConfDict::TypeTag& t);

}
#endif
