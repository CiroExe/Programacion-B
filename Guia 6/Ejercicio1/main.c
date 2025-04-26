#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    char caracter;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

void CargaLista(TLista *);
void MuestraLista(TLista);
void cantVocales(TLista, unsigned int *);
int estaOrdenada(TLista);
void elimina(TLista *, unsigned int);

int main()
{
    TLista L;
    unsigned int P,cont=0;


    CargaLista(&L);
    //Inciso a
    MuestraLista(L);
    //Inciso b
    cantVocales(L, &cont);
    printf("Cantidad de vocales %u\n", cont);
    //Inciso c
    if (estaOrdenada(L))
        printf("Esta ordenada\n");
    else
        printf("Esta desordenada\n");
    //Inciso d
    printf("Ingrese posicion que desea eliminar\n");
    scanf("%u", &P);
    elimina(&L, P);
    MuestraLista(L);

    return 0;
}

void CargaLista(TLista *L){
    char car;
    TLista aux, nuevo;

    *L=NULL;

    printf("Ingrese caracter(0 para finalizar)\n");
    scanf(" %c", &car);
    while (car != '0'){
        nuevo=(TLista)malloc(sizeof(nodo));
        nuevo->caracter=car;
        nuevo->sig=NULL ;
        if (*L == NULL)
            *L=nuevo;
        else{
            aux=*L;
            while(aux->sig != NULL)
                aux=aux->sig;
            aux->sig=nuevo;
        }

        printf("Ingrese caracter(0 para finalizar)\n");
        scanf(" %c", &car);
    }
}

void MuestraLista(TLista L){
    TLista aux;

    aux=L;
    while (aux != NULL){
        printf(" %c\n", aux->caracter);
        aux=aux->sig;
    }
}

int esVocal(char caracter){
    return (toupper(caracter) == 'A' || toupper(caracter)  == 'E' || toupper(caracter)  == 'I' || toupper(caracter)  == 'O' || toupper(caracter)  == 'U');
}

void cantVocales(TLista L, unsigned int *cont){
    TLista aux;

    aux=L;
    while(aux != NULL){
        if (esVocal(aux->caracter))
            (*cont)++;
        aux=aux->sig;
    }
}

int estaOrdenada(TLista L) {
    TLista ant = L;
    TLista act = L->sig;

    if (L == NULL || L->sig == NULL)
        return 1; // Vacía o con un solo nodo: se considera ordenada


    while (act != NULL) {
        if (ant->caracter > act->caracter)
            return 0; // No está ordenada
        ant = act;
        act = act->sig;
    }

    return 1; // Está ordenada
}

void elimina(TLista *L, unsigned int P){
    int cont = 1;
    TLista aux = *L, ant=NULL;

    while (cont < P){
        ant = aux;
        aux = aux->sig;
        cont++;
    }

    if (ant == NULL) { // Elimina el primer nodo
        *L = aux->sig;
    } else {
        ant->sig = aux->sig;
    }

    free(aux);
}


