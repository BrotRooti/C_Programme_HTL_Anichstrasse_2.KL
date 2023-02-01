# include "stdio.h"
# include "stdlib.h""
# include "HilfsFunktionen.h"
# include "BildschirmRoutinen.h"

void BeweglicheLinie(int iZeileStart,int iSpalteStart,int iZeileEnde,int iSpalteEnde, char cZeichen, int iDelay){
    int iZeile;
    int iSeite;
    int iSpalte;
    int iRichtung;
    iSpalte = (iSpalteStart + iSpalteEnde)/ 2;
    iRichtung = 1; //1 = dowm, 0 = up
    for (;;) {
        switch (iRichtung) {
            case 1:
                for (iZeile = iSpalteStart; iZeile != iZeileEnde; iZeile++) {
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteStart + 1, iZeile, iSpalte , cZeichen);
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteEnde -1, iZeile, iSpalte , cZeichen);

                    Delay(iDelay);
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteStart + 1, iZeile, iSpalte, ' ');
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteEnde -1, iZeile, iSpalte, ' ');
                }
                iRichtung = 0;
                break;
            case 0:
                for (iZeile = iZeileEnde; iZeile != iZeileStart; iZeile--) {
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteStart + 1, iZeile, iSpalte , cZeichen);
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteEnde -1, iZeile, iSpalte , cZeichen);

                    Delay(iDelay);
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteStart + 1, iZeile, iSpalte, ' ');
                    ZeichneLinie(((iZeileStart + iZeileEnde) / 2), iSpalteEnde -1, iZeile, iSpalte, ' ');
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