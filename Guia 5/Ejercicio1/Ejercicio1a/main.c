#include <stdio.h>
#include <stdlib.h>
#include "Pila Estatica.h"

int main()
{
    TElementoP num;
    TPila P;
    char res;

    IniciaP(&P);

    printf("Ingrese numero que desea ingresar a la pila (999 para finalizar)\n");
    scanf("%d",&num);
    while(num != 999)
    {
        poneP(&P, num);
        printf("Ingrese numero que desea ingresar a la pila (999 para finalizar)\n");
        scanf("%d",&num);

    }

    printf("Elementos quitados de la pila -->\t");

    while (!VaciaP(P))
        sacaP(&P, &num);
    return 0;
}
