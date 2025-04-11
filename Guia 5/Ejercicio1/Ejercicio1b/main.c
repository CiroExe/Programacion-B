#include <stdio.h>
#include <stdlib.h>
#include "PilaDinamica.h"

int main()
{
    int num;
    unsigned short int cont=0;
    TPila P;

    IniciaP(&P);

    printf("Ingrese numero que desea ingresar a la pila (999 para finalizar)\n");
    scanf("%d", &num);

    while (num != 999)
    {
        poneP(&P, num);
        printf("Se ingreso el elemento %d en la pila\n",num);
        printf("Ingrese numero que desea ingresar a la pila (999 para finalizar)\n");
        scanf("%d", &num);
    }

    printf("Elementos quitados de la pila -->\t\n");
    while (!VaciaP(P))
    {
        cont++;
        if (cont == 3)
            printf("El tercer elemento eliminado es %d", consultaP(P));
        sacaP(&P, &num);
    }
    return 0;
}
