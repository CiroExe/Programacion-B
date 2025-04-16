#define MAX 100

typedef char TElementoP;
typedef struct {
    TElementoP C[MAX];
    int tope;
} TPila;

void iniciaP(TPila *P);
void poneP(TPila *P, TElementoP car);
void sacaP(TPila *P, TElementoP *car);
int VaciaP(TPila P);
