#include <stdio.h>
#include <stdlib.h>
#define MAX 256

// Punto i

typedef struct {
    char codComercio[3], estado;
    unsigned int identificador_pedido;
    float importe;
}TElementoP;

typedef struct {
    TElementoP datos[MAX];
    int tope;
}TPila;

typedef struct nodito{
    unsigned int identificador_pedido;
    float importe;
    struct nodito *sig;
}nodito;
typedef nodito *Sublista;

typedef struct nodo{
    char codComercio[3];
    float importeComisiones;
    nodito *sublista;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

//----------------------------

int main()
{
    TLista L;
    TPila P;
    unsigned int idPedidoDesde, idPedidoHasta;
    char cod[3];

    CargaPila(&P);
    CargaLista(&L);
    TomaPedidos(&L, &P);
    printf("Ingrese codigo de comercio que desea buscar\n");
    scanf("%s", cod);
    printf("Ingrese el rango de pedidos que desea eliminar\n");
    scang("%u %u", &idPedidoDesde, &idPedidoHasta);
    EliminaPedidos(&L, idPedidoDesde, idPedidoHasta, cod);

    return 0;
}

//Punto ii

void TomaPedidos(TLista *L, TPila *P){
    TElementoP pedido;
    TPila aux;
    TLista nuevoLista, ant , act;
    nodito *nuevoSublista;


    while (!VaciaP(P)){
        SacaP(P, &pedido);
        if (pedido.estado == 'A'){
            //Declaro nuevo nodo para la lista simple.
            nuevoLista = (TLista)malloc(sizeof(nodo));
            strcpy(nuevoLista->codComercio, pedido.codComercio);
            nuevoLista->importeComisiones = pedido.importe*0.05;

            //Declaro nuevo nodito para la sublista.
            nuevoSublista = (nodito *)malloc(sizeof(nodito));
            nuevoSublista-> identificador_pedido = pedido.identificador_pedido;
            nuevoSublista-> importe = pedido.importe;

            if (*L == NULL || strcmp(pedido.codComercio, (*L)->codComercio) < 0){
                nuevoLista->sig = *L;
                nuevoLista->sublista = nuevoSublista;
                *L = nuevoLista;
            }
            else{
                ant = NULL;
                act = *L;
                while (act != NULL && strcmp(pedido.codComercio, act->codComercio) > 0){
                    ant = act;
                    act = act->sig;
                }

                if (strcmp(pedido.codComercio, act->codComercio) < 0){ // Si el comercio no existe insertarlo
                    ant->sig = nuevoLista;
                    nuevoLista->sig = act;
                    act = nuevoLista;
                }
                else{
                    act->importeComisiones += pedido.importe*0.05;
                    free(nuevoLista); //Como lo encontró no hace falta ocupar memoria para un nodo nuevo.
                }
                nuevoSublista->sig = act->sublista;
                act->sublista = nuevoSublista;
            }
        }
        else
            poneP(&aux, pedido); //Guardo los pendientes en una pila auxiliar.

    }
        while(!VaciaP(*aux)){
            sacaP(&aux, &pedido);
            poneP(P, pedido); //Vuelve a poner los pedidos pendientes en la pila original.

        }
}

void EliminaPedidos(TLista *L, unsigned int idPedidoDesde, unsigned int idPedidoHasta, char cod[]){
    TLista ant = NULL, aux = *L;
    Sublista antS, actS, elim;
    unsigned int contEliminados = 0;
    float acumEliminados = 0;


    while (aux != NULL && strcmp(cod, aux->codComercio) != 0){
        ant = aux;
        aux = aux->sig;
    }

    if (aux != NULL){
       antS = NULL;
       actS = aux->sublista;
       while (actS != NULL){
            if(actS->identificador_pedido >= idPedidoDesde && actS->identificador_pedido <= idPedidoHasta){
                elim=actS;
                if (antS == NULL)
                    aux->sublista = elim->sig;
                else
                    antS->sig = elim->sig;
                aux->importeComisiones -= elim->importe*0.05;
                contEliminados++;
                acumEliminados += elim->importe;
                actS = elim->sig;
                free(elim);
            }
            else {
                antS = actS;
                actS = actS->sig;
            }
       }

        if (aux->sublista == NULL){
            if (ant == NULL)
                *L = aux->sig;
            else
                ant->sig = aux->sig;
            free(aux)
        }
    }
    if (contEliminados != 0){
        printf("Cantidad de pedidos eliminados\t%u\n", contEliminados);
        printf("Importe promedio de los pedidos eliminados \t%.2f\n", (float)acumEliminados/contEliminados);
    }

}
