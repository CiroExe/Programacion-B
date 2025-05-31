typedef int TElementoP;
typedef struct nodoP{
    TElementoP dato;
    struct nodoP *sig;
}nodoP;
typedef nodoP *TPila;

void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P, TElementoP *x);
TElementoP consultaP(TPila P);
int VaciaP(TPila P);
void IniciaP(TPila *P);
