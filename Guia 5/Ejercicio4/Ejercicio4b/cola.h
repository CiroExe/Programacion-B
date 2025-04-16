#define MAX 256

typedef int TElementoC;

typedef struct {
    TElementoC V[MAX];
    int pri,ult;
} TCola;

void iniciaC(TCola *C);
void poneC(TCola *C, TElementoC dato);
void sacaC(TCola *C, TElementoC *dato);
int VaciaC(TCola C);
TElementoC consultaC(TCola C);


