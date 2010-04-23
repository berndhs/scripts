#include "berndsutil.h"
#include <iostream>
#include <string>
#include <stdint.h>
#include <time.h>

int main()
{

   std::string  S ("1234567890");

   time_t ui = berndsutil::fromString<time_t>(S);

   std::cout << ui << std::endl;
   std::cout << ctime (&ui) << std::endl;

   time_t later = ui + 60 * 60 * 24;
   S = berndsutil::toString(ui);
   std::cout << later << "   " << S << std::endl;
   std::cout << ctime(&later) << std::endl;

   for (int i = 1; i<11; i++) {
     later = ui + i* 365 * 24 * 60 * 60;
     S = berndsutil::toString<time_t>(later);
     std::cout << later << "   " << S << std::endl;
     std::cout << ctime(&later) << std::endl;
   }
}
