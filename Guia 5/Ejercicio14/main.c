#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"

void CargaCola(TCola *);
void esPalindroma(TCola *, TPila *);

int main()
{
    TCola C;
    TPila P;

    iniciaC(&C);
    iniciaP(&P);
    CargaCola(&C);
    esPalindroma(&C, &P);


    return 0;
}

void CargaCola(TCola *C){
    TElementoC caracter;
    char pal[20];
    unsigned int i, n;

    printf("Ingrese palabra\n");
    scanf("%s", pal);

    n=strlen(pal);

    for (i=0; i<n; i++){
        poneC(C, pal[i]);
    }
}

void esPalindroma(TCola *C, TPila *P){
    TCola auxC;
    TElementoC caracter, caracterC, caracterP;
    int esPal = 1;

    iniciaC(&auxC);
    while (!VaciaC(*C)) {
        sacaC(C, &caracter);
        poneC(&auxC, caracter);
        poneP(P, caracter);
    }

    while (!VaciaC(auxC) && !VaciaP(*P)) {
        sacaC(&auxC, &caracterC);
        sacaP(P, &caracterP);

        if (caracterC != caracterP) {
            esPal = 0;
        }

        poneC(C, caracterC);
    }

    if (esPal)
        printf("La palabra es palindroma\n");
    else
        printf("La palabra NO es palindroma\n");
}
