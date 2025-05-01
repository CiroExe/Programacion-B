// En este ejercicio solo voy a hacer lo que me pide la consigna directamente
//evitando la carga de datos en la lista original.

void CargaListas(TLista L, TListaC *LC, TListaD *LD){
    TLista aux = L;
    TListaC nuevoCircular;
    PnodoD nuevoDoble;

    *LC = NULL;

    LD->pri = NULL;
    LD->ult = NULL;

    while (aux != NULL){
        //Asigna memoria en el heap para el nuevo nodo que se va a insertar en la lista circular.
        nuevoCircular=(TListaC)malloc(sizeof(nodoC));
        nuevoCircular->elem = aux->elem;

        //Asigna memoria en el heap para el nuevo nodo que se va a insertar en la lista doble.
        nuevoDoble=(PnodoD)malloc(sizeof(nodoD));
        nuevoDoble->elem = aux->elem;
        nuevoDoble->sig = NULL;

        if (LD->pri == NULL && *LC == NULL){ //Primer nodo
            nuevoCircular->sig = nuevoCircular;
            *LC = nuevoCircular;


            nuevoDoble->ant = NULL;
            LD->pri = nuevoDoble;
            LD->ult = nuevoDoble;
        }
        else{
            nuevoCircular->sig = (*LC)->sig;
            (*LC)->sig=nuevoCircular;
            *LC=nuevoCircular;

            nuevoDoble->ant = LD->ult;
            LD->ult->sig = nuevoDoble;
            LD->ult = nuevoDoble;
        }

        aux = aux->sig;
    }
}
