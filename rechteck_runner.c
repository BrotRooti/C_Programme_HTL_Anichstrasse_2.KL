//
// Created by sepp2 on 30.11.2022.
//
//
// Created by Phillip on 16.11.2022.
//
#include <stdio.h>
#include "BildschirmRoutinen.h"

// a function that makes a character move around a rectangle
// iZeileOben,iSpalteLinks,iZeileUnten,iSpalteRechts are the coordinates of the rectangle
// cZeichen is the character that is moving
// iDelay is the delay between each movement
void RechteckWanderung (iZeileOben,iSpalteLinks,iZeileUnten,iSpalteRechts,cZeichen,iDelay)
{
    int iX,iY,iRichtung;
    iX=iSpalteLinks;
    iY=iZeileOben;
    iRichtung=1;
    while (1)
    {
        GotoXY(iX,iY);
        printf("%c",cZeichen);
        Delay(iDelay);
        GotoXY(iX,iY);
        printf(" ");
        switch (iRichtung)
        {
            case 1:
                iX++;
                if (iX==iSpalteRechts)
                {
                    iRichtung=2;
                }
                break;
            case 2:
                iY++;
                if (iY==iZeileUnten)
                {
                    iRichtung=3;
                }
                break;
            case 3:
                iX--;
                if (iX==iSpalteLinks)
                {
                    iRichtung=4;
                }
                break;
            case 4:
                iY--;
                if (iY==iZeileOben)
                {
                    iRichtung=1;
                }
                break;
        }
    }
}

void HLinie(int iZeile, int iStartSpalte, int iEndSpalte, char cZeichen){
    int iSpalte;
    for (iSpalte = iStartSpalte; iSpalte <= iEndSpalte; iSpalte++){

        GotoZS(iZeile, iSpalte);
        printf("%c",cZeichen);
    }
    printf("\n");
}

void VLinie(int iStartZeile, int iEndZeile, int iSpalte, char cZeichen){
    int iZeile;
    for (iZeile = iStartZeile; iZeile <= iEndZeile; iZeile++){

        GotoZS(iZeile, iSpalte);
        printf("%c",cZeichen);
    }
    printf("\n");
}


int main ()
{
    // allgemein
    // RechteckWanderung (iZeileOben,iSpalteLinks,iZeileUnten,iSpalteRechts,cZeichen,iDelay);
    // Beispiel-Aufruf
    RechteckWanderung (3,20,20,60,'+',50);

    return 0;
}

