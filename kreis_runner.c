#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BildschirmRoutinen.h"



void KreisWanderung (float fWinkel,int iMitte, int iRadius, int cZeichen, int iDelay) // Function which makes the code possible
{
    int iSpalte;
    int iZeile;

    while (1){
        iSpalte = iMitte + iRadius * cos(fWinkel);
        iZeile = iMitte + iRadius * sin(fWinkel);

        GotoXY(iSpalte,iZeile);
        printf("%c",cZeichen);
        Delay(iDelay);
        GotoXY(iSpalte,iZeile);
        printf(" ");
        fWinkel ++;
    }

}



int main ()
{

    KreisWanderung (10,10,5,'+',50);
    return 0;
}
