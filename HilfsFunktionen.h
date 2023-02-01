#ifndef HILFSFUNKTIONEN_H
#define HILFSFUNKTIONEN_H

#define STUNDE  0
#define MINUTE  1
#define SEKUNDE 2

void ZeichneLinieFloat (int iZeileVon,int iSpalteVon,int iZeileNach,int iSpalteNach,char cZeichen);
void ZeichneLinie (int iZeileVon,int iSpalteVon,int iZeileNach,int iSpalteNach,char cZeichen);
int  KreisPunktZ (int iZeileMitte,int iSpalteMitte,int iWinkel,int iRadius);
int  KreisPunktS (int iZeileMitte,int iSpalteMitte,int iWinkel,int iRadius);
int  UhrZeit (int iMode);
#endif
