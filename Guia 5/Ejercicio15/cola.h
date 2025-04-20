//Voy a utilizar cola estatica solo para practicar ya que los ultimos ejercicios los hice con colas y pilas dinamicas.

#define MAX 256

typedef struct {
    char apellido[20], nombre[20];
}TElementoC;

typedef struct {
    TElementoC competidores[MAX];
    int pri, ult;
}TCola;

void iniciaC(TCola *C);
void poneC(TCola *C, TElementoC competidor);
void sacaC(TCola *C, TElementoC *competidor);
int VaciaC(TCola C);
