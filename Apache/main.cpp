#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

const short ReadMaxRows = 100;

string IPAdress;
string Blank1,Blank2,Blank3;
string Date;
string TimeZone;  
string Method,Path,Version,StatusStr,PortStr;

unsigned short MethodGET, MethodPOST, MethodUNKNOWN, Port, Status;

ifstream ApacheLogIFile;
string Row;

int main(int argc, char *argv[])
{

  ApacheLogIFile.open("apache.log",ios::in);
  if (!ApacheLogIFile)
  {
    cerr << "Die Datei \"apache.log\" kann nicht geöffnet werden!" << endl;
  } else {
    while(!ApacheLogIFile.eof())
    {
      ApacheLogIFile >> IPAdress;
      ApacheLogIFile >> Blank1;
      ApacheLogIFile >> Blank2;
      ApacheLogIFile >> Date;
      ApacheLogIFile >> TimeZone;
      ApacheLogIFile >> Method;
      ApacheLogIFile >> Path;
      ApacheLogIFile >> Version;
      ApacheLogIFile >> StatusStr;
      ApacheLogIFile >> PortStr;
    }
    /*
217.225.116.146 - - [26/May/2003:14:05:26 +0200] "GET / HTTP/1.1" 200 1639
217.225.116.146 - - [26/May/2003:14:05:26 +0200] "GET /frames2.php HTTP/1.1" 200 5795
172.16.11.12 - - [26/May/2003:14:06:05 +0200] "GET / HTTP/1.1" 200 1639
172.16.11.12 - - [26/May/2003:14:06:05 +0200] "GET /navleiste.htm HTTP/1.1" 200 10279
    */

  }
  ApacheLogIFile.close();
    
    
  system("PAUSE");
  return EXIT_SUCCESS;
}
