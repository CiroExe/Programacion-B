#include <stdio.h>
#include <stdlib.h>
#include "PilaEstatica.h"
int main()
{
    FILE *arch;
    char car;
    TPila P;

    arch=fopen("letras.txt", "r");

    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        iniciaP(&P);

        fscanf(arch,"%c",&car);
        while (!feof(arch)){
            poneP(&P,car);
            printf("%c\n",car);
            fscanf(arch,"%c",&car);
        }

        printf("Elementos quitados de la pila\n");

        while (!VaciaP(P)){
            sacaP(&P,&car);
            printf("%c\n", car);
        }
        fclose(arch);
    }
    return 0;
}
