#include "BildschirmRoutinen.h"
#include "HilfsFunktionen.h"
#include <math.h>
#include <time.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#define ABS(X) ((X)>=0 ? (X) : -(X))

// -----------------------------------------------------------------------------------------------------------------
// eine Linie zeichnen auf Integer-Basis
// -----------------------------------------------------------------------------------------------------------------
void ZeichneLinie (int iZeileVon,int iSpalteVon,int iZeileNach,int iSpalteNach,char cZeichen)
{
    int iDeltaZeile;
    int iDeltaSpalte;
    int iSchrittZeile;
    int iSchrittSpalte;
    int iZeile;
    int iSpalte;
    int iSumme;

    // Endpunkte einzeichnen
    GotoZS (iZeileVon,iSpalteVon);
    printf ("%c",cZeichen);
    GotoZS (iZeileNach,iSpalteNach);
    printf ("%c",cZeichen);

    // Entfernung der Punkte ermitteln
    iDeltaZeile=iZeileNach-iZeileVon;
    iDeltaSpalte=iSpalteNach-iSpalteVon;

    // beide Punkte sind ident => fertig
    if  ( (iDeltaZeile==0) && (iDeltaSpalte==0) )
    {
        return;
    }

    // Abarbeitungsrichtung
    iSchrittZeile=(iDeltaZeile>0 ? 1 : -1);
    iSchrittSpalte=(iDeltaSpalte>0 ? 1 : -1);
    iDeltaZeile=ABS(iDeltaZeile);
    iDeltaSpalte=ABS(iDeltaSpalte);

    // Aufteilung in +/-45 Bereiche
    if (iDeltaSpalte>iDeltaZeile)
    {
        // +/- 45° Linie
        iSumme=iDeltaSpalte/2;
        iZeile=iZeileVon;

        for (iSpalte=iSpalteVon;iSpalte!=iSpalteNach;iSpalte+=iSchrittSpalte)
        {
            iSumme+=iDeltaZeile;
            if (iSumme>=iDeltaSpalte)
            {
                iSumme-=iDeltaSpalte;
                iZeile+=iSchrittZeile;
            }

            GotoZS (iZeile,iSpalte);
            printf ("%c",cZeichen);
        }
    }
    else
    {
        // ausserhalb +/- 45° Linie
        iSumme=iDeltaZeile/2;
        iSpalte=iSpalteVon;

        for (iZeile=iZeileVon;iZeile!=iZeileNach;iZeile+=iSchrittZeile)
        {
            iSumme+=iDeltaSpalte;
            if (iSumme>=iDeltaZeile)
            {
                iSumme-=iDeltaZeile;
                iSpalte+=iSchrittSpalte;
            }

            GotoZS (iZeile,iSpalte);
            printf ("%c",cZeichen);
        }
    }
}

// -----------------------------------------------------------------------------------------------------------------
// eine Linie zeichnen mit y=kx+d mit float-Genauigkeit
// -----------------------------------------------------------------------------------------------------------------
void ZeichneLinieFloat (int iZeileVon,int iSpalteVon,int iZeileNach,int iSpalteNach,char cZeichen)
{
    int iDeltaZeile;
    int iDeltaSpalte;
    int iSchritt;
    int iZeile;
    int iSpalte;
    float fK;
    float fD;

    // Endpunkte einzeichnen
    GotoZS (iZeileVon,iSpalteVon);
    printf ("%c",cZeichen);
    GotoZS (iZeileNach,iSpalteNach);
    printf ("%c",cZeichen);
    iDeltaZeile=iZeileNach-iZeileVon;
    iDeltaSpalte=iSpalteNach-iSpalteVon;

    // beide Punkte sind ident => fertig
    if  ( (iDeltaZeile==0) && (iDeltaSpalte==0) )
    {
        return;
    }

    // Aufteilung in +/-45 Bereiche
    if (ABS (iDeltaSpalte) > ABS(iDeltaZeile) )
    {
        // +/- 45° Linie
        iSchritt=(iDeltaSpalte>0 ? 1 : -1);
        fK=(float)iDeltaZeile/(float)iDeltaSpalte;
        fD=iZeileVon-fK*iSpalteVon;

        for (iSpalte=iSpalteVon;iSpalte!=iSpalteNach;iSpalte+=iSchritt)
        {
            iZeile=(int)(fK*iSpalte+fD+0.5f);
            GotoZS (iZeile,iSpalte);
            printf ("%c",cZeichen);
        }
    }
    else
    {
        // ausserhalb +/- 45° Linie
        iSchritt=(iDeltaZeile>0 ? 1 : -1);
        fK=(float)iDeltaSpalte/(float)iDeltaZeile;
        fD=iSpalteVon-fK*iZeileVon;

        for (iZeile=iZeileVon;iZeile!=iZeileNach;iZeile+=iSchritt)
        {
            iSpalte=(int)(fK*iZeile+fD+0.5f);
            GotoZS (iZeile,iSpalte);
            printf ("%c",cZeichen);
        }
    }
}

// -----------------------------------------------------------------------------------------------------------------
// Zeile eines Kreispunktes bestimmen - Winkel in °
// -----------------------------------------------------------------------------------------------------------------
int KreisPunktZ (int iZeileMitte,int iSpalteMitte,int iWinkel,int iRadius)
{
    return (int)(iZeileMitte+iRadius*cos(2*M_PI*iWinkel/360.0)+0.5f);
}

// -----------------------------------------------------------------------------------------------------------------
// Spalte eines Kreispunktes bestimmen - Winkel in °
// -----------------------------------------------------------------------------------------------------------------
int KreisPunktS (int iZeileMitte,int iSpalteMitte,int iWinkel,int iRadius)
{
    return (int)(iSpalteMitte+iRadius*sin(2*M_PI*iWinkel/360.0)+0.5f);
}

// -----------------------------------------------------------------------------------------------------------------
// aktuelle Zeit ermitteln (iMode=STUNDE oder MINUTE oder SEKUNDE
// -----------------------------------------------------------------------------------------------------------------
int UhrZeit (int iMode)
{
    struct tm *opAktuelleZeit;
    time_t oJetzt;
    int iReturn;

    time(&oJetzt);
    opAktuelleZeit = localtime(&oJetzt);

    switch (iMode)
    {
        case STUNDE :iReturn=opAktuelleZeit->tm_hour;break;
        case MINUTE :iReturn=opAktuelleZeit->tm_min;break;
        case SEKUNDE:iReturn=opAktuelleZeit->tm_sec;break;
        default:iReturn=0;break;
    }

    return iReturn;
}

