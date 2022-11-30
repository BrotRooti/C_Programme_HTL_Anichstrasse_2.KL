//
// Created by Phillip on 16.11.2022.
//
#include <stdio.h>
#include "BildschirmRoutinen.h"

void HLinie(int iZeile, int iStartSpalte, int iEndSpalte){
    int iSpalte;
    for (iSpalte = iStartSpalte; iSpalte <= iEndSpalte; iSpalte++){

        GotoZS(iZeile, iSpalte);
        printf("-");
    }
    printf("\n");
}

void VLinie(int iStartZeile, int iEndZeile, int iSpalte){
    int iZeile;
    for (iZeile = iStartZeile; iZeile <= iEndZeile; iZeile++){

        GotoZS(iZeile, iSpalte);
        printf("|");
    }
    printf("\n");
}

int main() {
    GotoZS(12,25);
    SetColor(GREEN,YELLOW);
    printf("Hello World\n");
    SetColor(WHITE,BLACK);
    GotoZS(13,40);
    HLinie(10, 0, 50);
    VLinie(11, 13, 0);
    VLinie(11, 13, 50);
    HLinie(14, 0, 50);
    return 0;
}