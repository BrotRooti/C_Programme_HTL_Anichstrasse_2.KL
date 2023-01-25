// --------------------------------------------------------------------------------
// Übungs-Vorlage 2. Klasse FSST/µC - fliegender Punkt innerhalb eines Vierecks
// DI. Mag(FH) Klingler - Jänner 2023
// Wissensbereiche
// - Befehle (if, switch/case)
// - Funktionen
// - Schleifen
// - Einbinden externen Funktionen mittels include
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "BildschirmRoutinen.h"

// --------------------------------------------------------------------------------
// ein Zeichen an die vorgegebene Position schreiben
// --------------------------------------------------------------------------------
void PunktSetzen (int iZeile,int iSpalte,char cZeichen)
{
    GotoZS (iZeile,iSpalte);
    printf ("%c",cZeichen);
}

// --------------------------------------------------------------------------------
// eine horizontale Linie zeichnen
// --------------------------------------------------------------------------------
void HorizontaleLinie (int iZeile,int iSpalteVon,int iSpalteBis,char cZeichen)
{
    int iSpalte;

    for (iSpalte=iSpalteVon;iSpalte<=iSpalteBis;iSpalte++)
    {
        PunktSetzen (iZeile,iSpalte,cZeichen);
    }
}

// --------------------------------------------------------------------------------
// eine vertikale Linie zeichnen
// --------------------------------------------------------------------------------
void VertikaleLinie (int iSpalte,int iZeileVon,int iZeileBis,char cZeichen)
{
    int iZeile;

    for (iZeile=iZeileVon;iZeile<=iZeileBis;iZeile++)
    {
        PunktSetzen (iZeile,iSpalte,cZeichen);
    }
}

// --------------------------------------------------------------------------------
// ein Viereck aus 2 horizontalen/vertikalen Linien zeichnen
// --------------------------------------------------------------------------------
void Rechteck (int iObenZeile,int iObenSpalte,int iUntenZeile,int iUntenSpalte,char cZeichen)
{
    HorizontaleLinie (iObenZeile,iObenSpalte,iUntenSpalte,cZeichen);
    HorizontaleLinie (iUntenZeile,iObenSpalte,iUntenSpalte,cZeichen);

    VertikaleLinie (iObenSpalte,iObenZeile,iUntenZeile,cZeichen);
    VertikaleLinie (iUntenSpalte,iObenZeile,iUntenZeile,cZeichen);
}

// --------------------------------------------------------------------------------
// Spielfeld zeichnen
// --------------------------------------------------------------------------------
void SpielfeldZeichnen ()
{
    ClrScr();
    printf ("******************************************************************\n");
    printf ("*                               |                                *\n");
    printf ("*                               |                                *\n");
    printf ("*                               |                                *\n");
    printf ("*                               |                                *\n");
    printf ("*                               |                                *\n");
    printf ("*                               |                                *\n");
    printf ("*                +++++++++++++++++++++++++++++                   *\n");
    printf ("*                                                                *\n");
    printf ("*                                                                *\n");
    printf ("*                                                                *\n");
    printf ("*                                                                *\n");
    printf ("*                +++++++++++++++++++++++++++++                   *\n");
    printf ("*                               |                                *\n");
    printf ("*                               |                                *\n");
    printf ("*                               |                                *\n");
    printf ("*                               |                                *\n");
    printf ("*                               |                                *\n");
    printf ("*                               |                                *\n");
    printf ("******************************************************************\n");

}


// --------------------------------------------------------------------------------
// Info anzeigen
// --------------------------------------------------------------------------------
void InfosAnzeigen (int iZeile, int iSpalte, int iRictung,int iColor){
    GotoZS (10,75);
    printf ("Position: %2d|%2d\n",iZeile,iSpalte);
    GotoZS (11,75);
    printf ("Richtung: ");
    GotoZS(12,75);
    printf ("Farbe: ");

    GotoZS(11,85);

    switch (iRictung) {
        case 0:printf("N  ");break;
        case 1:printf("NW ");break;
        case 2:printf("W  ");break;
        case 3:printf("SW ");break;
        case 4:printf("S  ");break;
        case 5:printf("SE ");break;
        case 6:printf("E  ");break;
        case 7:printf("NE ");break;
        default:printf("? ");break;
    }
    GotoZS(12,82);
    switch (iColor) {
        case 1:printf("dunkel Blau   ");break;
        case 2:printf("dunkel Gruen  ");break;
        case 3:printf("dunkel Tuerkis");break;
        case 4:printf("dunekl Rot    ");break;
        case 5:printf("dunkel Lila   ");break;
        case 6:printf("dunkel Gelb   ");break;
        case 7:printf("Grau          ");break;
        case 8:printf("dunkel Grau   ");break;
        case 9:printf("Blau          ");break;
        case 10:printf("Gruen        ");break;
        case 11:printf("Tuerkis      ");break;
        case 12:printf("Rot          ");break;
        case 13:printf("Lila         ");break;
        case 14:printf("Gelb         ");break;
        case 15:printf("Weis         ");break;

        default:printf("?");

    }

}
// --------------------------------------------------------------------------------
// einen Punkt zufällig innerhalb eines Vierecks fliegen lassen
// --------------------------------------------------------------------------------
void FliegenderPunkt (int iZeileOben,int iSpalteLinks,
                    int iZeileUnten,int iSpalteRechts,
                    char cZeichen,int iDelay)
{
    int iRichtung;
    int iNeueZeile;
    int iNeueSpalte;
    int iAktuelleZeile;
    int iAktuelleSpalte;
    int iCounter;
    int iColor;
    int iColorSwitch;

    SpielfeldZeichnen();

    iAktuelleZeile=(iZeileOben+iZeileUnten)/2;
    iAktuelleSpalte=(iSpalteLinks+iSpalteRechts)/2;
    iRichtung=0;

    for (;;)
    {
        // neue Position ermitteln
        switch (iRichtung)
        {
            case 0:iNeueZeile=iAktuelleZeile-1;iNeueSpalte=iAktuelleSpalte  ;break;
            case 1:iNeueZeile=iAktuelleZeile-1;iNeueSpalte=iAktuelleSpalte+1;break;
            case 2:iNeueZeile=iAktuelleZeile  ;iNeueSpalte=iAktuelleSpalte+1;break;
            case 3:iNeueZeile=iAktuelleZeile+1;iNeueSpalte=iAktuelleSpalte+1;break;
            case 4:iNeueZeile=iAktuelleZeile+1;iNeueSpalte=iAktuelleSpalte;break;
            case 5:iNeueZeile=iAktuelleZeile+1;iNeueSpalte=iAktuelleSpalte-1;break;
            case 6:iNeueZeile=iAktuelleZeile  ;iNeueSpalte=iAktuelleSpalte-1;break;
            case 7:iNeueZeile=iAktuelleZeile-1;iNeueSpalte=iAktuelleSpalte-1;break;
            default:break;
        }

        // passt die neue Position?
        if (GetCharZS (iNeueZeile,iNeueSpalte)==' ')
        {
            // ja => übernehmen
            iAktuelleZeile=iNeueZeile;
            iAktuelleSpalte=iNeueSpalte;
            iCounter++;
        }
        else
        {
          // nein => neue Richtung
            iRichtung=Zufall (0,7);
            iCounter=0;
        }
        iColorSwitch = Zufall(0,10);
        
        if(iColorSwitch==5){
            iColor=Zufall (1,15);
            SetColor(iColor,BLACK);
        }

        InfosAnzeigen(iAktuelleZeile,iAktuelleSpalte,iRichtung,iColor);
        PunktSetzen (iAktuelleZeile,iAktuelleSpalte,cZeichen);
        Delay (iDelay);
        PunktSetzen (iAktuelleZeile,iAktuelleSpalte,' ');

        if (iCounter==10) iRichtung=Zufall (0,7);
    }
}

// --------------------------------------------------------------------------------
// H A U P T R O U T I N E
// --------------------------------------------------------------------------------
int main()
{
    InitZufall ();
    FliegenderPunkt (3,3,20,60,'*',30);

    return 0;
}
