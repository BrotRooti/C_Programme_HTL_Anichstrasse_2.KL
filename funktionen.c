
#include <stdio.h>

int iGlobal;

int Summe(int iA, int iB)
{
    int iErg;
    iErg = iA + iB;
    return iErg;
}


int main() {
    int iWert1;
    int iWert2;
    int iErgebnis;

    iWert1 = 1;
    iWert2 = 2;
    iErgebnis = Summe(iWert1, iWert2);

    printf("Ergebnis: %d\n", iErgebnis);
    printf("Hello, World!\n");
    return 0;
}
