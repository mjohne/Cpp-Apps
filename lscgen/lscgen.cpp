/*
ToDo-Liste:
-----------
  Menü:
  -  Neue Land erstellen
  -  " generieren
  
  
  
  -  Startwerte für X und Y festlegen
  -  Generierung nach
     (a) Anzahl von Zügen
     (b) maximale Höhe
  -  Projektverwaltung
  -  Einstellungen als "Landscape Script *.lgs" speichern
     Bewegungsprofil als "Landscape Route *.lgr" speichern
     Höhenfeld als "Landscape Heightfield *.lgh" speichern
  -  Heightfield exportieren nach PGM, XPM, ...
  -  als Modell exportieren nach VRML, X3D, ...
              
*/
              

#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "console.h"

using namespace std;

CConsole console;

// ä = \x84
// ö = \x94
// ü = \x81

const int
  Black        = 0,
  Blue         = 1,
  Green        = 2,
  Cyan         = 3,
  Red          = 4,
  Magenta      = 5,
  Brown        = 6,
  LightGrey    = 7,
  DarkGrey     = 8,
  LightBlue    = 9,
  LightGreen   = 10,
  LightCyan    = 11,
  LightRed     = 12,
  LightMagenta = 13,
  Yellow       = 14,
  White        = 15;

const long MaxRange = 4096;

long
  a,b,c,i,n,       // interne Zähler
  StartX,StartY,   // Startwerte im Feld
  MaxX,MaxY,       // Größe des Felds
  X,Y,             // aktive zufällige Koordinaten
  Move,            // aktuelle Bewegung
  //Route[][] = {0},
  LandscapeHP[MaxRange][MaxRange] = {0}; // Feld für die Höhenwerte
  
bool
  SavingRouteEnabled = false;

ofstream
  ScriptFile,
  RouteFile,
  HeightfieldFile,
  Exported_PGM_HeightfieldFile,
  Exported_XPM_HeightfieldFile,
  Exported_RAW_HeightfieldFile,
  Exported_WRL_HeightfieldFile;

string
  ScriptName,
  RouteName,
  HeightfieldName,
  Exported_PGM_HeightfieldName,
  Exported_XPM_HeightfieldName,
  Exported_RAW_HeightfieldName,
  Exported_WRL_HeightfieldName;

void Save_Heightfield_LGH()
{
  HeightfieldName = "test.lgh";
  HeightfieldFile.open(HeightfieldName.c_str(),ios::out);
  HeightfieldFile << MaxX << " " << MaxY << "\n";
  n = 1;
  for(X = 1; X <= MaxX; X++)
  {
    for(Y = 1; Y <= MaxY; Y++)
    {
      HeightfieldFile << LandscapeHP[X][Y] << " ";
      n++;
    }
    HeightfieldFile << "\n";
  }
  HeightfieldFile.close(); HeightfieldFile.clear();
}

void Save_Route_LGR()
{
  RouteName = "test.lgr";
  RouteFile.open(RouteName.c_str(),ios::app);
  RouteFile << Move << " ";
  RouteFile.close(); RouteFile.clear();
}

void Export_Heightfield_as_Graphic_PGM()
{
  Exported_PGM_HeightfieldName = "test.pgm";
  Exported_PGM_HeightfieldFile.open(Exported_PGM_HeightfieldName.c_str(),ios::out);
  Exported_PGM_HeightfieldFile << "P2\n#Created by lscgen\n" << MaxX << " "  << MaxY << "\n" << 255 <<"\n";
  n = 1;
  for(X = 1; X <= MaxX; X++)
  {
    for(Y = 1; Y <= MaxY; Y++)
    {
      Exported_PGM_HeightfieldFile << LandscapeHP[X][Y] << " ";
      n++;
    }
  }
  Exported_PGM_HeightfieldFile.close(); Exported_PGM_HeightfieldFile.clear();
}

void Export_Heightfield_as_Graphic_RAW()
{
  Exported_RAW_HeightfieldName = "test.raw";
  Exported_RAW_HeightfieldFile.open(Exported_RAW_HeightfieldName.c_str(),ios::out);
  n = 1;
  for(X = 1; X <= MaxX; X++)
  {
    for(Y = 1; Y <= MaxY; Y++)
    {
      Exported_RAW_HeightfieldFile << char(LandscapeHP[X][Y]);
      n++;
    }
  }
  Exported_RAW_HeightfieldFile.close(); Exported_RAW_HeightfieldFile.clear();
}

void Export_Heightfield_as_Graphic_XPM()
{
  Exported_XPM_HeightfieldName = "test.xpm";
  Exported_XPM_HeightfieldFile.open(Exported_XPM_HeightfieldName.c_str(),ios::out);
  Exported_XPM_HeightfieldFile << "/* Created by lscgen */\n static char *heightmap_xpm[] = {\n/* width height num_colors chars_per_pixel */\n\"" << MaxX << " " << MaxY << " " << 255 << " 2\",\n/* colors */\n";
  Exported_XPM_HeightfieldFile << "\"´` c #000000\",\n";
  Exported_XPM_HeightfieldFile << "\"´. c #010101\",\n";
  Exported_XPM_HeightfieldFile << "\"´# c #020202\",\n";
  Exported_XPM_HeightfieldFile << "\"´a c #030303\",\n";
  Exported_XPM_HeightfieldFile << "\"´b c #040404\",\n";
  Exported_XPM_HeightfieldFile << "\"´c c #050505\",\n";
  Exported_XPM_HeightfieldFile << "\"´d c #060606\",\n";
  Exported_XPM_HeightfieldFile << "\"´e c #070707\",\n";
  Exported_XPM_HeightfieldFile << "\"´f c #080808\",\n";
  Exported_XPM_HeightfieldFile << "\"´g c #090909\",\n";
  Exported_XPM_HeightfieldFile << "\"´h c #0a0a0a\",\n";
  Exported_XPM_HeightfieldFile << "\"´i c #0b0b0b\",\n";
  Exported_XPM_HeightfieldFile << "\"´j c #0c0c0c\",\n";
  Exported_XPM_HeightfieldFile << "\"´k c #0d0d0d\",\n";
  Exported_XPM_HeightfieldFile << "\"´l c #0e0e0e\",\n";
  Exported_XPM_HeightfieldFile << "\"´m c #0f0f0f\",\n";
  Exported_XPM_HeightfieldFile << "\"´n c #101010\",\n";
  Exported_XPM_HeightfieldFile << "\"´o c #111111\",\n";
  Exported_XPM_HeightfieldFile << "\"´p c #121212\",\n";
  Exported_XPM_HeightfieldFile << "\"´q c #131313\",\n";
  Exported_XPM_HeightfieldFile << "\"´r c #141414\",\n";
  Exported_XPM_HeightfieldFile << "\"´s c #151515\",\n";
  Exported_XPM_HeightfieldFile << "\"´t c #161616\",\n";
  Exported_XPM_HeightfieldFile << "\"´u c #171717\",\n";
  Exported_XPM_HeightfieldFile << "\"´v c #181818\",\n";
  Exported_XPM_HeightfieldFile << "\"´w c #191919\",\n";
  Exported_XPM_HeightfieldFile << "\"´x c #1a1a1a\",\n";
  Exported_XPM_HeightfieldFile << "\"´y c #1b1b1b\",\n";
  Exported_XPM_HeightfieldFile << "\"´z c #1c1c1c\",\n";
  Exported_XPM_HeightfieldFile << "\"´A c #1d1d1d\",\n";
  Exported_XPM_HeightfieldFile << "\"´B c #1e1e1e\",\n";
  Exported_XPM_HeightfieldFile << "\"´C c #1f1f1f\",\n";
  Exported_XPM_HeightfieldFile << "\"´D c #202020\",\n";
  Exported_XPM_HeightfieldFile << "\"´E c #212121\",\n";
  Exported_XPM_HeightfieldFile << "\"´F c #222222\",\n";
  Exported_XPM_HeightfieldFile << "\"´G c #232323\",\n";
  Exported_XPM_HeightfieldFile << "\"´H c #242424\",\n";
  Exported_XPM_HeightfieldFile << "\"´I c #252525\",\n";
  Exported_XPM_HeightfieldFile << "\"´J c #262626\",\n";
  Exported_XPM_HeightfieldFile << "\"´K c #272727\",\n";
  Exported_XPM_HeightfieldFile << "\"´L c #282828\",\n";
  Exported_XPM_HeightfieldFile << "\"´M c #292929\",\n";
  Exported_XPM_HeightfieldFile << "\"´N c #2a2a2a\",\n";
  Exported_XPM_HeightfieldFile << "\"´O c #2b2b2b\",\n";
  Exported_XPM_HeightfieldFile << "\"´P c #2c2c2c\",\n";
  Exported_XPM_HeightfieldFile << "\"´Q c #2d2d2d\",\n";
  Exported_XPM_HeightfieldFile << "\"´R c #2e2e2e\",\n";
  Exported_XPM_HeightfieldFile << "\"´S c #2f2f2f\",\n";
  Exported_XPM_HeightfieldFile << "\"´T c #303030\",\n";
  Exported_XPM_HeightfieldFile << "\"´U c #313131\",\n";
  Exported_XPM_HeightfieldFile << "\"´V c #323232\",\n";
  Exported_XPM_HeightfieldFile << "\"´W c #333333\",\n";
  Exported_XPM_HeightfieldFile << "\"´X c #343434\",\n";
  Exported_XPM_HeightfieldFile << "\"´Y c #353535\",\n";
  Exported_XPM_HeightfieldFile << "\"´Z c #363636\",\n";
  Exported_XPM_HeightfieldFile << "\"´0 c #373737\",\n";
  Exported_XPM_HeightfieldFile << "\"´1 c #383838\",\n";
  Exported_XPM_HeightfieldFile << "\"´2 c #393939\",\n";
  Exported_XPM_HeightfieldFile << "\"´3 c #3a3a3a\",\n";
  Exported_XPM_HeightfieldFile << "\"´4 c #3b3b3b\",\n";
  Exported_XPM_HeightfieldFile << "\"´5 c #3c3c3c\",\n";
  Exported_XPM_HeightfieldFile << "\"´6 c #3d3d3d\",\n";
  Exported_XPM_HeightfieldFile << "\"´7 c #3e3e3e\",\n";
  Exported_XPM_HeightfieldFile << "\"´8 c #3f3f3f\",\n";
  Exported_XPM_HeightfieldFile << "\".` c #404040\",\n";
  Exported_XPM_HeightfieldFile << "\".. c #414141\",\n";
  Exported_XPM_HeightfieldFile << "\".# c #424242\",\n";
  Exported_XPM_HeightfieldFile << "\".a c #434343\",\n";
  Exported_XPM_HeightfieldFile << "\".b c #444444\",\n";
  Exported_XPM_HeightfieldFile << "\".c c #454545\",\n";
  Exported_XPM_HeightfieldFile << "\".d c #464646\",\n";
  Exported_XPM_HeightfieldFile << "\".e c #474747\",\n";
  Exported_XPM_HeightfieldFile << "\".f c #484848\",\n";
  Exported_XPM_HeightfieldFile << "\".g c #494949\",\n";
  Exported_XPM_HeightfieldFile << "\".h c #4a4a4a\",\n";
  Exported_XPM_HeightfieldFile << "\".i c #4b4b4b\",\n";
  Exported_XPM_HeightfieldFile << "\".j c #4c4c4c\",\n";
  Exported_XPM_HeightfieldFile << "\".k c #4d4d4d\",\n";
  Exported_XPM_HeightfieldFile << "\".l c #4e4e4e\",\n";
  Exported_XPM_HeightfieldFile << "\".m c #4f4f4f\",\n";
  Exported_XPM_HeightfieldFile << "\".n c #505050\",\n";
  Exported_XPM_HeightfieldFile << "\".o c #515151\",\n";
  Exported_XPM_HeightfieldFile << "\".p c #525252\",\n";
  Exported_XPM_HeightfieldFile << "\".q c #535353\",\n";
  Exported_XPM_HeightfieldFile << "\".r c #545454\",\n";
  Exported_XPM_HeightfieldFile << "\".s c #555555\",\n";
  Exported_XPM_HeightfieldFile << "\".t c #565656\",\n";
  Exported_XPM_HeightfieldFile << "\".u c #575757\",\n";
  Exported_XPM_HeightfieldFile << "\".v c #585858\",\n";
  Exported_XPM_HeightfieldFile << "\".w c #595959\",\n";
  Exported_XPM_HeightfieldFile << "\".x c #5a5a5a\",\n";
  Exported_XPM_HeightfieldFile << "\".y c #5b5b5b\",\n";
  Exported_XPM_HeightfieldFile << "\".z c #5c5c5c\",\n";
  Exported_XPM_HeightfieldFile << "\".A c #5d5d5d\",\n";
  Exported_XPM_HeightfieldFile << "\".B c #5e5e5e\",\n";
  Exported_XPM_HeightfieldFile << "\".C c #5f5f5f\",\n";
  Exported_XPM_HeightfieldFile << "\".D c #606060\",\n";
  Exported_XPM_HeightfieldFile << "\".E c #616161\",\n";
  Exported_XPM_HeightfieldFile << "\".F c #626262\",\n";
  Exported_XPM_HeightfieldFile << "\".G c #636363\",\n";
  Exported_XPM_HeightfieldFile << "\".H c #646464\",\n";
  Exported_XPM_HeightfieldFile << "\".I c #656565\",\n";
  Exported_XPM_HeightfieldFile << "\".J c #666666\",\n";
  Exported_XPM_HeightfieldFile << "\".K c #676767\",\n";
  Exported_XPM_HeightfieldFile << "\".L c #686868\",\n";
  Exported_XPM_HeightfieldFile << "\".M c #696969\",\n";
  Exported_XPM_HeightfieldFile << "\".N c #6a6a6a\",\n";
  Exported_XPM_HeightfieldFile << "\".O c #6b6b6b\",\n";
  Exported_XPM_HeightfieldFile << "\".P c #6c6c6c\",\n";
  Exported_XPM_HeightfieldFile << "\".Q c #6d6d6d\",\n";
  Exported_XPM_HeightfieldFile << "\".R c #6e6e6e\",\n";
  Exported_XPM_HeightfieldFile << "\".S c #6f6f6f\",\n";
  Exported_XPM_HeightfieldFile << "\".T c #707070\",\n";
  Exported_XPM_HeightfieldFile << "\".U c #717171\",\n";
  Exported_XPM_HeightfieldFile << "\".V c #727272\",\n";
  Exported_XPM_HeightfieldFile << "\".W c #737373\",\n";
  Exported_XPM_HeightfieldFile << "\".X c #747474\",\n";
  Exported_XPM_HeightfieldFile << "\".Y c #757575\",\n";
  Exported_XPM_HeightfieldFile << "\".Z c #767676\",\n";
  Exported_XPM_HeightfieldFile << "\".0 c #777777\",\n";
  Exported_XPM_HeightfieldFile << "\".1 c #787878\",\n";
  Exported_XPM_HeightfieldFile << "\".2 c #797979\",\n";
  Exported_XPM_HeightfieldFile << "\".3 c #7a7a7a\",\n";
  Exported_XPM_HeightfieldFile << "\".4 c #7b7b7b\",\n";
  Exported_XPM_HeightfieldFile << "\".5 c #7c7c7c\",\n";
  Exported_XPM_HeightfieldFile << "\".6 c #7d7d7d\",\n";
  Exported_XPM_HeightfieldFile << "\".7 c #7e7e7e\",\n";
  Exported_XPM_HeightfieldFile << "\".8 c #7f7f7f\",\n";
  Exported_XPM_HeightfieldFile << "\"#` c #808080\",\n";
  Exported_XPM_HeightfieldFile << "\"#. c #818181\",\n";
  Exported_XPM_HeightfieldFile << "\"## c #828282\",\n";
  Exported_XPM_HeightfieldFile << "\"#a c #838383\",\n";
  Exported_XPM_HeightfieldFile << "\"#b c #848484\",\n";
  Exported_XPM_HeightfieldFile << "\"#c c #858585\",\n";
  Exported_XPM_HeightfieldFile << "\"#d c #868686\",\n";
  Exported_XPM_HeightfieldFile << "\"#e c #878787\",\n";
  Exported_XPM_HeightfieldFile << "\"#f c #888888\",\n";
  Exported_XPM_HeightfieldFile << "\"#g c #898989\",\n";
  Exported_XPM_HeightfieldFile << "\"#h c #8a8a8a\",\n";
  Exported_XPM_HeightfieldFile << "\"#i c #8b8b8b\",\n";
  Exported_XPM_HeightfieldFile << "\"#j c #8c8c8c\",\n";
  Exported_XPM_HeightfieldFile << "\"#k c #8d8d8d\",\n";
  Exported_XPM_HeightfieldFile << "\"#l c #8e8e8e\",\n";
  Exported_XPM_HeightfieldFile << "\"#m c #8f8f8f\",\n";
  Exported_XPM_HeightfieldFile << "\"#n c #909090\",\n";
  Exported_XPM_HeightfieldFile << "\"#o c #919191\",\n";
  Exported_XPM_HeightfieldFile << "\"#p c #929292\",\n";
  Exported_XPM_HeightfieldFile << "\"#q c #939393\",\n";
  Exported_XPM_HeightfieldFile << "\"#r c #949494\",\n";
  Exported_XPM_HeightfieldFile << "\"#s c #959595\",\n";
  Exported_XPM_HeightfieldFile << "\"#t c #969696\",\n";
  Exported_XPM_HeightfieldFile << "\"#u c #979797\",\n";
  Exported_XPM_HeightfieldFile << "\"#v c #989898\",\n";
  Exported_XPM_HeightfieldFile << "\"#w c #999999\",\n";
  Exported_XPM_HeightfieldFile << "\"#x c #9a9a9a\",\n";
  Exported_XPM_HeightfieldFile << "\"#y c #9b9b9b\",\n";
  Exported_XPM_HeightfieldFile << "\"#z c #9c9c9c\",\n";
  Exported_XPM_HeightfieldFile << "\"#A c #9d9d9d\",\n";
  Exported_XPM_HeightfieldFile << "\"#B c #9e9e9e\",\n";
  Exported_XPM_HeightfieldFile << "\"#C c #9f9f9f\",\n";
  Exported_XPM_HeightfieldFile << "\"#D c #a0a0a0\",\n";
  Exported_XPM_HeightfieldFile << "\"#E c #a1a1a1\",\n";
  Exported_XPM_HeightfieldFile << "\"#F c #a2a2a2\",\n";
  Exported_XPM_HeightfieldFile << "\"#G c #a3a3a3\",\n";
  Exported_XPM_HeightfieldFile << "\"#H c #a4a4a4\",\n";
  Exported_XPM_HeightfieldFile << "\"#I c #a5a5a5\",\n";
  Exported_XPM_HeightfieldFile << "\"#J c #a6a6a6\",\n";
  Exported_XPM_HeightfieldFile << "\"#K c #a7a7a7\",\n";
  Exported_XPM_HeightfieldFile << "\"#L c #a8a8a8\",\n";
  Exported_XPM_HeightfieldFile << "\"#M c #a9a9a9\",\n";
  Exported_XPM_HeightfieldFile << "\"#N c #aaaaaa\",\n";
  Exported_XPM_HeightfieldFile << "\"#O c #ababab\",\n";
  Exported_XPM_HeightfieldFile << "\"#P c #acacac\",\n";
  Exported_XPM_HeightfieldFile << "\"#Q c #adadad\",\n";
  Exported_XPM_HeightfieldFile << "\"#R c #aeaeae\",\n";
  Exported_XPM_HeightfieldFile << "\"#S c #afafaf\",\n";
  Exported_XPM_HeightfieldFile << "\"#T c #b0b0b0\",\n";
  Exported_XPM_HeightfieldFile << "\"#U c #b1b1b1\",\n";
  Exported_XPM_HeightfieldFile << "\"#V c #b2b2b2\",\n";
  Exported_XPM_HeightfieldFile << "\"#W c #b3b3b3\",\n";
  Exported_XPM_HeightfieldFile << "\"#X c #b4b4b4\",\n";
  Exported_XPM_HeightfieldFile << "\"#Y c #b5b5b5\",\n";
  Exported_XPM_HeightfieldFile << "\"#Z c #b6b6b6\",\n";
  Exported_XPM_HeightfieldFile << "\"#0 c #b7b7b7\",\n";
  Exported_XPM_HeightfieldFile << "\"#1 c #b8b8b8\",\n";
  Exported_XPM_HeightfieldFile << "\"#2 c #b9b9b9\",\n";
  Exported_XPM_HeightfieldFile << "\"#3 c #bababa\",\n";
  Exported_XPM_HeightfieldFile << "\"#4 c #bbbbbb\",\n";
  Exported_XPM_HeightfieldFile << "\"#5 c #bcbcbc\",\n";
  Exported_XPM_HeightfieldFile << "\"#6 c #bdbdbd\",\n";
  Exported_XPM_HeightfieldFile << "\"#7 c #bebebe\",\n";
  Exported_XPM_HeightfieldFile << "\"#8 c #bfbfbf\",\n";
  Exported_XPM_HeightfieldFile << "\"a` c #c0c0c0\",\n";
  Exported_XPM_HeightfieldFile << "\"a. c #c1c1c1\",\n";
  Exported_XPM_HeightfieldFile << "\"a# c #c2c2c2\",\n";
  Exported_XPM_HeightfieldFile << "\"aa c #c3c3c3\",\n";
  Exported_XPM_HeightfieldFile << "\"ab c #c4c4c4\",\n";
  Exported_XPM_HeightfieldFile << "\"ac c #c5c5c5\",\n";
  Exported_XPM_HeightfieldFile << "\"ad c #c6c6c6\",\n";
  Exported_XPM_HeightfieldFile << "\"ae c #c7c7c7\",\n";
  Exported_XPM_HeightfieldFile << "\"af c #c8c8c8\",\n";
  Exported_XPM_HeightfieldFile << "\"ag c #c9c9c9\",\n";
  Exported_XPM_HeightfieldFile << "\"ah c #cacaca\",\n";
  Exported_XPM_HeightfieldFile << "\"ai c #cbcbcb\",\n";
  Exported_XPM_HeightfieldFile << "\"aj c #cccccc\",\n";
  Exported_XPM_HeightfieldFile << "\"ak c #cdcdcd\",\n";
  Exported_XPM_HeightfieldFile << "\"al c #cecece\",\n";
  Exported_XPM_HeightfieldFile << "\"am c #cfcfcf\",\n";
  Exported_XPM_HeightfieldFile << "\"an c #d0d0d0\",\n";
  Exported_XPM_HeightfieldFile << "\"ao c #d1d1d1\",\n";
  Exported_XPM_HeightfieldFile << "\"ap c #d2d2d2\",\n";
  Exported_XPM_HeightfieldFile << "\"aq c #d3d3d3\",\n";
  Exported_XPM_HeightfieldFile << "\"ar c #d4d4d4\",\n";
  Exported_XPM_HeightfieldFile << "\"as c #d5d5d5\",\n";
  Exported_XPM_HeightfieldFile << "\"at c #d6d6d6\",\n";
  Exported_XPM_HeightfieldFile << "\"au c #d7d7d7\",\n";
  Exported_XPM_HeightfieldFile << "\"av c #d8d8d8\",\n";
  Exported_XPM_HeightfieldFile << "\"aw c #d9d9d9\",\n";
  Exported_XPM_HeightfieldFile << "\"ax c #dadada\",\n";
  Exported_XPM_HeightfieldFile << "\"ay c #dbdbdb\",\n";
  Exported_XPM_HeightfieldFile << "\"az c #dcdcdc\",\n";
  Exported_XPM_HeightfieldFile << "\"aA c #dddddd\",\n";
  Exported_XPM_HeightfieldFile << "\"aB c #dedede\",\n";
  Exported_XPM_HeightfieldFile << "\"aC c #dfdfdf\",\n";
  Exported_XPM_HeightfieldFile << "\"aD c #e0e0e0\",\n";
  Exported_XPM_HeightfieldFile << "\"aE c #e1e1e1\",\n";
  Exported_XPM_HeightfieldFile << "\"aF c #e2e2e2\",\n";
  Exported_XPM_HeightfieldFile << "\"aG c #e3e3e3\",\n";
  Exported_XPM_HeightfieldFile << "\"aH c #e4e4e4\",\n";
  Exported_XPM_HeightfieldFile << "\"aI c #e5e5e5\",\n";
  Exported_XPM_HeightfieldFile << "\"aJ c #e6e6e6\",\n";
  Exported_XPM_HeightfieldFile << "\"aK c #e7e7e7\",\n";
  Exported_XPM_HeightfieldFile << "\"aL c #e8e8e8\",\n";
  Exported_XPM_HeightfieldFile << "\"aM c #e9e9e9\",\n";
  Exported_XPM_HeightfieldFile << "\"aN c #eaeaea\",\n";
  Exported_XPM_HeightfieldFile << "\"aO c #ebebeb\",\n";
  Exported_XPM_HeightfieldFile << "\"aP c #ececec\",\n";
  Exported_XPM_HeightfieldFile << "\"aQ c #ededed\",\n";
  Exported_XPM_HeightfieldFile << "\"aR c #eeeeee\",\n";
  Exported_XPM_HeightfieldFile << "\"aS c #efefef\",\n";
  Exported_XPM_HeightfieldFile << "\"aT c #f0f0f0\",\n";
  Exported_XPM_HeightfieldFile << "\"aU c #f1f1f1\",\n";
  Exported_XPM_HeightfieldFile << "\"aV c #f2f2f2\",\n";
  Exported_XPM_HeightfieldFile << "\"aW c #f3f3f3\",\n";
  Exported_XPM_HeightfieldFile << "\"aX c #f4f4f4\",\n";
  Exported_XPM_HeightfieldFile << "\"aY c #f5f5f5\",\n";
  Exported_XPM_HeightfieldFile << "\"aZ c #f6f6f6\",\n";
  Exported_XPM_HeightfieldFile << "\"a0 c #f7f7f7\",\n";
  Exported_XPM_HeightfieldFile << "\"a1 c #f8f8f8\",\n";
  Exported_XPM_HeightfieldFile << "\"a2 c #f9f9f9\",\n";
  Exported_XPM_HeightfieldFile << "\"a3 c #fafafa\",\n";
  Exported_XPM_HeightfieldFile << "\"a4 c #fbfbfb\",\n";
  Exported_XPM_HeightfieldFile << "\"a5 c #fcfcfc\",\n";
  Exported_XPM_HeightfieldFile << "\"a6 c #fdfdfd\",\n";
  Exported_XPM_HeightfieldFile << "\"a7 c #fefefe\",\n";
  Exported_XPM_HeightfieldFile << "\"a8 c #ffffff\",\n";
  Exported_XPM_HeightfieldFile << "/* pixels */\n\"";
  n = 1;
  for(X = 1; X <= MaxX; X++)
  {
    for(Y = 1; Y <= MaxY; Y++)
    {
      switch(LandscapeHP[X][Y])
      {
        case 0 : { Exported_XPM_HeightfieldFile << "´`"; break; }
        case 1 : { Exported_XPM_HeightfieldFile << "´."; break; }
        case 2 : { Exported_XPM_HeightfieldFile << "´#"; break; }
        case 3 : { Exported_XPM_HeightfieldFile << "´a"; break; }
        case 4 : { Exported_XPM_HeightfieldFile << "´b"; break; }
        case 5 : { Exported_XPM_HeightfieldFile << "´c"; break; }
        case 6 : { Exported_XPM_HeightfieldFile << "´d"; break; }
        case 7 : { Exported_XPM_HeightfieldFile << "´e"; break; }
        case 8 : { Exported_XPM_HeightfieldFile << "´f"; break; }
        case 9 : { Exported_XPM_HeightfieldFile << "´g"; break; }
        case 10 : { Exported_XPM_HeightfieldFile << "´h"; break; }
        case 11 : { Exported_XPM_HeightfieldFile << "´i"; break; }
        case 12 : { Exported_XPM_HeightfieldFile << "´j"; break; }
        case 13 : { Exported_XPM_HeightfieldFile << "´k"; break; }
        case 14 : { Exported_XPM_HeightfieldFile << "´l"; break; }
        case 15 : { Exported_XPM_HeightfieldFile << "´m"; break; }
        case 16 : { Exported_XPM_HeightfieldFile << "´n"; break; }
        case 17 : { Exported_XPM_HeightfieldFile << "´o"; break; }
        case 18 : { Exported_XPM_HeightfieldFile << "´p"; break; }
        case 19 : { Exported_XPM_HeightfieldFile << "´q"; break; }
        case 20 : { Exported_XPM_HeightfieldFile << "´r"; break; }
        case 21 : { Exported_XPM_HeightfieldFile << "´s"; break; }
        case 22 : { Exported_XPM_HeightfieldFile << "´t"; break; }
        case 23 : { Exported_XPM_HeightfieldFile << "´u"; break; }
        case 24 : { Exported_XPM_HeightfieldFile << "´v"; break; }
        case 25 : { Exported_XPM_HeightfieldFile << "´w"; break; }
        case 26 : { Exported_XPM_HeightfieldFile << "´x"; break; }
        case 27 : { Exported_XPM_HeightfieldFile << "´y"; break; }
        case 28 : { Exported_XPM_HeightfieldFile << "´z"; break; }
        case 29 : { Exported_XPM_HeightfieldFile << "´A"; break; }
        case 30 : { Exported_XPM_HeightfieldFile << "´B"; break; }
        case 31 : { Exported_XPM_HeightfieldFile << "´C"; break; }
        case 32 : { Exported_XPM_HeightfieldFile << "´D"; break; }
        case 33 : { Exported_XPM_HeightfieldFile << "´E"; break; }
        case 34 : { Exported_XPM_HeightfieldFile << "´F"; break; }
        case 35 : { Exported_XPM_HeightfieldFile << "´G"; break; }
        case 36 : { Exported_XPM_HeightfieldFile << "´H"; break; }
        case 37 : { Exported_XPM_HeightfieldFile << "´I"; break; }
        case 38 : { Exported_XPM_HeightfieldFile << "´J"; break; }
        case 39 : { Exported_XPM_HeightfieldFile << "´K"; break; }
        case 40 : { Exported_XPM_HeightfieldFile << "´L"; break; }
        case 41 : { Exported_XPM_HeightfieldFile << "´M"; break; }
        case 42 : { Exported_XPM_HeightfieldFile << "´N"; break; }
        case 43 : { Exported_XPM_HeightfieldFile << "´O"; break; }
        case 44 : { Exported_XPM_HeightfieldFile << "´P"; break; }
        case 45 : { Exported_XPM_HeightfieldFile << "´Q"; break; }
        case 46 : { Exported_XPM_HeightfieldFile << "´R"; break; }
        case 47 : { Exported_XPM_HeightfieldFile << "´S"; break; }
        case 48 : { Exported_XPM_HeightfieldFile << "´T"; break; }
        case 49 : { Exported_XPM_HeightfieldFile << "´U"; break; }
        case 50 : { Exported_XPM_HeightfieldFile << "´V"; break; }
        case 51 : { Exported_XPM_HeightfieldFile << "´W"; break; }
        case 52 : { Exported_XPM_HeightfieldFile << "´X"; break; }
        case 53 : { Exported_XPM_HeightfieldFile << "´Y"; break; }
        case 54 : { Exported_XPM_HeightfieldFile << "´Z"; break; }
        case 55 : { Exported_XPM_HeightfieldFile << "´0"; break; }
        case 56 : { Exported_XPM_HeightfieldFile << "´1"; break; }
        case 57 : { Exported_XPM_HeightfieldFile << "´2"; break; }
        case 58 : { Exported_XPM_HeightfieldFile << "´3"; break; }
        case 59 : { Exported_XPM_HeightfieldFile << "´4"; break; }
        case 60 : { Exported_XPM_HeightfieldFile << "´5"; break; }
        case 61 : { Exported_XPM_HeightfieldFile << "´6"; break; }
        case 62 : { Exported_XPM_HeightfieldFile << "´7"; break; }
        case 63 : { Exported_XPM_HeightfieldFile << "´8"; break; }
        case 64 : { Exported_XPM_HeightfieldFile << ".`"; break; }
        case 65 : { Exported_XPM_HeightfieldFile << ".."; break; }
        case 66 : { Exported_XPM_HeightfieldFile << ".#"; break; }
        case 67 : { Exported_XPM_HeightfieldFile << ".a"; break; }
        case 68 : { Exported_XPM_HeightfieldFile << ".b"; break; }
        case 69 : { Exported_XPM_HeightfieldFile << ".c"; break; }
        case 70 : { Exported_XPM_HeightfieldFile << ".d"; break; }
        case 71 : { Exported_XPM_HeightfieldFile << ".e"; break; }
        case 72 : { Exported_XPM_HeightfieldFile << ".f"; break; }
        case 73 : { Exported_XPM_HeightfieldFile << ".g"; break; }
        case 74 : { Exported_XPM_HeightfieldFile << ".h"; break; }
        case 75 : { Exported_XPM_HeightfieldFile << ".i"; break; }
        case 76 : { Exported_XPM_HeightfieldFile << ".j"; break; }
        case 77 : { Exported_XPM_HeightfieldFile << ".k"; break; }
        case 78 : { Exported_XPM_HeightfieldFile << ".l"; break; }
        case 79 : { Exported_XPM_HeightfieldFile << ".m"; break; }
        case 80 : { Exported_XPM_HeightfieldFile << ".n"; break; }
        case 81 : { Exported_XPM_HeightfieldFile << ".o"; break; }
        case 82 : { Exported_XPM_HeightfieldFile << ".p"; break; }
        case 83 : { Exported_XPM_HeightfieldFile << ".q"; break; }
        case 84 : { Exported_XPM_HeightfieldFile << ".r"; break; }
        case 85 : { Exported_XPM_HeightfieldFile << ".s"; break; }
        case 86 : { Exported_XPM_HeightfieldFile << ".t"; break; }
        case 87 : { Exported_XPM_HeightfieldFile << ".u"; break; }
        case 88 : { Exported_XPM_HeightfieldFile << ".v"; break; }
        case 89 : { Exported_XPM_HeightfieldFile << ".w"; break; }
        case 90 : { Exported_XPM_HeightfieldFile << ".x"; break; }
        case 91 : { Exported_XPM_HeightfieldFile << ".y"; break; }
        case 92 : { Exported_XPM_HeightfieldFile << ".z"; break; }
        case 93 : { Exported_XPM_HeightfieldFile << ".A"; break; }
        case 94 : { Exported_XPM_HeightfieldFile << ".B"; break; }
        case 95 : { Exported_XPM_HeightfieldFile << ".C"; break; }
        case 96 : { Exported_XPM_HeightfieldFile << ".D"; break; }
        case 97 : { Exported_XPM_HeightfieldFile << ".E"; break; }
        case 98 : { Exported_XPM_HeightfieldFile << ".F"; break; }
        case 99 : { Exported_XPM_HeightfieldFile << ".G"; break; }
        case 100 : { Exported_XPM_HeightfieldFile << ".H"; break; }
        case 101 : { Exported_XPM_HeightfieldFile << ".I"; break; }
        case 102 : { Exported_XPM_HeightfieldFile << ".J"; break; }
        case 103 : { Exported_XPM_HeightfieldFile << ".K"; break; }
        case 104 : { Exported_XPM_HeightfieldFile << ".L"; break; }
        case 105 : { Exported_XPM_HeightfieldFile << ".M"; break; }
        case 106 : { Exported_XPM_HeightfieldFile << ".N"; break; }
        case 107 : { Exported_XPM_HeightfieldFile << ".O"; break; }
        case 108 : { Exported_XPM_HeightfieldFile << ".P"; break; }
        case 109 : { Exported_XPM_HeightfieldFile << ".Q"; break; }
        case 110 : { Exported_XPM_HeightfieldFile << ".R"; break; }
        case 111 : { Exported_XPM_HeightfieldFile << ".S"; break; }
        case 112 : { Exported_XPM_HeightfieldFile << ".T"; break; }
        case 113 : { Exported_XPM_HeightfieldFile << ".U"; break; }
        case 114 : { Exported_XPM_HeightfieldFile << ".V"; break; }
        case 115 : { Exported_XPM_HeightfieldFile << ".W"; break; }
        case 116 : { Exported_XPM_HeightfieldFile << ".X"; break; }
        case 117 : { Exported_XPM_HeightfieldFile << ".Y"; break; }
        case 118 : { Exported_XPM_HeightfieldFile << ".Z"; break; }
        case 119 : { Exported_XPM_HeightfieldFile << ".0"; break; }
        case 120 : { Exported_XPM_HeightfieldFile << ".1"; break; }
        case 121 : { Exported_XPM_HeightfieldFile << ".2"; break; }
        case 122 : { Exported_XPM_HeightfieldFile << ".3"; break; }
        case 123 : { Exported_XPM_HeightfieldFile << ".4"; break; }
        case 124 : { Exported_XPM_HeightfieldFile << ".5"; break; }
        case 125 : { Exported_XPM_HeightfieldFile << ".6"; break; }
        case 126 : { Exported_XPM_HeightfieldFile << ".7"; break; }
        case 127 : { Exported_XPM_HeightfieldFile << ".8"; break; }
        case 128 : { Exported_XPM_HeightfieldFile << "#`"; break; }
        case 129 : { Exported_XPM_HeightfieldFile << "#."; break; }
        case 130 : { Exported_XPM_HeightfieldFile << "##"; break; }
        case 131 : { Exported_XPM_HeightfieldFile << "#a"; break; }
        case 132 : { Exported_XPM_HeightfieldFile << "#b"; break; }
        case 133 : { Exported_XPM_HeightfieldFile << "#c"; break; }
        case 134 : { Exported_XPM_HeightfieldFile << "#d"; break; }
        case 135 : { Exported_XPM_HeightfieldFile << "#e"; break; }
        case 136 : { Exported_XPM_HeightfieldFile << "#f"; break; }
        case 137 : { Exported_XPM_HeightfieldFile << "#g"; break; }
        case 138 : { Exported_XPM_HeightfieldFile << "#h"; break; }
        case 139 : { Exported_XPM_HeightfieldFile << "#i"; break; }
        case 140 : { Exported_XPM_HeightfieldFile << "#j"; break; }
        case 141 : { Exported_XPM_HeightfieldFile << "#k"; break; }
        case 142 : { Exported_XPM_HeightfieldFile << "#l"; break; }
        case 143 : { Exported_XPM_HeightfieldFile << "#m"; break; }
        case 144 : { Exported_XPM_HeightfieldFile << "#n"; break; }
        case 145 : { Exported_XPM_HeightfieldFile << "#o"; break; }
        case 146 : { Exported_XPM_HeightfieldFile << "#p"; break; }
        case 147 : { Exported_XPM_HeightfieldFile << "#q"; break; }
        case 148 : { Exported_XPM_HeightfieldFile << "#r"; break; }
        case 149 : { Exported_XPM_HeightfieldFile << "#s"; break; }
        case 150 : { Exported_XPM_HeightfieldFile << "#t"; break; }
        case 151 : { Exported_XPM_HeightfieldFile << "#u"; break; }
        case 152 : { Exported_XPM_HeightfieldFile << "#v"; break; }
        case 153 : { Exported_XPM_HeightfieldFile << "#w"; break; }
        case 154 : { Exported_XPM_HeightfieldFile << "#x"; break; }
        case 155 : { Exported_XPM_HeightfieldFile << "#y"; break; }
        case 156 : { Exported_XPM_HeightfieldFile << "#z"; break; }
        case 157 : { Exported_XPM_HeightfieldFile << "#A"; break; }
        case 158 : { Exported_XPM_HeightfieldFile << "#B"; break; }
        case 159 : { Exported_XPM_HeightfieldFile << "#C"; break; }
        case 160 : { Exported_XPM_HeightfieldFile << "#D"; break; }
        case 161 : { Exported_XPM_HeightfieldFile << "#E"; break; }
        case 162 : { Exported_XPM_HeightfieldFile << "#F"; break; }
        case 163 : { Exported_XPM_HeightfieldFile << "#G"; break; }
        case 164 : { Exported_XPM_HeightfieldFile << "#H"; break; }
        case 165 : { Exported_XPM_HeightfieldFile << "#I"; break; }
        case 166 : { Exported_XPM_HeightfieldFile << "#J"; break; }
        case 167 : { Exported_XPM_HeightfieldFile << "#K"; break; }
        case 168 : { Exported_XPM_HeightfieldFile << "#L"; break; }
        case 169 : { Exported_XPM_HeightfieldFile << "#M"; break; }
        case 170 : { Exported_XPM_HeightfieldFile << "#N"; break; }
        case 171 : { Exported_XPM_HeightfieldFile << "#O"; break; }
        case 172 : { Exported_XPM_HeightfieldFile << "#P"; break; }
        case 173 : { Exported_XPM_HeightfieldFile << "#Q"; break; }
        case 174 : { Exported_XPM_HeightfieldFile << "#R"; break; }
        case 175 : { Exported_XPM_HeightfieldFile << "#S"; break; }
        case 176 : { Exported_XPM_HeightfieldFile << "#T"; break; }
        case 177 : { Exported_XPM_HeightfieldFile << "#U"; break; }
        case 178 : { Exported_XPM_HeightfieldFile << "#V"; break; }
        case 179 : { Exported_XPM_HeightfieldFile << "#W"; break; }
        case 180 : { Exported_XPM_HeightfieldFile << "#X"; break; }
        case 181 : { Exported_XPM_HeightfieldFile << "#Y"; break; }
        case 182 : { Exported_XPM_HeightfieldFile << "#Z"; break; }
        case 183 : { Exported_XPM_HeightfieldFile << "#0"; break; }
        case 184 : { Exported_XPM_HeightfieldFile << "#1"; break; }
        case 185 : { Exported_XPM_HeightfieldFile << "#2"; break; }
        case 186 : { Exported_XPM_HeightfieldFile << "#3"; break; }
        case 187 : { Exported_XPM_HeightfieldFile << "#4"; break; }
        case 188 : { Exported_XPM_HeightfieldFile << "#5"; break; }
        case 189 : { Exported_XPM_HeightfieldFile << "#6"; break; }
        case 190 : { Exported_XPM_HeightfieldFile << "#7"; break; }
        case 191 : { Exported_XPM_HeightfieldFile << "#8"; break; }
        case 192 : { Exported_XPM_HeightfieldFile << "a`"; break; }
        case 193 : { Exported_XPM_HeightfieldFile << "a."; break; }
        case 194 : { Exported_XPM_HeightfieldFile << "a#"; break; }
        case 195 : { Exported_XPM_HeightfieldFile << "aa"; break; }
        case 196 : { Exported_XPM_HeightfieldFile << "ab"; break; }
        case 197 : { Exported_XPM_HeightfieldFile << "ac"; break; }
        case 198 : { Exported_XPM_HeightfieldFile << "ad"; break; }
        case 199 : { Exported_XPM_HeightfieldFile << "ae"; break; }
        case 200 : { Exported_XPM_HeightfieldFile << "af"; break; }
        case 201 : { Exported_XPM_HeightfieldFile << "ag"; break; }
        case 202 : { Exported_XPM_HeightfieldFile << "ah"; break; }
        case 203 : { Exported_XPM_HeightfieldFile << "ai"; break; }
        case 204 : { Exported_XPM_HeightfieldFile << "aj"; break; }
        case 205 : { Exported_XPM_HeightfieldFile << "ak"; break; }
        case 206 : { Exported_XPM_HeightfieldFile << "al"; break; }
        case 207 : { Exported_XPM_HeightfieldFile << "am"; break; }
        case 208 : { Exported_XPM_HeightfieldFile << "an"; break; }
        case 209 : { Exported_XPM_HeightfieldFile << "ao"; break; }
        case 210 : { Exported_XPM_HeightfieldFile << "ap"; break; }
        case 211 : { Exported_XPM_HeightfieldFile << "aq"; break; }
        case 212 : { Exported_XPM_HeightfieldFile << "ar"; break; }
        case 213 : { Exported_XPM_HeightfieldFile << "as"; break; }
        case 214 : { Exported_XPM_HeightfieldFile << "at"; break; }
        case 215 : { Exported_XPM_HeightfieldFile << "au"; break; }
        case 216 : { Exported_XPM_HeightfieldFile << "av"; break; }
        case 217 : { Exported_XPM_HeightfieldFile << "aw"; break; }
        case 218 : { Exported_XPM_HeightfieldFile << "ax"; break; }
        case 219 : { Exported_XPM_HeightfieldFile << "ay"; break; }
        case 220 : { Exported_XPM_HeightfieldFile << "az"; break; }
        case 221 : { Exported_XPM_HeightfieldFile << "aA"; break; }
        case 222 : { Exported_XPM_HeightfieldFile << "aB"; break; }
        case 223 : { Exported_XPM_HeightfieldFile << "aC"; break; }
        case 224 : { Exported_XPM_HeightfieldFile << "aD"; break; }
        case 225 : { Exported_XPM_HeightfieldFile << "aE"; break; }
        case 226 : { Exported_XPM_HeightfieldFile << "aF"; break; }
        case 227 : { Exported_XPM_HeightfieldFile << "aG"; break; }
        case 228 : { Exported_XPM_HeightfieldFile << "aH"; break; }
        case 229 : { Exported_XPM_HeightfieldFile << "aI"; break; }
        case 230 : { Exported_XPM_HeightfieldFile << "aJ"; break; }
        case 231 : { Exported_XPM_HeightfieldFile << "aK"; break; }
        case 232 : { Exported_XPM_HeightfieldFile << "aL"; break; }
        case 233 : { Exported_XPM_HeightfieldFile << "aM"; break; }
        case 234 : { Exported_XPM_HeightfieldFile << "aN"; break; }
        case 235 : { Exported_XPM_HeightfieldFile << "aO"; break; }
        case 236 : { Exported_XPM_HeightfieldFile << "aP"; break; }
        case 237 : { Exported_XPM_HeightfieldFile << "aQ"; break; }
        case 238 : { Exported_XPM_HeightfieldFile << "aR"; break; }
        case 239 : { Exported_XPM_HeightfieldFile << "aS"; break; }
        case 240 : { Exported_XPM_HeightfieldFile << "aT"; break; }
        case 241 : { Exported_XPM_HeightfieldFile << "aU"; break; }
        case 242 : { Exported_XPM_HeightfieldFile << "aV"; break; }
        case 243 : { Exported_XPM_HeightfieldFile << "aW"; break; }
        case 244 : { Exported_XPM_HeightfieldFile << "aX"; break; }
        case 245 : { Exported_XPM_HeightfieldFile << "aY"; break; }
        case 246 : { Exported_XPM_HeightfieldFile << "aZ"; break; }
        case 247 : { Exported_XPM_HeightfieldFile << "a0"; break; }
        case 248 : { Exported_XPM_HeightfieldFile << "a1"; break; }
        case 249 : { Exported_XPM_HeightfieldFile << "a2"; break; }
        case 250 : { Exported_XPM_HeightfieldFile << "a3"; break; }
        case 251 : { Exported_XPM_HeightfieldFile << "a4"; break; }
        case 252 : { Exported_XPM_HeightfieldFile << "a5"; break; }
        case 253 : { Exported_XPM_HeightfieldFile << "a6"; break; }
        case 254 : { Exported_XPM_HeightfieldFile << "a7"; break; }
        case 255 : { Exported_XPM_HeightfieldFile << "a8"; break; }
      }
      if(n == MaxX) {Exported_XPM_HeightfieldFile << "\",\n\""; n = 0;}
      n++;
    }
  }
  Exported_XPM_HeightfieldFile << "\"\n};";
  Exported_XPM_HeightfieldFile.close(); Exported_XPM_HeightfieldFile.clear();
}

void Export_Heightfield_as_Model_WRL()
{

  Exported_WRL_HeightfieldName = "test.wrl";
  Exported_WRL_HeightfieldFile.open(Exported_WRL_HeightfieldName.c_str(),ios::out);  
  Exported_WRL_HeightfieldFile << "#VRML V2.0 utf8\nShape\n{\n  appearance Appearance\n  {\n    material Material { }\n  }\n  geometry ElevationGrid\n  {\n    xDimension " << MaxX << "\n    zDimension " << MaxY << "\n    xSpacing " << MaxY << "\n    zSpacing " << MaxY << "\n    height\n    [\n";
  n = 1;
  for(X = 1; X <= MaxX; X++)
  {
    for(Y = 1; Y <= MaxY; Y++)
    {
      HeightfieldFile << LandscapeHP[X][Y] << " ";
      Exported_PGM_HeightfieldFile << LandscapeHP[X][Y] << " ";
      Exported_RAW_HeightfieldFile << char(LandscapeHP[X][Y]);
      Exported_WRL_HeightfieldFile << LandscapeHP[X][Y] << ", ";
      n++;
    }
    HeightfieldFile << "\n";
  }
  Exported_WRL_HeightfieldFile << "\n    ]\n  }\n}\n";
  Exported_WRL_HeightfieldFile.close(); Exported_WRL_HeightfieldFile.clear();
}

int main()
{
  srand((unsigned)time(NULL));
  console.ClrScr();
  console.Box(0,0,79,23);  // "Fenster"-Kasten
  console.Box(1,1,78,3);   // oberer Kasten
  console.Box(1,4,41,15);  // linker Kasten
  console.Box(42,4,78,15); // rechter Kasten
  console.Box(1,16,78,22); // unterer Kasten
  console.SetTextAttribute(LightCyan);
  console.GotoXY(15,2); cout << "Landscape Generator";
  console.SetTextAttribute(White); cout << " - (c) Michael Johne 2006 v1.0";

  console.SetTextAttribute(LightGrey);
  console.GotoXY(3,05); cout << "[1|N] - Neue Landschaft erstellen";
  console.GotoXY(3,06); cout << "[2|O] - Vorhandene Landschaft laden";
  console.SetTextAttribute(DarkGrey);
  console.GotoXY(3,07); cout << "[3|S] - Aktuelle Landschaft speichern";
  console.GotoXY(3, 9); cout << "[4|B] - Aktuelle Landschaft bearbeiten";
  console.GotoXY(3,10); cout << "[5|M] - Als Modell exportieren";
  console.GotoXY(3,11); cout << "[6|G] - Als Grafik exportieren";
  console.SetTextAttribute(Cyan);
  console.GotoXY(3,38); cout << "[9|H] - Hilfe";
  console.SetTextAttribute(LightRed);
  console.GotoXY(3,39); cout << "[0|X] - Programm beenden";


  
  console.SetTextAttribute(LightGreen);
  console.GotoXY(3,17); cout << "Landscape Generator (= lscgen) ist ein zufallsbasierender, fraktaler Land-";
  console.GotoXY(3,18); cout << "schaftsgenerator. Dieses Programm erstellt ein zweidimensionales Feld, das";
  console.GotoXY(3,19); cout << "ein komplettes H\x94henprofil f\x81r eine definierte Fl\x84" << "che enth\x84lt. Diese Werte";
  console.GotoXY(3,20); cout << "werden zur weiteren Verarbeitung (z. B. visuelle Pr\x84sentation, 3D-Renderer)";
  console.GotoXY(3,21); cout << "in einer Datei abgespeichert oder in andere Formate exportiert.";


  system("pause");
  console.ClrScr();

  MaxX = MaxRange+1;
  while(MaxX > MaxRange)
  {
    cout << "   X-Achse (max. 4096): "; cin >> MaxX;
    if(MaxX > MaxRange) cout << "   X ist leider gr\x94sser als 4096!!!\n";
  }
  MaxY = MaxRange+1;
  while(MaxY > MaxRange)
  {
    cout << "   Y-Achse (max. 4096): "; cin >> MaxY;
    if(MaxY > MaxRange) cout << "   Y ist leider gr\x94sser als 4096!!!\n";
  }
  StartX = -1; StartY = -1;
  while(StartX < 0 || StartX > MaxX)
  {
    cout << "   Startwert für X-Koordinate (max. X-Achse; 0 = Zufall): "; cin >> StartX;
    if(StartX == 0) StartX = (rand() % MaxX)+1;
    if(StartX < 0) cout << "   Startwert ist kleiner als 0!!!\n";
    if(StartX > MaxX) cout << "   Startwert ist gr\x94sser als X-Achse!!!\n";
  }
  while(StartY < 0 || StartY > MaxY)
  {
    cout << "   Startwert für Y-Koordinate (max. Y-Achse; 0 = Zufall): "; cin >> StartY;
    if(StartY == 0) StartY = (rand() % MaxY)+1;
    if(StartY < 0) cout << "   Startwert ist kleiner als 0!!!\n";
    if(StartY > MaxY) cout << "   Startwert ist gr\x94sser als Y-Achse!!!\n";
  }


  /*ScriptName = "test.lgs";
  ScriptFile.open(ScriptName.c_str(),ios::out);
  RouteName = "test.lgr";
  RouteFile.open(RouteName.c_str(),ios::out);*/

  n = 1;
  while(LandscapeHP[X][Y] <= 254)
  {
    Move = rand() % 10;
    switch(Move)
    {
      case 1 : { X--; Y++; break; }
      case 2 : { Y++; break; }
      case 3 : { X++; Y++; break; }
      case 4 : { X--; break; }
      case 6 : { X++; break; }
      case 7 : { X--; Y--; break; }
      case 8 : { Y--; break; }
      case 9 : { X++; Y--; break; }
    }
    if(X < 1) X = X+MaxX;
    if(Y < 1) Y = Y+MaxY;
    if(X > MaxX) X = X-MaxX;
    if(Y > MaxY) Y = Y-MaxY;
    if(Move != 0)
    {
      LandscapeHP[X][Y]++;
      if (SavingRouteEnabled == true) Save_Route_LGR();
    }
    n++;
  }

  Save_Heightfield_LGH();
  Export_Heightfield_as_Graphic_PGM();
  Export_Heightfield_as_Graphic_RAW();
  Export_Heightfield_as_Graphic_XPM();
  Export_Heightfield_as_Model_WRL();


  /*ScriptFile.close(); ScriptFile.clear();
  RouteFile.close(); RouteFile.clear();*/
  

  system("pause");
  return EXIT_SUCCESS;
}
