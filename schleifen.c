//
// Created by Phillip on 09.11.2022.
//
#include <stdio.h>
int main() {
    int iZaehler;
    int iUpdate;

    iZaehler = 0;
    iUpdate = 2;


    while (iZaehler < 10) {

        printf("Zaehler: %d\n", iZaehler);
        iZaehler++;
    }
// empty line
    printf("\n");

    iZaehler = 0;

    do {
        printf("Zaehler: %d\n", iZaehler);
        iZaehler++;
    } while (iZaehler < 10);


    printf("Schleifen in C\n");
    return 0;

}