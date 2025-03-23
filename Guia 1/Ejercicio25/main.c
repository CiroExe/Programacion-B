#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    char nombre[20];
    int edad;
} TPersonas;

void llenarVec(TPersonas [], int *);
void SuperanEdad(TPersonas [], int, int *);
float porcentajeMayores(TPersonas [], int);

int main(){
    TPersonas personas[MAX];
    int n, X;

    llenarVec(personas, &n);
    SuperanEdad(personas,n,&X);
    printf("Porcentaje mayores de edad %2.2f%\n", porcentajeMayores(personas,n)*100);
    return 0;
}

void llenarVec(TPersonas personas[],int *n){
    int i;

    printf("Ingrese cantidad total de personas\n");
    scanf("%d", n);

    for (i=0;i<*n;i++){
        printf("Persona %d\n",i+1);
        printf("Nombre: ");
        scanf("%s", personas[i].nombre);
        printf("Edad: ");
        scanf("%d",&personas[i].edad);
    }
}

void SuperanEdad(TPersonas personas[],int n, int *X){
    int i=0;
    printf("Ingrese X\n");
    scanf("%d", X);
    printf("Cantidad de personas que tienen mas de %d anios\n", *X);
    for (;i<n;i++){
        if (personas[i].edad > *X)
            printf("%s\n", personas[i].nombre);
    }


}

float porcentajeMayores(TPersonas personas[], int n){
    int contMayores=0;

    for(int i=0;i<n;i++){
        if (personas[i].edad >= 18)
            contMayores++;
    }

    return (float)contMayores/n;
}




