#include <stdio.h>
#include <stdlib.h>

void main(){
    int i, arr[N] = {4,8,9,60}; //No es necesario asignar una dimension a un vector declarado como constante. La dimension de un vector constante lo deduce el interprete.
    TLISTA lista=NULL, pult=NULL, act, ant, nuevo;


    cargarLista(&lista);
    printf("\nLista Original\n");
    muestra(&lista); //No deberia pasar la direccion de la lista, ya que no se va a modificar, solo va a mostrarse ( muestra(lista)).

    act = lista;
    ant = NULL;        2 5 7 8 9 12  act->n= 7.
    for(i=0; i<=N; i++) { // i < N !!!!
        while(act!=NULL && arr[i] <= act->n) {  //Se quieren ingresar datos ordenados a la lista entonces
            act = ant;    //ant=act;            //cuando compara arr[i] <= act -> n esta comparando con su igual.
                                                //Deberia comparar arr[i] > act -> n (Ejecutar mientras act sea distinto de null y 7
                                                //y el elemento del array sea menor al elemento actual de la lista.

            act = act.sig;   //Estamos trabajando con listas dinamicas => act = act -> sig.
        }
        *nuevo = (TLISTA)malloc(sizeof(NODO));  //TLISTA ya es un puntero a nodo => nuevo = (TLISTA) malloc(sizeof(NODO)).
        nuevo->n = arr[i-1];  //nuevo -> n = arr[i]
        if(ant = NULL) { // ant == NULL. Está asignando, no comparando.
            nuevo->sig = lista;
            *lista = &nuevo;  //Sin el ampersand
        }
        else {
            nuevo->sig = ant;
            ant->sig = &nuevo; //Sin el ampersand
        }
        act = nuevo->sig;
    }
    printf("\nLista Resultado\n");
    muestra(&lista);   // muestra(lista).
}
