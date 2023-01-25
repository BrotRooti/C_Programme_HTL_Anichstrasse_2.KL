# include "stdio.h"
# include "stdlib.h""
# include "HilfsFunktionen.h"
# include "BildschirmRoutinen.h"

void BeweglicheLinie(int iZeileStart,int iSpalteStart,int iZeileEnde,int iSpalteEnde, char cZeichen, int iDelay){
    int iZeile;
    int iSeite;
    int iRichtung;
    iRichtung = 1; //1 = dowm, 0 = up
    iSeite = 1;
    switch (iSeite) {
        case 1:
            ZeichneLinie(iZeileStart,iSpalteStart,iZeileEnde,iSpalteStart,cZeichen);

        case 2:
            ZeichneLinie(iZeileStart,iSpalteStart,iZeileStart,iSpalteEnde,cZeichen);

        case 3:
            ZeichneLinie(iZeileStart,iSpalteEnde,iZeileEnde,iSpalteEnde,cZeichen);

        case 4:
            ZeichneLinie(iZeileEnde,iSpalteStart,iZeileEnde,iSpalteEnde,cZeichen);
            break;


    }
    for (;;) {
        switch (iRichtung) {
            case 1:
                for (iZeile = iSpalteStart; iZeile != iZeileEnde; iZeile++) {
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteStart + 1, iZeile, iSpalteEnde - 1, cZeichen);
                    Delay(iDelay);
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteStart + 1, iZeile, iSpalteEnde - 1, ' ');
                }
                iRichtung = 0;
                break;
            case 0:
                for (iZeile = iZeileEnde; iZeile != iZeileStart; iZeile--) {
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteStart + 1, iZeile, iSpalteEnde - 1, cZeichen);
                    Delay(iDelay);
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteStart + 1, iZeile, iSpalteEnde - 1, ' ');
                }
                iRichtung = 1;
                break;


        }
    }


}



int main (){
    BeweglicheLinie(2,2,24,75,'*',50);
    return 0;
}