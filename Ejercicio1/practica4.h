#ifndef PRACTICA4_H
#define PRACTICA4_H

#include <stdio.h>
#include <stdlib.h>

double* capturaConjunto(int cardinalidad);

void imprimeConjunto(double* conjunto, int cardinalidad);

double* unionConjuntos(double* conjunto1, int cardinalidad1,
                       double* conjunto2, int cardinalidad2,
                       int *total);

void ejercicio1();

#endif

