//
// Created by Phillip on 16.11.2022.
//
#include <stdio.h>
#include "BildschirmRoutinen.h"

// a function that makes a character move around a rectangle
// iZeileOben,iSpalteLinks,iZeileUnten,iSpalteRechts are the coordinates of the rectangle
// cZeichen is the character that is moving
// iDelay is the delay between each movement
void RechteckWanderung (int iZeileOben,int iSpalteLinks,int iZeileUnten,int iSpalteRechts,char cZeichen,int iDelay)
{
    int iXPos;
	int iYPos;
	int iRichtung;
    iXPos=iSpalteLinks;
    iYPos=iZeileOben;
    iRichtung=1;
    while (1==1)
    {
        GotoXY(iXPos,iYPos);
        printf("%c",cZeichen);
        Delay(iDelay);
        GotoXY(iXPos,iYPos);
        printf(" ");
        switch (iRichtung)
        {
            case 1:
                iXPos++;
                if (iXPos==iSpalteRechts)
                {
                    iRichtung=2;
                }
                break;
            case 2:
                iYPos++;
                if (iYPos==iZeileUnten)
                {
                    iRichtung=3;
                }
                break;
            case 3:
                iXPos--;
                if (iXPos==iSpalteLinks)
                {
                    iRichtung=4;
                }
                break;
            case 4:
                iYPos--;
                if (iYPos==iZeileOben)
                {
                    iRichtung=1;
                }
                break;
        }
    }
}



int main ()
{
    // allgemein
    // RechteckWanderung (iZeileOben,iSpalteLinks,iZeileUnten,iSpalteRechts,cZeichen,iDelay);
    // Beispiel-Aufruf
    RechteckWanderung (3,20,20,60,'+',50);

    return 0;
}

