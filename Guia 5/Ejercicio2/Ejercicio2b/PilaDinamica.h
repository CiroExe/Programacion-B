typedef char TElementoP;

typedef struct nodo {
    TElementoP dato;
    struct nodo *sig;
} nodo;

typedef nodo *TPila;

void iniciaP(TPila *P);
void poneP(TPila *P, TElementoP car);
void sacaP(TPila *P, TElementoP *car);
int VaciaP(TPila P);


