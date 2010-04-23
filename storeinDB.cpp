#include <mysql++/mysql++.h>
#include <mysql/mysqld_error.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int maxbytes = 1024 * 1024 * 2 ;   // 2 MB

char bytebuf[maxbytes];

void
storeBlob 
    (mysqlpp::Connection &con,
     string blob_name, 
     int blob_len, 
     char* blob_buf)
{
  int idt = time(NULL);
  stringstream idt_s;
  idt_s << idt;
  cout << idt_s.str() << endl;
  string query_string;
  string blob_data;
  char host[512];
  gethostname(host,500);
  string hostname(host);
  blob_data.assign(blob_buf,blob_len);
  string query_front = string("INSERT INTO satpics ( ident, picname, remark, image ) VALUES ( ")
    + idt_s.str() + " , "
    + "\"" + blob_name + "\", "
    + string("\"") + hostname + string("\", ") ;
  mysqlpp::Query q = con.query();
  q << query_front.c_str() 
    << " \""
    << mysqlpp::escape << blob_data 
    << "\")";
  mysqlpp::SimpleResult res = q.execute();
  cout << "Inserted " << blob_name << "  as "
       << idt_s.str() << "  " 
       << blob_data.size() << " bytes , ID is "
       << res.insert_id() << endl;
  
}

int
main (int argc, char *argv[])
{

  string db("weather");
  string server("localhost");
  string user("weather");
  string pass("quetzalcoatl");
 
  string filename;

  mysqlpp::Connection conn;

 
  conn.connect (db.c_str(), server.c_str(), user.c_str(), pass.c_str());

  cout << "connected to " << db << " on " << server << " as " << user << endl;

  int i; int fsize; int fnbytes;
  ifstream picfile;
  struct stat filestat;


  for (i=1; i<argc; i++) {
    filename = argv[i];
    if (stat(filename.c_str(), &filestat) == 0) {
      fsize = filestat.st_size;
    } else {
      continue;
    }
    if (fsize > maxbytes) {
      cout << "file " << filename << " with " << fsize 
       << " bytes is too big " << endl;
      continue;
    }
    picfile.open(filename.c_str(), ios::in | ios::binary);
    picfile.read(bytebuf, fsize);
    fnbytes = picfile.gcount();
    picfile.close();

    if (fnbytes == fsize) {
      storeBlob (conn, filename, fsize, bytebuf);
    }
 
    
  }  
  conn.disconnect();
}
