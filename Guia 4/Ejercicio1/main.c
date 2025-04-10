#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main()
{
    int num, den;
    fraccion fraccion1, fraccion2, fraccionAux;
    printf("Ingrese numerador 1\n");
    scanf("%d", &num);
    printf("Ingrese denominador 1\n");
    scanf("%d", &den);
    fraccion1 = crear(num, den);

    printf("Ingrese numerador 2\n");
    scanf("%d", &num);
    printf("Ingrese denominador 2\n");
    scanf("%d", &den);
    fraccion2 = crear(num, den);

    printf("Fraccion 1 -->\t %d/%d\n", numerador(fraccion1), denominador(fraccion1));
    printf("Fraccion 2 -->\t %d/%d\n", numerador(fraccion2), denominador(fraccion2));


    fraccionAux = simplificar(sumar(fraccion1, fraccion2));
    printf("Suma entre fraccion 1 y fraccion 2 -->\t %d/%d\n",fraccionAux.numerador, fraccionAux.denominador);

    fraccionAux = simplificar(restar(fraccion1, fraccion2));
    printf("Resta entre fraccion 1 y fraccion 2 -->\t");
    printf((fraccionAux.numerador != 0 )? ("%d/%d\n",fraccionAux.numerador, fraccionAux.denominador) : "0\n" );

    fraccionAux= multiplicar(fraccion1, fraccion2);
    printf("Multiplicacion entre fraccion 1 y fraccion 2 -->\t %d/%d\n",fraccionAux.numerador, fraccionAux.denominador);

    fraccionAux = dividir(fraccion1, fraccion2);
    printf("Division entre fraccion 1 y fraccion 2 -->\t %d/%d\n", fraccionAux.numerador, fraccionAux.denominador);

    fraccionAux = simplificar(fraccion1);
    printf("Fraccion 1 simplificada -->\t %d/%d\n", fraccionAux);

    fraccionAux=simplificar(fraccion2);
    printf("Fraccion 2 simplificada -->\t %d/%d\n",fraccionAux);

    printf(iguales(fraccion1, fraccion2) ? "Las fracciones son iguales":"Las fracciones NO son iguales");


    return 0;
}
