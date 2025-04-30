#include <stdio.h>
#include <stdlib.h>

//Declaracion de tipos para Listas Doblemente Enlazadas.
typedef struct nodoD{
    char caracter;
    struct nodoD *ant, *sig;
}nodoD;
typedef nodoD *PnodoD;

typedef struct {
    PnodoD pri, ult; //nodoD *pri, *ult
}TListaD;

//Declaracion de tipos para Listas Circulares.
typedef struct nodoC{
    char caracter;
    struct nodoC *sig;
}nodoC;
typedef nodoC *TListaC;


void CargaListaDoble(TListaD *);
void MuestraListaDoble(TListaD);
unsigned int cantVocales(TListaD);
int estaOrdenada(TListaD);
void eliminaP(TListaD *, unsigned int );
void CargaListaCircular(TListaC *);
void MuestraListaCircular(TListaC);
unsigned int cantVocalesCircular(TListaC);
int estaOrdenadaCircular(TListaC);
void eliminaK(TListaC *, unsigned int);

int main()
{
    TListaD LD;
    TListaC LC;
    unsigned int P, K;


    //Inciso A
    CargaListaDoble(&LD);
    MuestraListaDoble(LD);
    printf(estaOrdenada(LD) ? "Esta ordenda\n":"No esta ordenada\n");
    printf("%u nodos poseen vocales\n", cantVocales(LD));
    printf("Ingrese posicion que desea eliminar\n");
    scanf("%u", &P);
    eliminaP(&LD, P);
    MuestraListaDoble(LD);
    printf("\n\n\n");

    //Inciso B
    CargaListaCircular(&LC);
    MuestraListaCircular(LC);
    printf("%u nodo poseen vocales\n", cantVocalesCircular(LC));
    printf(estaOrdenadaCircular(LC)? "Esta ordenada\n" : "No esta ordenada\n");
    printf("Ingrese posicion que desea eliminar\n");
    scanf("%u", &K);
    eliminaK(&LC, K);
    MuestraListaCircular(LC);



    return 0;
}


void CargaListaDoble(TListaD *LD){
    char car;
    PnodoD nuevoDato;

    LD->pri = NULL;
    LD->ult = NULL;
    printf("Ingrese caracter('0 para finalizar')\n");
    scanf(" %c", &car);
    while(car != '0'){
        nuevoDato=(nodoD *)malloc(sizeof(nodoD));
        nuevoDato->caracter = car;
        nuevoDato->ant = NULL;
        nuevoDato->sig = LD->pri;

        if (LD->pri == NULL)
            LD->ult = nuevoDato;
        else
            LD->pri->ant=nuevoDato;

        LD->pri = nuevoDato;

        printf("Ingrese caracter('0 para finalizar')\n");
        scanf(" %c", &car);
    }
}

void MuestraListaDoble(TListaD LD){
    PnodoD aux;

    aux=LD.pri;
    while (aux != NULL){
        printf("%c\n", aux->caracter);
        aux = aux->sig;
    }
    printf("\n");
    aux=LD.ult;
    while(aux != NULL){
        printf("%c\n", aux->caracter);
        aux = aux->ant;
    }
}

int esVocal(char caracter){
    return (toupper(caracter) == 'A' || toupper(caracter) == 'E' || toupper(caracter) == 'I' || toupper(caracter) == 'O' || toupper(caracter) == 'U');
}

unsigned int cantVocales(TListaD LD){
    unsigned int cont=0;


    while(LD.ult != NULL){
        if (esVocal(LD.ult->caracter))
            cont++;
        LD.ult = LD.ult->ant;
    }
    return cont;
}

int estaOrdenada(TListaD LD){
    PnodoD aux;

    aux = LD.ult;

    while(aux != NULL && aux->ant != NULL){
        if (aux->caracter >aux->ant->caracter)
            return 0;
        aux = aux->ant;
    }

    return 1;
}

void eliminaP(TListaD *LD, unsigned int P){
    int cont=1;
    PnodoD aux;

    aux = LD->pri;

    while(aux != NULL && cont != P){
        aux = aux->sig;
        cont++;
    }

    if (aux != NULL){
        printf("Elimino %c\n", aux->caracter);
         if (LD->pri == aux){// Pregunta si es el primero
            LD->pri = aux->sig;
            if (LD->pri != NULL) // Pregunta si el nuevo pri no es null, si cumple hace apuntar el anterior a NULL
                LD->pri->ant=NULL;
         }
         else if(LD->ult == aux){ //Pregunta si es el ultimo
                    LD->ult = aux->ant;
                    LD->ult->sig= NULL;
               }
               else{
                    aux->ant->sig = aux->sig;
                    aux->sig->ant = aux->ant;
               }
        free(aux);
    }
}

void CargaListaCircular(TListaC *LC){
    TListaC nuevoDato;
    char car;

    *LC = NULL;

    printf("Ingrese caracter ('0' para finalizar)\n");
    scanf(" %c", &car);

    while (car != '0'){
        nuevoDato = (TListaC)malloc(sizeof(nodoC));
        nuevoDato->caracter = car;

        if (*LC == NULL){
            *LC = nuevoDato;
            nuevoDato->sig = nuevoDato;
        }
        else{
            nuevoDato->sig = (*LC)->sig;
            (*LC)->sig = nuevoDato;
            *LC = nuevoDato;
        }

        printf("Ingrese caracter ('0' para finalizar)\n");
        scanf(" %c", &car);
    }
}

void MuestraListaCircular(TListaC LC){ //Supongo que siempre esta llena.
    TListaC aux = LC->sig;

    do{
        printf("%c\n", aux->caracter);
        aux = aux->sig;
    }while (aux != LC->sig);
}

unsigned int cantVocalesCircular(TListaC LC){
    unsigned int cont=0;
    TListaC aux = LC->sig;

    do{
        if (esVocal(aux->caracter))
        cont++;
        aux = aux->sig;

    }while(aux != LC->sig);

    return cont;
}

int estaOrdenadaCircular(TListaC LC){
    TListaC aux = LC->sig;

    do{
        if (aux->caracter > aux->sig->caracter)
            return 0;
        aux = aux->sig;
    }while (aux != LC);

    return 1;
}

void eliminaK(TListaC *LC, unsigned int K){
    TListaC act=(*LC)->sig, ant=*LC;
    unsigned int cont=1;

    while (act != *LC && cont < K){
        ant = act;
        act = act->sig;
        cont ++;
    }

    if (act == *LC){ //Si es a donde apunta LC preguntar si es unico nodo
        if (act == (*LC)->sig)
            *LC = NULL;
        else
            *LC = act->sig;
    }
    else
        ant->sig = act->sig;

    free(act);
}
