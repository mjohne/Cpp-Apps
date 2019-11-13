/******************************************************************************/
/* Description: Windows Textmode Console Functions                            */
/*              look at Microsoft Information (KB Q99261)                     */
/* Compiler NT: MS Visual C++ 6.0, Console App                                */
/* Written by.: F. Mersmann, 23.03.1988              Version 3.20, 12.03.2003 */
/******************************************************************************/
/* Change log.: Gabriel Augustin, 01.06.2001                                  */
/* Change log.: Mark Scholtes, 11.12.2002                                     */
/* Change log.: J. Wolkenhauer, 10.03.2003                                    */
/******************************************************************************/

//#include "stdafx.h"  						// bei MFC-Projekt 'includen'
#include "Console.h"
#include "iostream.h"
#include "assert.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConsole::CConsole()
{
  hCon = GetStdHandle(STD_OUTPUT_HANDLE);
  ios::sync_with_stdio();
  stMaxSize = GetMaxWindowSize();
  nOldtime = -1;
  stSize.X = 80;
  stSize.Y = 25;
  SetWindowSize(stSize);
  bIsWindow = TRUE; // Console hat normale Groesse
}

CConsole::~CConsole()
{
  ScreenMode();
}

COORD CConsole::GetMaxWindowSize()	// ask os for max possible window size
{
    return(GetLargestConsoleWindowSize(hCon));
}

COORD CConsole::GetWindowSize()		// ask actual window size
{
    return(stSize);
}

void CConsole::SetWindowSize(int nXsize, int nYsize)	// set actual window size
{
  COORD stNewSize;
  stNewSize.X = nXsize;
  stNewSize.Y = nYsize;
  SetWindowSize(stNewSize);
}

void CConsole::SetWindowSize(COORD stNewSize)  // set actual window size
{
  assert(stNewSize.X <= stMaxSize.X);
  assert(stNewSize.X <= stMaxSize.X);
  SetConsoleScreenBufferSize(hCon, stNewSize);
  stSize = stNewSize;
}

void CConsole::SetTitle(char * pszStr)
{  // set a console window title
  if(pszStr) SetConsoleTitle(pszStr);
}  // CConsole


void  CConsole::Box(int nX1, int nY1, int nX2, int nY2)
{  // draw simple box from (nX1,nY1) to (nX2,nY2) with a single line
int   nI;

  GotoXY(nX1, nY1);
  cout << char(218);
  for(nI = nX1 + 1; nI < nX2; nI++) cout << char(196);
  cout << char(191);
  for(nI = nY1 + 1; nI < nY2; nI++)
  {
    GotoXY(nX1, nI);    cout << char(179);
    GotoXY(nX2, nI);    cout << char(179);
  }
  GotoXY(nX1, nY2);
  cout << char(192);
  for(nI = nX1 + 1; nI < nX2; nI++) cout << char(196);
  cout << char(217);
  GotoXY(nX1 + 1, nY1 + 1);
  cout.flush();
}  // Box


void  CConsole::ClrBox(int nX1, int nY1, int nX2, int nY2)
{  // Clear Box, leave border, position cursor to {nX1+1, nY1+1}
int   nI = nX1 + 1,
      nJ = nY1 + 1;

  for( ; nJ < nY2; nJ++)
  {
    GotoXY(nI, nJ);
    for( ; nI < nX2; nI++)
        cout << ' ';
    nI = nX1 + 1;
  }
  GotoXY(nX1 + 1, nY1 + 1);
  cout.flush();
}  // ClrBox


void CConsole::ClrScr(int nY1, int nY2)
{  // Clear Screen for any window size, position cursor to {0, nY1}
  coord.X = 0;
  coord.Y = nY1;
  bSuccess = GetConsoleScreenBufferInfo(hCon, &csbi);
  if(! nY2) nY2 = csbi.dwSize.Y;
  nConsize = csbi.dwSize.X * (nY2 - nY1);
  FillConsoleOutputCharacter(hCon, ' ', nConsize, coord, &nConsize);
  bSuccess = SetConsoleCursorPosition(hCon, coord);
}  // ClrScr


void CConsole::ClrEoln()
{ // Clear from cursor to end of line, leave cursor at current position
  bSuccess = GetConsoleScreenBufferInfo(hCon, &csbi);
  nConsize = csbi.dwSize.X - csbi.dwCursorPosition.X;
  coord.X = csbi.dwCursorPosition.X;
  coord.Y = csbi.dwCursorPosition.Y;
  FillConsoleOutputCharacter(hCon, ' ', nConsize, coord, &nConsize);
  bSuccess = SetConsoleCursorPosition(hCon, coord);
}  // ClrEoln


void CConsole::GotoXY(int nX, int nY)
{  // position cursor to {nX, nY}
  bSuccess = GetConsoleScreenBufferInfo(hCon, &csbi);
  coord.X = nX % csbi.dwSize.X;
  coord.Y = nY % csbi.dwSize.Y;
  bSuccess = SetConsoleCursorPosition(hCon, coord);
}  // GotoXY


bool CConsole::Time(int nX, int nY, bool bWait)
{  // postion Clock to {nX, nY}
    int nNewtime;
    time_t   stMyTime;
    tm     * pstToday;
    time(&stMyTime);
    pstToday = localtime(&stMyTime);
    nNewtime = pstToday->tm_sec/10;
    if(nNewtime != nOldtime || nOldtime == (-1))
    {
        GotoXY(nX, nY);
        cout << pstToday->tm_hour << ":";
        if(pstToday->tm_min < 10)cout << '0';
        cout << pstToday->tm_min;
        cout.flush();
        nOldtime = nNewtime;
        return (1);
    }
    if(bWait) Sleep(1000);
    return (0);
} // Time


void CConsole::Date(int nX, int nY)
{  // postion Date to {nX, nY}
    GotoXY(nX, nY);
    time_t   stMyTime;
    tm     * pstToday;								 
    time(&stMyTime);
    pstToday = localtime(&stMyTime);
    if(pstToday->tm_mday < 10)
        cout << '0';
    cout << pstToday->tm_mday << '.';
    if((pstToday->tm_mon+1) < 10)
        cout << '0';
    cout << (pstToday->tm_mon+1) << '.' <<
pstToday->tm_year+1900;
    cout.flush();
} // Date


void CConsole::HLine(int nX1, int nY, int nX2)
{ // draw simple V-Line from (nX1,nY) to (nX2,nY) with a single line (made for Box)
    assert(nX1 >= 0);
    assert(nX2 < stSize.X);
    GotoXY(nX1, nY);
    cout << char(132);
    for(nX1 ; nX1 < (nX2 - 1); nX1++)    cout <<  char(155);
    cout << char(147);
    cout.flush();
}// H-Line


void CConsole::VLine(int nX, int nY1, int nY2)
{ // draw simple H-Line from (nX,nY1) to (nX,nY2) with a single line (made for Box)

    assert(nY1 >= 0);
    assert(nY2 < stSize.Y);
    GotoXY(nX, nY1);
    cout << char(194);
    for(nY1++; nY1 < nY2 ; nY1++)
    {
		GotoXY(nX, nY1);
		cout <<  char(179);
    }
    GotoXY(nX, nY1);
    cout << char(193);
    cout.flush();
}// V-Line


void CConsole::SetX(int nX, int nY)
{
    GotoXY(nX, nY);
    cout << char(197);
    cout.flush();
}

//nachtrag von wolke 10.3.2003
void CConsole::ScreenMode (int nSize)
{//switches between full and normal screen for the console
    if (bIsWindow && nSize == FULLSCREEN || !bIsWindow && nSize == WINDOW)
    {
		  //Emulation of keys ALT + ENTER
		  keybd_event ( VK_MENU , 0x38 , 0 , 0 );//Alt key was pressed
		  keybd_event ( VK_RETURN , 0x1c , 0 , 0 );//Return key was pressed
		  keybd_event ( VK_RETURN , 0x1c , KEYEVENTF_KEYUP , 0 );//Return key was released
		  keybd_event ( VK_MENU , 0x38 , KEYEVENTF_KEYUP , 0 );//Alt key was released
		  if (nSize == FULLSCREEN )
        bIsWindow = FALSE;
		  else
        bIsWindow = TRUE; //stores current screen size
	  }
}


// Nachtrag am 11.12.2002 von M. Scholtes, geaendert 12.03.2003, fme
void CConsole::ClrScrAttribute(int nY1, int nY2)
{  // Clear Screen for any window size, position cursor to {0, nY1}

  ClrScr(nY1, nY2);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
  FillConsoleOutputAttribute(hCon, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, nConsize, coord, &nConsize);
}  // ClrScrAttribute


void CConsole::SetTextAttribute(WORD wAttribute)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttribute);
}
