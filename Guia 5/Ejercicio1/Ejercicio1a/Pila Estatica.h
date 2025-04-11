#define MAX 100

typedef int TElementoP;
typedef struct {
    TElementoP A[MAX];
    int tope;
} TPila;

void IniciaP(TPila *P);
void poneP(TPila *P, TElementoP dato);
void sacaP(TPila *P, TElementoP *dato);
TElementoP consultaP(TPila P);
int vaciaP(TPila P);
