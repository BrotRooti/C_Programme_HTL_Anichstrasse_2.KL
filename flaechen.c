
#include <stdio.h>



int FlaecheRechteck (int iLaenge, int iBreite)
{
    int iFlaeche;
    iFlaeche = iLaenge * iBreite;
    return iFlaeche;
}
int FlaecheQuadrate (int iSeite)
{
    int iFlaeche;
    iFlaeche = FlaecheRechteck( iSeite ,iSeite);
    return iFlaeche;
}


int main() {
    int iLaenge;
    int iBreite;
    int iSeite;
    int iErgebnis;

    iErgebnis = FlaecheQuadrate( 5 );

    printf("Ergebnis: %d\n", iErgebnis);
    printf("Hello, World!\n");
    return 0;
}
