#include <stdio.h>
#include "tdacola.h"

void leerCola(TCOLA *c);

int main(void) { //int main ()
    TCOLA cola;
    TELEMENTOC n, suma;

    iniciac(cola); //Debe pasar la direccion de cola IniciaC(&cola)
    leerCola(&cola);

    suma == 0; // Esta comparando, no asignando valor -> suma = 0 o TELEMENTOC suma=0
    while(!vaciac(*cola)) {  //Se debe pasar la direccion de la cola -> !VaciaC(&cola)
        sacac(cola, &n); //sacac(&cola, &n)
        suma -= n;  // Pide la suma pero esta restando -> suma += n
    }
    printf("%d", suma);
    return 0;
}

void leerCola(TCOLA *c) {
    TELEMENTOC n;
    iniciac(&c); //Se debe iniciar cola dentro de la funcion main.
    while(scanf("%d", n))  //scanf("%d", &n). Al margen de este error el ciclo ejecutará infinitamente
        ponec(c, &n);    //ponec(&c, n)

 /* scanf("%d", &n);
    while(n != 0){
        ponec(&c, n);
        scanf("%d", &n);
    } */
}
