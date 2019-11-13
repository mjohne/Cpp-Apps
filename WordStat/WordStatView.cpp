// WordStatView.cpp : implementation of the CWordStatView class
//

#include "stdafx.h"
#include "WordStat.h"

#include "WordStatDoc.h"
#include "WordStatView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWordStatView

IMPLEMENT_DYNCREATE(CWordStatView, CView)

BEGIN_MESSAGE_MAP(CWordStatView, CView)
	//{{AFX_MSG_MAP(CWordStatView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordStatView construction/destruction

CWordStatView::CWordStatView()
{
	// TODO: add construction code here

}

CWordStatView::~CWordStatView()
{
}

BOOL CWordStatView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWordStatView drawing

void CWordStatView::OnDraw(CDC* pDC)
{
	CWordStatDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
  CRect lRect;
  GetClientRect(lRect);  // Ermitteln der Größe der Zeichenfläche
  lRect.NormalizeRect(); // Wandelt mögliche, negative Angaben der Zeichenfläche ins Positive am
  int nDistance = 120;   // Abstand den Achsen zum Fensterrahmen
  bool bMove = false;
  LONG
    nKValueMin = 1,            // minimaler Wert für den K-Wert
    nKValueMax = 0,            // maximaler Wert für den K-Wert
    nRankMin = 99999,          // minimaler Wert für den Rang
    nRankMax = 0,              // maximaler Wert für den Rang
    nWordFrequencyMin = 99999, // minimaler Wert für die Worthäufigkeit
    nWordFrequencyMax = 0,     // maximaler Wert für die Worthäufigkeit
    nWordLenMin = 255,         // minimaler Wert für die Wortlänge
    nWordLenMax = 0,           // maximaler Wert für die Wortlänge
    nWordLen2Min = 255,        // 2. minimaler Wert für die Wortlänge
    nWordLen2Max = 0,          // 2. maximaler Wert für die Wortlänge
    i,x,x2,y,                  // Zählervariablen und Variablen für Koordianten
    nKValueSpan = 0,           // Differenz zwischen Maximun & Minimum des K-Werts
    nRankSpan = 0,             // Differenz zwischen Maximun & Minimum des Rangs
    nWordFrequencySpan = 0,    // Differenz zwischen Maximun & Minimum der Worthäufigkeit
    nWordLenSpan = 0,          // Differenz zwischen Maximun & Minimum der Wortlänge
    nWordLen2Span = 0;         // 2. Differenz zwischen Maximun & Minimum der Wortlänge
  CString strTemp,strOutput;   // Zeichenkette zu diversen Textausgaben
  CPen *pCOldPen;
  // Pens für verschiedene Farben
  CPen CBlackPen1(PS_SOLID,1,0x000001); // Schwarz
  CPen CBlackPen2(PS_SOLID,2,0x000001); // Schwarz
  CPen CGrayPen(PS_SOLID,1,0xC0C0C0);   // Grün
  CPen CGreenPen(PS_SOLID,1,0x008000);  // Grün
  CPen CRedPen(PS_SOLID,1,0x0000ff);    // Rot
  CPen CGrasPen(PS_SOLID,1,0x00ff00);   // Hellgrün
  CPen CBluePen(PS_SOLID,1,0xff0000);   // Blue
  CPen CYellowPen(PS_SOLID,1,0x00ffff); // Gelb
  CPen CAquaPen(PS_SOLID,1,0xffff00);   // Hellblau
  CPen CWhitePen(PS_SOLID,1,0xffffff);  // Weiß
  // Brushs für verschiedene Farben
  CBrush CBlackBrush(0x000001);  // Black
  CBrush CGrayBrush(0xC0C0C0);   // Black
  CBrush CGreenBrush(0x008000);  // Grün
  CBrush CRedBrush(0x0000ff);    // Rot
  CBrush CGrasBrush(0x00ff00);   // Hellgrün
  CBrush CBlueBrush(0xff0000);   // Blue
  CBrush CYellowBrush(0x00ffff); // Gelb
  CBrush CAquaBrush(0xffff00);   // Hellblau
  CBrush CWhiteBrush(0xffffff);  // Weiß

  LONG WordFrequency[65535], KValue[65535], WordLen[255], WordLen2[255];

  pDC->SetTextColor(0x000000);
  pDC->SetBkMode(TRANSPARENT);
  CFont CArialFont_MainTitle, CArialFont_SubTitle, CArialFont_SubTitle2, CArialFont_AxisDescription;
  LOGFONT strMyFont;  
  memset(&strMyFont,0,sizeof(strMyFont)); // LOGFONT-Struktur zuerst mit Default vorbelegen

  switch(pDoc->ProcessState)
  {
    case 1 :
    {
      pDC->TextOut(10,10,"Lese Eingabedatei..."); break;
    }
    case 2 :
    {
      pDC->TextOut(10,10,"Lese Eingabedatei...");
      pDC->TextOut(10,30,"Sortiere Worttabelle nach Worthäufigkeit absteigend..."); break;
    }
    case 7 :
    {
      pDC->TextOut(10,10,"Lese Eingabedatei...");
      pDC->TextOut(10,30,"Sortiere Worttabelle nach Worthäufigkeit absteigend...");
      pDC->TextOut(10,50,"Erstelle Worthäufigkeit - Tabelle..."); break;
    }
    case 8 :
    {
      pDC->TextOut(10,10,"Lese Eingabedatei...");
      pDC->TextOut(10,30,"Sortiere Worttabelle nach Worthäufigkeit absteigend...");
      pDC->TextOut(10,50,"Erstelle Worthäufigkeit - Tabelle...");
      pDC->TextOut(10,70,"Erstelle K-Werte..."); break;
    }
    case 9 :
    {
      pDC->TextOut(10,10,"Lese Eingabedatei...");
      pDC->TextOut(10,30,"Sortiere Worttabelle nach Worthäufigkeit absteigend...");
      pDC->TextOut(10,50,"Erstelle Worthäufigkeit - Tabelle...");
      pDC->TextOut(10,70,"Erstelle K-Werte...");
      pDC->TextOut(10,90,"Erstelle Wortlängen - Tabelle..."); break;
    }
    case 10 :
    {
      pDC->TextOut(10,10,"Lese Eingabedatei...");
      pDC->TextOut(10,30,"Sortiere nach Worthäufigkeit absteigend...");
      pDC->TextOut(10,50,"Erstelle Worthäufigkeit - Tabelle...");
      pDC->TextOut(10,70,"Erstelle K-Werte...");
      pDC->TextOut(10,90,"Erstelle Wortlängen - Tabelle...");
      CString strTemp;
      strTemp.Format(" %.d",pDoc->Letters);
      pDC->TextOut(10,150,"Buchstaben: "+strTemp);
      strTemp.Format(" %.d",pDoc->Spaces);
      pDC->TextOut(10,170,"Leerzeichen: "+strTemp);
      strTemp.Format(" %.d",pDoc->Words);
      pDC->TextOut(10,190,"Wörter: "+strTemp);
      break;
    }
    case 20 :
    {
      // "Platzhalter" für Ausgaben und Anzeigen bei der Speicherung von Dateien
      break;
    }
    case 110 :
    {
      for(i = 0; i < (sizeof pDoc->WordLen / sizeof pDoc->WordLen[0]); i++) { WordLen[i] = pDoc->WordLen[i]; }
      for(i = 0; i < (sizeof WordLen2 / sizeof WordLen2[0]); i++) { WordLen2[i] = 0; }
      for(i = 0; i < (sizeof pDoc->WordFrequency / sizeof pDoc->WordFrequency[0]); i++) { WordFrequency[i] = pDoc->WordFrequency[i]; }
      for(i = 0; i < pDoc->m_WordTable.GetSize(); i++)
      {
        if (WordLen[i] >= nWordLenMax) {nWordLenMax = WordLen[i];}
        if (WordLen[i] <= nWordLenMin) {nWordLenMin = WordLen[i];}
      }
      for(i = 0; i < pDoc->m_WordTable.GetSize(); i++)
      {
        WordLen2[WordLen[i]] += WordFrequency[i];
      }
      nWordLenMax = pDoc->m_uintLimitX;
      // Maximalwerte ermitteln
      for(i = 0; i < (sizeof WordLen2 / sizeof WordLen2[0]); i++)
      {
        if (WordLen2[i] >= nWordLen2Max) {nWordLen2Max = WordLen2[i];}
        if (WordLen2[i] <= nWordLen2Min) {nWordLen2Min = WordLen2[i];}
      }
      // Betrag aus Minimum & Maximum errechnen
      nWordLenSpan = nWordLenMax-nWordLenMin+1;
      nWordLen2Span = nWordLen2Max-nWordLen2Min+1;
      if ((nWordLenMax > nWordLenMin) && (nWordLen2Max > nWordLen2Min))
      {
        pDC->SelectObject(&CGrayBrush);
        pDC->Rectangle(nDistance/2,nDistance/2,lRect.Width()-(nDistance/2),lRect.Height()-(nDistance/2));
        pDC->SelectObject(&CBlackPen2);
        pDC->MoveTo(nDistance/2,nDistance/2);
        pDC->LineTo(nDistance/2,lRect.Height()-(nDistance/2)); // Y-Achse zeichnen
        pDC->LineTo(lRect.Width()-(nDistance/2),lRect.Height()-(nDistance/2)); // X-Achse zeichnen
        //Achsenbeschriftung
        pDC->SetTextAlign(TA_CENTER);
        CArialFont_MainTitle.CreatePointFont(240,"Arial");
        pDC->SelectObject(&CArialFont_MainTitle);
        pDC->TextOut(lRect.Width()/2,0,"Anzahl der Wortlänge");
        CArialFont_SubTitle.CreatePointFont(120,"Arial");
        pDC->SelectObject(&CArialFont_SubTitle);
        strOutput = "Wortlänge ";
        strTemp.Format("%d",nWordLenMin); strOutput += strTemp;
        strOutput += "...";
        strTemp.Format("%d",nWordLenMax); strOutput += strTemp;
        pDC->TextOut(lRect.Width()/2,lRect.Height()-nDistance/4,strOutput);
        strMyFont.lfHeight = 20;
        strMyFont.lfEscapement = 900;
        strcpy(strMyFont.lfFaceName,"Arial");
        CArialFont_SubTitle2.CreateFontIndirect(&strMyFont);
        pDC->SelectObject(&CArialFont_SubTitle2);
        strOutput = "Anzahl der Wortlänge ";
        strTemp.Format("%d",nWordLen2Min); strOutput += strTemp;
        strOutput += "...";
        strTemp.Format("%d",nWordLen2Max); strOutput += strTemp;
        pDC->TextOut(0,lRect.Height()/2,strOutput);
        // Maßeinteilung der Achsen beschriften
        pDC->SelectObject(&CBlackPen1);
        CArialFont_AxisDescription.CreatePointFont(100,"Arial");        
        int m;
        if(nWordLen2Max <= 9) { m = 1; } else m = nWordLen2Max/10;
        for(i = 1; i < nWordLen2Max; i++)
        {
          if(i % m == 0)
          {
            pDC->SelectObject(&CArialFont_AxisDescription);
            strOutput.Format("%d",i);
            y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(i-nWordLen2Min))/nWordLen2Span)+(nDistance/2);
            pDC->TextOut(nDistance/2-20,y-7,strOutput);
            pDC->MoveTo((nDistance/2)-7,y);
            pDC->LineTo(lRect.Width()-(nDistance/2),y);
          }
        }
        if(nWordLenMax <= 9) { m = 1; } else m = nWordLenMax/10;
        for(i = 1; i < nWordLenMax+1; i++)
        {
          if(i % m == 0)
          {
            pDC->SelectObject(&CArialFont_AxisDescription);
            strOutput.Format("%d",i);
            x = ((lRect.Width()-nDistance)*(i-(nWordLenMin-0.75*(nWordLenMin/1.5)))/nWordLenSpan)+(nDistance/2);
            y = lRect.Height()-nDistance/2-20;
            pDC->TextOut(x,y+30,strOutput);
            pDC->MoveTo(x,y+20);
            pDC->LineTo(x,y+30);
          }
        }
        // Graph zeichnen
        pCOldPen = pDC->SelectObject(&CBlackPen1);
        pDC->SelectObject(&CBlueBrush);
        for(i = 1; i < nWordLenMax+1; i++)
        {
          x = ((lRect.Width()-nDistance)*(i-nWordLenMin))/(nWordLenSpan)+(nDistance/2);
          x2 = ((lRect.Width()-nDistance)*((i+1)-nWordLenMin))/(nWordLenSpan)+(nDistance/2);
          y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(WordLen2[i]-nWordLen2Min))/nWordLen2Span)+(nDistance/2);
          pDC->Rectangle(x,y,x2,lRect.Height()-(nDistance/2));
        }
        pDC->SelectObject(pCOldPen);

      }
      break;
    }
    case 120 :
    {
      for(i = 0; i < (sizeof pDoc->WordFrequency / sizeof pDoc->WordFrequency[0]); i++) { WordFrequency[i] = pDoc->WordFrequency[i]; }
      // Maximalwerte ermitteln
      for(i = 0; i < pDoc->m_WordTable.GetSize(); i++)
      {
        if (WordFrequency[i] >= nWordFrequencyMax) {nWordFrequencyMax = WordFrequency[i];}
        if (WordFrequency[i] <= nWordFrequencyMin) {nWordFrequencyMin = WordFrequency[i];}
      }
      nRankMin = 1;
      nRankMax = pDoc->m_uintLimitX;
      // Betrag aus Minimum & Maximum errechnen
      nRankSpan = nRankMax - nRankMin;
      nWordFrequencySpan = nWordFrequencyMax - nWordFrequencyMin;
      if ((nWordFrequencyMax > nWordFrequencyMin) && (nRankMax > nRankMin))
      {
        pDC->SelectObject(&CGrayBrush);
        pDC->Rectangle(nDistance/2,nDistance/2,lRect.Width()-(nDistance/2),lRect.Height()-(nDistance/2));
        pDC->SelectObject(&CBlackPen2);
        pDC->MoveTo(nDistance/2,nDistance/2);
        pDC->LineTo(nDistance/2,lRect.Height()-(nDistance/2)); // Y-Achse zeichnen
        pDC->LineTo(lRect.Width()-(nDistance/2),lRect.Height()-(nDistance/2)); // X-Achse zeichnen
        // Achsenbeschriftung
        pDC->SetTextAlign(TA_CENTER);
        CArialFont_MainTitle.CreatePointFont(240,"Arial");
        pDC->SelectObject(&CArialFont_MainTitle);
        pDC->TextOut(lRect.Width()/2,0,"Absteigende Worthäufigkeit");
        CArialFont_SubTitle.CreatePointFont(120,"Arial");
        pDC->SelectObject(&CArialFont_SubTitle);
        strOutput = "Rang ";
        strTemp.Format("%d",nRankMin); strOutput += strTemp;
        strOutput += "...";
        strTemp.Format("%d",nRankMax); strOutput += strTemp;
        pDC->TextOut(lRect.Width()/2,lRect.Height()-nDistance/4,strOutput);
        strMyFont.lfHeight = 20;
        strMyFont.lfEscapement = 900;
        strcpy(strMyFont.lfFaceName,"Arial");
        CArialFont_SubTitle2.CreateFontIndirect(&strMyFont);
        pDC->SelectObject(&CArialFont_SubTitle2);
        strOutput = "Worthäufigkeit ";
        strTemp.Format("%d",nWordFrequencyMin); strOutput += strTemp;
        strOutput += "...";
        strTemp.Format("%d",nWordFrequencyMax); strOutput += strTemp;
        pDC->TextOut(0,lRect.Height()/2,strOutput);
        // Maßeinteilung der Achsen beschriften
        pDC->SelectObject(&CBlackPen1);
        CArialFont_AxisDescription.CreatePointFont(100,"Arial");        
        int m;
        if(nWordFrequencyMax <= 9) { m = 1; } else m = nWordFrequencyMax/10;
        for(i = 1; i < nWordFrequencyMax; i++)
        {
          if(i % m == 0)
          {
            pDC->SelectObject(&CArialFont_AxisDescription);
            strOutput.Format("%d",i);
            y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(i-nWordFrequencyMin))/nWordFrequencySpan)+(nDistance/2);
            pDC->TextOut(nDistance/2-20,y-7,strOutput);
            pDC->MoveTo(nDistance/2-7,y);
            pDC->LineTo(lRect.Width()-(nDistance/2),y);
          }
        }
        if(nRankMax <= 9) { m = 1; } else m = nRankMax/10;
        for(i = 1; i < nRankMax; i++)
        {
          if(i % m == 0)
          {
            pDC->SelectObject(&CArialFont_AxisDescription);
            strOutput.Format("%d",i);
            x = ((lRect.Width()-nDistance)*(i-nRankMin)/nRankSpan)+(nDistance/2);
            y = lRect.Height()-nDistance/2-20;
            pDC->TextOut(x,y+30,strOutput);
            pDC->MoveTo(x,y+20);
            pDC->LineTo(x,y+30);
          }
        }
        // Graph zeichnen
        pCOldPen = pDC->SelectObject(&CBluePen);
        bMove = false;
        for(i = 0; i < nRankMax; i++)
        {
          if(!bMove) // nur bei Beginn des Linienzeichnens hier reinspringen
          {
            x = ((lRect.Width()-nDistance)*((i+1)-nRankMin))/nRankSpan+(nDistance/2);
            y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(WordFrequency[i]-nWordFrequencyMin))/nWordFrequencySpan)+(nDistance/2);
            pDC->MoveTo(x,y);
            bMove = true;
          }
          x = ((lRect.Width()-nDistance)*((i+1)-nRankMin))/nRankSpan+(nDistance/2);
          y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(WordFrequency[i]-nWordFrequencyMin))/nWordFrequencySpan)+(nDistance/2);
          pDC->LineTo(x,y);
        }
        pDC->SelectObject(pCOldPen);
      }
      break;
    }
    case 130 :
    {
      for(i = 0; i < (sizeof pDoc->WordLen / sizeof pDoc->WordLen[0]); i++) { WordLen[i] = pDoc->WordLen[i]; }
      for(i = 0; i < (sizeof pDoc->WordFrequency / sizeof pDoc->WordFrequency[0]); i++) { WordFrequency[i] = pDoc->WordFrequency[i]; }
      // Maximalwerte ermitteln
      for(i = 0; i < pDoc->m_WordTable.GetSize(); i++)
      {
        if (WordLen[i] >= nWordLenMax) {nWordLenMax = WordLen[i];}
        if (WordLen[i] <= nWordLenMin) {nWordLenMin = WordLen[i];}
        if (WordFrequency[i] >= nWordFrequencyMax) {nWordFrequencyMax = WordFrequency[i];}
        if (WordFrequency[i] <= nWordFrequencyMin) {nWordFrequencyMin = WordFrequency[i];}
      }
      nWordLenMax = pDoc->m_uintLimitX;
      // Betrag aus Minimum & Maximum errechnen
      nWordLenSpan = nWordLenMax - nWordLenMin;
      nWordFrequencySpan = nWordFrequencyMax - nWordFrequencyMin;
      if ((nWordLenMax > nWordLenMin) && (nWordFrequencyMax > nWordFrequencyMin))
      {
        pDC->SelectObject(&CGrayBrush);
        pDC->Rectangle(nDistance/2,nDistance/2,lRect.Width()-(nDistance/2),lRect.Height()-(nDistance/2));
        pDC->SelectObject(&CBlackPen2);
        pDC->MoveTo(nDistance/2,nDistance/2);
        pDC->LineTo(nDistance/2,lRect.Height()-(nDistance/2)); // Y-Achse zeichnen
        pDC->LineTo(lRect.Width()-(nDistance/2),lRect.Height()-(nDistance/2)); // X-Achse zeichnen
        // Achsenbeschriftung
        pDC->SetTextAlign(TA_CENTER);
        CArialFont_MainTitle.CreatePointFont(240,"Arial");
        pDC->SelectObject(&CArialFont_MainTitle);
        pDC->TextOut(lRect.Width()/2,0,"Relation zwischen Wortlänge und Worthäufigkeit");
        CArialFont_SubTitle.CreatePointFont(120,"Arial");
        pDC->SelectObject(&CArialFont_SubTitle);
        strOutput = "Wortlänge ";
        strTemp.Format("%d",nWordLenMin); strOutput += strTemp;
        strOutput += "...";
        strTemp.Format("%d",nWordLenMax); strOutput += strTemp;
        pDC->TextOut(lRect.Width()/2,lRect.Height()-nDistance/4,strOutput);
        strMyFont.lfHeight = 20;
        strMyFont.lfEscapement = 900;
        strcpy(strMyFont.lfFaceName,"Arial");
        CArialFont_SubTitle2.CreateFontIndirect(&strMyFont);
        pDC->SelectObject(&CArialFont_SubTitle2);
        strOutput = "Worthäufigkeit ";
        strTemp.Format("%d",nWordFrequencyMin); strOutput += strTemp;
        strOutput += "...";
        strTemp.Format("%d",nWordFrequencyMax); strOutput += strTemp;
        pDC->TextOut(0,lRect.Height()/2,strOutput);
        // Maßeinteilung der Achsen beschriften
        pDC->SelectObject(&CBlackPen1);
        CArialFont_AxisDescription.CreatePointFont(100,"Arial");        
        int m;
        if(nWordFrequencyMax >= 30)
        {
          if(nWordFrequencyMax <= 1000) { m = 50; } else { m = 500; }
        }
        for(i = 1; i < nWordFrequencyMax; i++)
        {
          if(nWordFrequencyMax <= 30) m = i;
          if(i % m == 0)
          {
            pDC->SelectObject(&CArialFont_AxisDescription);
            strOutput.Format("%d",i);
            y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(i-nWordFrequencyMin))/nWordFrequencySpan)+(nDistance/2);
            pDC->TextOut(nDistance/2-20,y-7,strOutput);
            pDC->MoveTo(nDistance/2-7,y);
            pDC->LineTo(lRect.Width()-(nDistance/2),y);
          }
        }
        if(nWordLenMax <= 9) { m = 1; } else m = nWordLenMax/10;
        for(i = 1; i < nWordLenMax; i++)
        {
          if(i % m == 0)
          {
            pDC->SelectObject(&CArialFont_AxisDescription);
            strOutput.Format("%d",i);
            x = ((lRect.Width()-nDistance)*(i-nWordLenMin)/nWordLenSpan)+(nDistance/2);
            y = lRect.Height()-nDistance/2-20;
            pDC->TextOut(x,y+30,strOutput);
            pDC->MoveTo(x,y+20);
            pDC->LineTo(x,y+30);
          }
        }
        // Graph zeichnen
        pCOldPen = pDC->SelectObject(&CBlackPen1);
        int nRadius = ((lRect.Width()*lRect.Height())/100000)*2;
        nRadius += 2;
        for(i = 0; i < pDoc->m_WordTable.GetSize(); i++)
        {
          if(WordLen[i] <= nWordLenMax)
          {
            x = ((lRect.Width()-nDistance)*(WordLen[i]-nWordLenMin))/nWordLenSpan+(nDistance/2);
            y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(WordFrequency[i]-nWordFrequencyMin))/nWordFrequencySpan)+(nDistance/2);
            pDC->SelectObject(&CBlueBrush);
            pDC->Ellipse(x-nRadius,y-nRadius,x+nRadius,y+nRadius);
          }
        }
        pDC->SelectObject(pCOldPen);
      }
      break;
    }
    case 140 :
    {
      for(i = 0; i < (sizeof pDoc->KValue / sizeof pDoc->KValue[0]); i++) { KValue[i] = pDoc->KValue[i]; }
      // Maximalwerte ermitteln
      for(i = 0; i < pDoc->m_WordTable.GetSize(); i++)
      {
        if(KValue[i] >= nKValueMax) {nKValueMax = KValue[i];}
      }
      nRankMin = 1;
      nRankMax = pDoc->m_uintLimitX;
      // Betrag aus Minimum & Maximum errechnen
      nRankSpan = nRankMax - nRankMin;
      nKValueSpan = nKValueMax - nKValueMin;
      if((nKValueMax > nKValueMin) && (nRankMax > nRankMin))
      {
        pDC->SelectObject(&CGrayBrush);
        pDC->Rectangle(nDistance/2,nDistance/2,lRect.Width()-(nDistance/2),lRect.Height()-(nDistance/2));
        pDC->SelectObject(&CBlackPen2);
        pDC->MoveTo(nDistance/2,nDistance/2);
        pDC->LineTo(nDistance/2,lRect.Height()-(nDistance/2));     // Y-Achse zeichnen
        pDC->LineTo(lRect.Width()-(nDistance/2),lRect.Height()-(nDistance/2)); // X-Achse zeichnen
        // Achsenbeschriftung
        pDC->SetTextAlign(TA_CENTER);
        CArialFont_MainTitle.CreatePointFont(240,"Arial");
        pDC->SelectObject(&CArialFont_MainTitle);
        pDC->TextOut(lRect.Width()/2,0,"K-Wert - Diagramm");
        CArialFont_SubTitle.CreatePointFont(120,"Arial");
        pDC->SelectObject(&CArialFont_SubTitle);
        strOutput = "Rang ";
        strTemp.Format("%d",nRankMin); strOutput += strTemp;
        strOutput += "...";
        strTemp.Format("%d",nRankMax); strOutput += strTemp;
        pDC->TextOut(lRect.Width()/2,lRect.Height()-nDistance/4,strOutput);
        strMyFont.lfHeight = 20;
        strMyFont.lfEscapement = 900;
        strcpy(strMyFont.lfFaceName,"Arial");
        CArialFont_SubTitle2.CreateFontIndirect(&strMyFont);
        pDC->SelectObject(&CArialFont_SubTitle2);
        strOutput = "K-Wert ";
        strTemp.Format("%d",nKValueMin); strOutput += strTemp;
        strOutput += "...";
        strTemp.Format("%d",nKValueMax); strOutput += strTemp;
        pDC->TextOut(0,lRect.Height()/2,strOutput);
        // Maßeinteilung der Achsen beschriften
        pDC->SelectObject(&CBlackPen1);
        CArialFont_AxisDescription.CreatePointFont(100,"Arial");        
        int m;
        if(nKValueMax <= 9) { m = 1; } else m = nKValueMax/10;
        for(i = 1; i < nKValueMax; i++)
        {
          if(nKValueMax <= 30) m = i;
          if(i % m == 0)
          {
            pDC->SelectObject(&CArialFont_AxisDescription);
            strOutput.Format("%d",i);
            y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(i-nKValueMin))/nKValueSpan)+(nDistance/2);
            pDC->TextOut(nDistance/2-20,y-7,strOutput);
            pDC->MoveTo(nDistance/2-7,y);
            pDC->LineTo(lRect.Width()-(nDistance/2),y);
          }
        }
        if(nRankMax <= 9) { m = 1; } else m = nRankMax/10;
        for(i = 1; i < nRankMax; i++)
        {
          if(i % m == 0)
          {
            pDC->SelectObject(&CArialFont_AxisDescription);
            strOutput.Format("%d",i);
            x = ((lRect.Width()-nDistance)*(i-nRankMin)/nRankSpan)+(nDistance/2);
            y = lRect.Height()-nDistance/2-20;
            pDC->TextOut(x,y+30,strOutput);
            pDC->MoveTo(x,y+20);
            pDC->LineTo(x,y+30);
          }
        }
        // Graph zeichnen
        pCOldPen = pDC->SelectObject(&CBluePen);
        bMove = false;
        for(i = 0; i < nRankMax; i++)
        {
          if(!bMove) // nur bei Beginn des Linienzeichnens hier reinspringen
          {
            x = ((lRect.Width()-nDistance)*((i+1)-nRankMin))/nRankSpan+(nDistance/2);
            y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(KValue[i]-nKValueMin))/nKValueSpan)+(nDistance/2);
            pDC->MoveTo(x,y);
            bMove = true;
          }
          x = ((lRect.Width()-nDistance)*((i+1)-nRankMin))/nRankSpan+(nDistance/2);
          y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(KValue[i]-nKValueMin))/nKValueSpan)+(nDistance/2);
          pDC->LineTo(x,y);
        }
        pDC->SelectObject(pCOldPen);
      }
      break;
    }
    case 150 :
    {
      for(i = 0; i < (sizeof pDoc->WordLen / sizeof pDoc->WordLen[0]); i++) { WordLen[i] = pDoc->WordLen[i]; }
      // Maximalwerte ermitteln
      for(i = 0; i < pDoc->m_WordTable.GetSize(); i++)
      {
        if(WordLen[i] >= nWordLenMax) {nWordLenMax = WordLen[i];}
        if(WordLen[i] <= nWordLenMin) {nWordLenMin = WordLen[i];}
      }
      nRankMin = 1;
      nRankMax = pDoc->m_uintLimitX;
      // Betrag aus Minimum & Maximum errechnen
      nRankSpan = nRankMax - nRankMin;
      nWordLenSpan = nWordLenMax - nWordLenMin;
      if((nWordLenMax > nWordLenMin) && (nRankMax > nRankMin))
      {
        pDC->SelectObject(&CGrayBrush);
        pDC->Rectangle(nDistance/2,nDistance/2,lRect.Width()-(nDistance/2),lRect.Height()-(nDistance/2));
        pDC->SelectObject(&CBlackPen2);
        pDC->MoveTo(nDistance/2,nDistance/2);
        pDC->LineTo(nDistance/2,lRect.Height()-(nDistance/2)); // Y-Achse zeichnen
        pDC->LineTo(lRect.Width()-(nDistance/2),lRect.Height()-(nDistance/2)); // X-Achse zeichnen
        // Achsenbeschriftung
        pDC->SetTextAlign(TA_CENTER);
        CArialFont_MainTitle.CreatePointFont(240,"Arial");
        pDC->SelectObject(&CArialFont_MainTitle);
        pDC->TextOut(lRect.Width()/2,0,"Folge von Wortlängen");
        CArialFont_SubTitle.CreatePointFont(120,"Arial");
        pDC->SelectObject(&CArialFont_SubTitle);
        strOutput = "Rang ";
        strTemp.Format("%d",nRankMin); strOutput += strTemp;
        strOutput += "...";
        strTemp.Format("%d",nRankMax); strOutput += strTemp;
        pDC->TextOut(lRect.Width()/2,lRect.Height()-nDistance/4,strOutput);
        strMyFont.lfHeight = 20;
        strMyFont.lfEscapement = 900;
        strcpy(strMyFont.lfFaceName,"Arial");
        CArialFont_SubTitle2.CreateFontIndirect(&strMyFont);
        pDC->SelectObject(&CArialFont_SubTitle2);
        strOutput = "Wortlänge ";
        strTemp.Format("%d",nWordLenMin); strOutput += strTemp;
        strOutput += "...";
        strTemp.Format("%d",nWordLenMax); strOutput += strTemp;
        pDC->TextOut(0,lRect.Height()/2,strOutput);
        // Maßeinteilung der Achsen beschriften
        pDC->SelectObject(&CBlackPen1);
        CArialFont_AxisDescription.CreatePointFont(100,"Arial");        
        int m;
        if(nWordLenMax <= 9) { m = 1; } else m = nWordLenMax/10;
        for(i = 2; i < nWordLenMax; i++)
        {
          if(i % m == 0)
          {
            pDC->SelectObject(&CArialFont_AxisDescription);
            strOutput.Format("%d",i);
            y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(i-nWordLenMin))/nWordLenSpan)+(nDistance/2);
            pDC->TextOut(nDistance/2-20,y-7,strOutput);
            pDC->MoveTo(nDistance/2-7,y);
            pDC->LineTo(lRect.Width()-(nDistance/2),y);
          }
        }
        if(nRankMax <= 9) { m = 1; } else m = nRankMax/10;
        for(i = 1; i < nRankMax; i++)
        {
          if(i % m == 0)
          {
            pDC->SelectObject(&CArialFont_AxisDescription);
            strOutput.Format("%d",i);
            x = ((lRect.Width()-nDistance)*(i-nRankMin)/nRankSpan)+(nDistance/2);
            y = lRect.Height()-nDistance/2-20;
            pDC->TextOut(x,y+30,strOutput);
            pDC->MoveTo(x,y+20);
            pDC->LineTo(x,y+30);
          }
        }
        // Graph zeichnen
        bMove = false;
        pCOldPen = pDC->SelectObject(&CBluePen);
        for(i = 0; i < nRankMax; i++)
        {
          if(!bMove) // nur bei Beginn des Linienzeichnens hier reinspringen
          {
            x = ((lRect.Width()-nDistance)*((i+1)-nRankMin))/nRankSpan+(nDistance/2);
            y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(WordLen[i]-nWordLenMin))/nWordLenSpan)+(nDistance/2);
            pDC->MoveTo(x,y);
            bMove = true;
          }
          x = ((lRect.Width()-nDistance)*((i+1)-nRankMin))/nRankSpan+(nDistance/2);
          y = ((lRect.Height()-nDistance)-((lRect.Height()-nDistance)*(WordLen[i]-nWordLenMin))/nWordLenSpan)+(nDistance/2);
          pDC->LineTo(x,y);
        }
        pDC->SelectObject(pCOldPen);
      }
      break;
    }
  }
}

/////////////////////////////////////////////////////////////////////////////
// CWordStatView printing


BOOL CWordStatView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWordStatView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWordStatView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWordStatView diagnostics

#ifdef _DEBUG
void CWordStatView::AssertValid() const
{
	CView::AssertValid();
}

void CWordStatView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWordStatDoc* CWordStatView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWordStatDoc)));
	return (CWordStatDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWordStatView message handlers

