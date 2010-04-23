#ifndef COUNTER_H
#define COUNTER_H


//
//  Copyright (C) 2009 - Bernd H Stramm
//


#include <map>
#include "fault.h"

namespace berndsutil {

// Counter - a glorified integer
//           with restricted functionality
//           but with initialization
class Counter {

 public:

  Counter(int initval=0)
         :count(initval){}


    int  Incr(int amount=1)
             {count += amount; return count;}
    int  Val() 
             { return count; }
    int  Reset(int newval=0)
             {count=newval; return count;}

 private:
 
    int count;
};


// RangeCounter  - a sparse array of counters
//                 that works for float (double) indices
//                 or any index that defines operator<
//                 (less than)
//                 Useful to make histograms

template <typename T> class RangeCounter {
 public:

  RangeCounter<T>(){}

  int Incr(T index, int amount=1)
  { return count[index].Incr(amount); }

  int Val(T index)
  { 
    CMIterator i = count.find(index);
    if (i == count.end()) {
      return 0; 
    }
    return i->second.Val();
  }

  int Reset(T index, int newval)
  { return count[index].Reset(newval); }

  bool Empty() {
    return count.empty();
  }

  T LowBound() {
    if (count.empty()) {
      throw Fault() ;
    }
    return count.begin()->first;
  }

  T HighBound() {
    if (count.empty()) {
      throw Fault();
    }
    CMIterator last = count.end();
    last--;
    return last->first;
  }

  //
  // Val (low..high) - returns the sum of all counts in the range low..high
  //
  int Val (T low, T high) {
    CMIterator i = count.lower_bound(low);
    if (i==count.end()) {
      return 0;
    }
    CMIterator ihigh = count.upper_bound(high);
    int sum = 0;
    for (;i!= ihigh; i++) {
      sum += i->second.Val();
    }
    return sum;
  }
    


 private:

    typedef map<T,Counter>       CounterMap;
    typedef typename map<T,Counter>::iterator CMIterator;
    
    CounterMap count;
};

} // end of namespace
#endif
