#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void CargaPila(TPila *, int);
void MuestraResultado(TPila *);
void sumaP(TPila *, TPila *, TPila *);

int main()
{
    TPila P1,P2, P3;
    int n;

    iniciaP(&P1);
    iniciaP(&P2);
    iniciaP(&P3);

    printf("Ingrese cantidad de digitos del primer numero ->\t");
    scanf("%d", &n);
    CargaPila(&P1, n);
    printf("\n");

    printf("Ingrese cantidad de digitos del segundo numero ->\t");
    scanf("%d", &n);
    CargaPila(&P2, n);

    sumaP(&P1, &P2, &P3);
    MuestraResultado(&P1);
    MuestraResultado(&P2);
    MuestraResultado(&P3);

    return 0;
}

void CargaPila(TPila *P, int n){
    TElementoP elem;
    int i;

    printf("Ingrese el número dígito a dígito:\n");
    for (i = 0; i < n; i++) {
        scanf(" %c", &elem);
        getchar();
        poneP(P, elem);
    }
}

void sumaP(TPila *P1, TPila *P2, TPila *P3){
    int suma,resto ,acarreo=0;
    TElementoP elem1, elem2, resultado;

    while (!VaciaP(*P1) || !VaciaP(*P2)){
        if (!VaciaP(*P1)){
            sacaP(P1, &elem1);
            printf("%c\n", elem1);

        }
        else
            elem1='0';

         if (!VaciaP(*P2)){
            sacaP(P2, &elem2);
            printf("%c\n", elem2);
        }
         else
            elem2='0';

        suma = (elem1 -'0') + (elem2 - '0') + acarreo;
        acarreo = suma / 10;
        resto = suma % 10;

        resultado = resto + '0';

        poneP(P3, resultado);
        printf("Ingreso %c\n", resultado);
    }

    if (acarreo !=0){
        resultado=acarreo + '0';
        poneP(P3, resultado);
        printf("Ingreso %c\n", resultado);
    }
}

void MuestraResultado(TPila *P)
{
    TElementoP elem;
    if (!VaciaP(*P))
    {
        sacaP(P, &elem);
        printf("%d ", (elem - '0'));
        MuestraResultado(P);
        poneP(P, elem);
    }
}
