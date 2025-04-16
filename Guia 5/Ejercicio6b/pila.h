typedef int TElementoP;

typedef struct nodo {
    TElementoP dato;
    struct nodo *sig;
}nodo;

typedef nodo *TPila;

void iniciaP(TPila *P);
void poneP(TPila *P, TElementoP dato);
void sacaC(TPila *P, TElementoP *dato);
int VaciaP(TPila P);
TElementoP consultaP(TPila P);

