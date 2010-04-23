#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define BIGBUFSIZE 1024*1024

int
main (int argc, char *argv[])
{
  if (argc != 3) {
    cerr << " need 2 file names" << endl;
    return 1;
  }
  int longline (BIGBUFSIZE);
  char buf1[BIGBUFSIZE+4];
  char buf2[BIGBUFSIZE+4];
  string in1 (argv[1]);
  string in2 (argv[2]);;
  ifstream if1;
  ifstream if2;
  if1.open (in1.c_str());
  if2.open (in2.c_str());
  while (!if1.eof() && !if1.eof()) {
    if1.getline (buf1, longline);
    if2.getline (buf2, longline);
    cout << buf1 << " " << buf2  << endl;
  }
  if1.close();
  if2.close();
}
