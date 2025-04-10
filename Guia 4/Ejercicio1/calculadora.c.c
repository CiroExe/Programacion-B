#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

fraccion crear(int numerador, int denominador)
{
    fraccion aux;
    aux.numerador = numerador;
    aux.denominador = denominador;
    return aux;
}

int mcd(int dividendo, int divisor)
{
    int resto;

    while (divisor != 0)
    {
        resto= dividendo % divisor;
        dividendo=divisor;
        divisor=resto;
    }
    return dividendo;
}


int numerador (fraccion f)
{
    return f.numerador;
}

int denominador (fraccion f)
{
    return f.denominador;
}

fraccion sumar(fraccion f1, fraccion f2)
{
    return crear(f1.numerador*f2.denominador + f2.numerador*f1.denominador,f1.denominador*f2.denominador);
}

fraccion restar (fraccion f1, fraccion f2)
{
    return crear(f1.numerador * f2.denominador - f2.numerador * f1.denominador, f1.denominador * f2.denominador);
}

fraccion multiplicar (fraccion f1, fraccion f2)
{
    return crear(f1.numerador * f2.numerador, f1.denominador * f2.denominador);
}

fraccion dividir (fraccion f1, fraccion f2)
{
    return crear(f1.numerador*f2.denominador, f2.numerador*f1.denominador);
}

fraccion simplificar (fraccion f)
{
    return crear(f.numerador/mcd(f.numerador, f.denominador), f.denominador/mcd(f.numerador, f.denominador));
}


int iguales(fraccion f1, fraccion f2)
{
    fraccion fraccionSimplificada1, fraccionSimplificada2;

    fraccionSimplificada1 = simplificar(f1);
    fraccionSimplificada2 = simplificar (f2);

    return (fraccionSimplificada1.numerador == fraccionSimplificada2.numerador && fraccionSimplificada1.denominador == fraccionSimplificada2.denominador) ? 1 :0;
}
