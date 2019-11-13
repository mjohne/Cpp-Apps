/******************************************************************************/
/* Description: Windows Textmode Console Functions                            */
/*              look at Microsoft Informationen (KB Q99261)                   */
/* Compiler NT: MS Visual C++ 6.0, Console App                                */
/* Written by.: F. Mersmann, 23.03.1988              Version 3.20, 12.03.2003 */
/******************************************************************************/
/* Change log.: Gabriel Augustin, 01.06.2001                                  */
/* Change log.: Mark Scholtes, 11.12.2002                                     */
/* Change log.: J. Wolkenhauer, 10.03.2003                                    */
/******************************************************************************/
/*
        'normal' screen having 25 rows and 80 columns

          (0,0)                             (79,0)    (X,0,24)
            +----------------------------------+         -
            |                                  |         | V-Line for 'normal' screen
            |                                  |         |
            |                                  |         |
            |                                  |         |
            |                                  |         |
            |                                  |         |
            |                                  |         |
            |                                  |         |
            +----------------------------------+         -
          (0,24)                            (79,24)
           
            H-Line for 'normal' screen
            |----------------------------------| (0,Y,79)      */


#if !defined(AFX_CONSOLE_H__52E2F0BD_A563_41DF_A01E_133B0302B6DF__INCLUDED_)
#define AFX_CONSOLE_H__52E2F0BD_A563_41DF_A01E_133B0302B6DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "windows.h"
#include "time.h"

#define WINDOW     0
#define FULLSCREEN 1

class CConsole
{
private:
  HANDLE                      hCon;			                // console handle
  DWORD                       nConsize;	  	            // window size
  COORD                       coord;		                // cursor position
  CONSOLE_SCREEN_BUFFER_INFO  csbi;
  BOOL                        bSuccess;		              // flag
  int                         nOldtime;		              // Time() handle
  COORD                       stMaxSize;
  COORD                       stSize;		                // struct für die Konsolenfenstergröße
  bool						            bIsWindow;                // screen mode (using whole screen or not)
  


public:
	CConsole();
	virtual ~CConsole();

	COORD GetMaxWindowSize();	                            // ask os for max possible window size
	COORD GetWindowSize();		                            // ask for actual window size
	void  SetWindowSize(COORD stNewSize);					// set actual window size
	void  SetWindowSize(int nXsize = 80, int nYsize = 25);  // set actual window size
	void  SetTitle(char * pszStr = 0);						// set window title string
	void  ClrEoln();										// clear from cursor to eoln
	void  ClrScr(int nY1 = 0, int nY2 = 0);					// clear screen including lines Y1 and Y2
	void  GotoXY(int nX, int nY);							// goto position
	void  Box(int nX1 = 0, int nY1 = 0, int nX2 = 79, int nY2 = 24); // drawing a box
	void  ClrBox(int nX1 = 0, int nY1 = 0, int nX2 = 79, int nY2 = 24);
	bool  Time(int nX = 74, int nY = 24,  bool bWait = false);// output of time
	void  Date(int nX = 69, int nY = 24);					 // output of date
	void  HLine(int nX1 = 0, int nY = 23, int nX2 = 79);	// horizontal line
	void  VLine(int nX = 1, int nY1 = 0, int nY2 = 23);		// vertikal line
	void  SetX(int nX, int nY);

	//nachtrag von wolke 10.03.2003
	void  ScreenMode(int nSize = WINDOW);			  	    // Sets or resets console to full screen mode
															// OPTIONS: FULLSCREEN(1), WINDOW(0)
	//nachtrag am 11.12.2002 von M. Scholtes
	void  ClrScrAttribute(int nY1 = 0, int nY2 = 0);		// clear screen including lines Y1 and Y2
	void  SetTextAttribute(WORD wAttribute);
	// wAttribute = FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED, FOREGROUND_INTENSITY, 
	//              BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED, BACKGROUND_INTENSITY
};

#endif // !defined(AFX_CONSOLE_H__52E2F0BD_A563_41DF_A01E_133B0302B6DF__INCLUDED_)

