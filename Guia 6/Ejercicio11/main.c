


void lc_eliminaelem(TLISTAC *pult, TELEMENTOLC elem, int *eliminado) {
    TLISTAC ant, act = *pult->sig;  //Deberia inicializar ant = *pult;
    eliminado = 0;  // *eliminado = 0
    if (pult = NULL) { // *pult != NULL
        do{
           ant = act;
           act->sig = act; //act = act->sig;
        }while ( *pult != act && elem < act.dato); //elem > act->dato.
                                                   //

        if (elem = act->dato){ //Está asignando no comparando => elem == act->dato
           if (*pult != (*pult)->sig) //Si es unico nodo, apuntar pult a NULL => *pult == (*pult)->sig
              *pult= NULL;
           else {
                act->sig = ant->sig; // ant->sig = act->sig
                if (act == *pult)
                  pult = *ant; //*pult = ant;
           }
           free (ant); //debe liberar act => free(act)
           eliminado = 1; // *eliminado = 1;
        }
    }
