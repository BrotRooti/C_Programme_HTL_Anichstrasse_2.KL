//
// Created by Phillip on 14.12.2022.
//
#include <stdio.h>
#include "BildschirmRoutinen.h"

void PunktZeichen (int iZeile,int iSpalte,char cZeichen,int iDelay){
    GotoZS(iZeile,iSpalte);
    printf("%c",cZeichen);
    Delay(iDelay);
    GotoZS(iZeile,iSpalte);
    printf(" ");
}

void FliegendesTeil (int iZeileOben,int iSpalteLinks,int iZeileUnten,int iSpalteRechts,char cZeichen,int iDelay){
    int iSpalte;
    int iZeile;
    int iNeueSpalte;
    int iNeueZeile;
    int iRichtungSpalte;
    int iRichtungZeile;

    iZeile =(iZeileOben+iZeileUnten)/2;
    iSpalte=(iSpalteLinks+iSpalteRechts)/2;
    iRichtungSpalte=1;
    iRichtungZeile=1;


    for (;;){
        iNeueSpalte=iSpalte+iRichtungSpalte;
        iNeueZeile=iZeile+iRichtungZeile;
        if ( (iSpalteLinks < iNeueSpalte) && (iNeueSpalte<iSpalteRechts)){
            // im erlaubten Bereich
            //iSpalte=iNeueSpalte;
        }
        else{
            // nicht im erlaubten Bereich
            iRichtungSpalte=-iRichtungSpalte;
        }
        if ( (iZeileOben < iNeueZeile) && (iNeueZeile<iZeileUnten)){
            // im erlaubten Bereich
            iZeile=iNeueZeile;
        }
        else{
            // nicht im erlaubten Bereich
            iRichtungZeile=-iRichtungZeile;
        }

        PunktZeichen(iZeile,iSpalte,cZeichen,iDelay);
    }

}




int main(){
    FliegendesTeil(1,1,30,30,'*',50);
    return 0;
}