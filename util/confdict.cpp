

//
//  Copyright (C) 2009 - Bernd H Stramm
//

#include "confdict.h"
#include <iostream>
#include <fstream>

namespace berndsutil {
 
void
DictSetDouble (void* pDict, char* n, double d)
{
  ((ConfDict*)pDict)->Set (string(n),d);
  cout << "defined " << n << endl;
}

void
DictSetLLI (void* pDict, char* n, long long int ll)
{
  ((ConfDict*)pDict)->Set (string(n),ll);
  cout << "defined " << n << endl;
}

void
DictSetBool (void* pDict, char* n, int b)
{
  ((ConfDict*)pDict)->Set (string(n),bool(b));
  cout << "defined " << n << endl;
}

void
DictSetString (void* pDict, char* n, char* val)
{
  ((ConfDict*)pDict)->Set (string(n),string(val));
  cout << "defined " << n << endl;
}

ConfDict::ConfDict()
{}

ConfDict::~ConfDict()
{}


void
ConfDict::Dump(ostream & out)
{
  ConfIter it;
  ConfRec  rec;
  for (it = myConf.begin();
       it != myConf.end();
       it++) {
    
    rec = (*it).second;
    out << rec ;
    out << endl;
  }
}

ostream&
operator<< (ostream& out, const ConfDict::TypeTag t)
{
  switch (t) {
  case ConfDict::T_none:
    out << "notype" ;
    break;
  case ConfDict::T_bool:
    out << "bool" ;
    break;
  case ConfDict::T_double:
    out << "double";
    break;
  case ConfDict::T_longlongint:
    out << "int64";
    break;
  case ConfDict::T_string:
    out << "name";
    break;
  default:
    out << "notype";
    break;
  }
  return out;
}

istream&
operator>> (istream& in, ConfDict::TypeTag& t)
{
  string sym;
  in >> sym;
  if (sym == "bool") {
    t = ConfDict::T_bool;
  } else if (sym == "double") {
    t = ConfDict::T_double;
  } else if (sym == "int64") {
    t = ConfDict::T_longlongint;
  } else if (sym == "name") {
    t = ConfDict::T_string;
  } else {
    t = ConfDict::T_none;
  }
  return in;
}


ostream&
operator<< (ostream& out, const ConfDict::ConfRec r)
{
  out << r.key;
  out << " ";
  out << r.tag;
  out << " ( " ;
  switch (r.tag) {
  case (ConfDict::T_bool):
    out << r.val.bVal;
    break;
  case (ConfDict::T_double):
    out << r.val.dVal;
    break;
  case (ConfDict::T_longlongint):
    out << r.val.llVal;
    break;
  case (ConfDict::T_string):
    out << r.strVal;
    break;
  default:
    out << "?";
    break;
  }
  out << " ) " ;
  return out;
}

istream&
operator>> (istream& in, ConfDict::ConfRec& r)
{
  in >> r.key;
  in >> r.tag;
  string sep;
  bool good = false;
  in >> sep;
  cout << sep << " < sep " << endl;
  if (sep == "(") {
    switch (r.tag) {
    case (ConfDict::T_bool):
      in >> r.val.bVal;
      good = true;
      break;
    case (ConfDict::T_double):
      in >> r.val.dVal;
      good = true;
      break;
    case (ConfDict::T_longlongint):
      in >> r.val.llVal;
      good = true;
      break;
    case (ConfDict::T_string):
      in >> r.strVal;
      good = true;
      break;
    default:
      in >> sep;  // eat up a string
      break;
    }
  }
  in >> sep;
  if (sep != ")") {
    good = false;
  }
  if (!good) {
    r.tag = ConfDict::T_none;
    in.ignore();  // skip rest of input until EOF
  }
  return in;
}


bool
ConfDict::Set (const string name,
               const TypeTag tt,
               const ConfValue val)
{
  ConfRec rec;
  rec.tag = tt;
  rec.val = val;
  rec.key = name;
  myConf[name] = rec;
  return true;
  //return myConf.insert(pair<string,ConfRec>(name,rec)).second;
}

bool
ConfDict::Set (const string& name,
               const Coord val)
{
  ConfRec rec;
  rec.tag = T_coord;
  rec.cVal = val;
  rec.val = ConfValue(false);
  rec.key = name;
  myConf[name] = rec;
  return true;
}

bool
ConfDict::Insert (const ConfRec& r)
{
  myConf[r.key] = r;
  return true;
}

bool
ConfDict::Set (const string& name,
               const string& val)
{
  ConfRec rec;
  rec.tag = T_string;
  rec.val = ConfValue(false);
  rec.strVal = val;
  rec.key = name;
  myConf[name] = rec;
  return true;
}

  ConfDict::TypeTag
ConfDict::IsKnown (const string& name)
{
  ConfIter it = myConf.find(name);
  if (it == myConf.end()) {
    return T_none;
  }
  return it->second.tag;
}

ConfDict::ConfRec
ConfDict::FindUntyped (const string& name)
{
  ConfIter it = myConf.find(name);
  if (it == myConf.end()) {
    throw ConfDict::NotFound (name,false,T_none,T_none);
  }
  return (*it).second;
}
  

ConfDict::TypeTag
ConfDict::FindType (const string& name)
{
  ConfRec rec = FindUntyped (name);
  return rec.tag;
}

ConfDict::ConfRec
ConfDict::FindSpecific (const string& name,
                const TypeTag tt)
{
  ConfRec rec = FindUntyped (name);
  if (rec.tag != tt) {
    throw ConfDict::NotFound(name,true,tt,rec.tag);
  }
  return rec;
}

std::string
ConfDict::Find (const string& name)
{
  ConfRec rec = FindUntyped(name);
  if (rec.tag != T_string) {
    throw ConfDict::NotFound(name,true,T_string,rec.tag);
  }
  return rec.strVal;
}

Coord
ConfDict::FindCoord (const string& name)
{ 
  ConfRec rec = FindUntyped(name);
  if (rec.tag != T_coord) {
    throw ConfDict::NotFound(name,true,T_coord,rec.tag);
  }
  return rec.cVal;
}

void
ConfDict::Read (string fname)
{
  filebuf infile;
  infile.open(fname.c_str(),ios::in);
  istream in(&infile);
  ConfRec r;
  bool ok=true;
  while (ok && !in.eof()) {
    in >> r;
    if (r.tag == T_none) {
      break;
    }
    ok = Insert (r);
  }
  infile.close();
}

void
ConfDict::Write (string fname)
{
  filebuf outfile;
  outfile.open(fname.c_str(),ios::out);
  ostream out(&outfile);
  Dump(out);
  outfile.close();
}

}
