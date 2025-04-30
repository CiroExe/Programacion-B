#include <stdio.h>
#include <stdlib.h>

typedef struct nodoD{
    char letra;
    struct nodoD *ant, *sig;
}nodoD;
typedef nodoD *PnodoD;

typedef struct {
    PnodoD pri, ult;
}TListaD;

void CargaListaDoble(TListaD *);
void MuestraListaDoble(TListaD);
void esPalindroma(TListaD);

int main()
{
    TListaD LD;

    CargaListaDoble(&LD);
    MuestraListaDoble(LD);
    esPalindroma(LD);

    return 0;
}

void CargaListaDoble(TListaD *LD){
    char palabra[20];
    unsigned int i;
    PnodoD nuevo;

    (*LD).pri = NULL;
    (*LD).ult = NULL;

    printf("Ingrese la palabra que desea ingresar.\n");
    scanf("%s", palabra);

    for (i=0 ; i<strlen(palabra); i++){
        nuevo=(PnodoD)malloc(sizeof(nodoD));
        nuevo->letra = palabra[i];
        nuevo->sig = NULL;

        if (LD->pri == NULL){
            nuevo->ant = NULL;
            LD->pri = nuevo;
            LD->ult = nuevo;
        }
        else{
            nuevo->ant = LD->ult;
            LD->ult->sig = nuevo;
            LD->ult=nuevo;
        }
    }
}

void MuestraListaDoble(TListaD LD){
    PnodoD aux = LD.pri;

    while (aux != NULL){
        printf("%c\n", aux->letra);
        aux = aux->sig;
    }
}

void esPalindroma(TListaD LD){
    PnodoD primero=LD.pri, ultimo=LD.ult;

    while(primero->letra == ultimo->letra && primero != ultimo && primero->ant != ultimo){ //Cuando primero y ultimo apuntan a un mismo lugar se asume que las letras seran iguales
        primero = primero->sig;
        ultimo = ultimo->ant;
    }

    printf((primero == ultimo || primero->ant == ultimo) ? "Es Palindroma\n" : "No es Palindroma\n");

}
