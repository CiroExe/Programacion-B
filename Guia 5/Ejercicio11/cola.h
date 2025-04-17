
typedef struct {
    char legajo[9];
    int arribo, usoHorno;
}TElementoC;

typedef struct nodo {
    TElementoC empleado;
    struct nodo *sig;
}nodo;

typedef struct {
    nodo *pri, *ult;
}TCola;

void iniciaC(TCola *C);
void poneC(TCola *C, TElementoC empleado);
void sacaC(TCola *C, TElementoC *empleado);
int VaciaC(TCola C);
TElementoC consultaC(TCola C);

