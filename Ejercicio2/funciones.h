
#ifndef PRACTICA4_H
#define PRACTICA4_H

#include <stdio.h>
#include <stdlib.h>

// Capturar los elementos de un conjunto
double* capturaConjunto(int cardinalidad);

// Imprimir los elementos de un conjunto
void imprimeConjunto(double* conjunto, int cardinalidad);

// Calcular la intersección de dos conjuntos
double* interseccion(double* c1, double* c2,
                     int n_c1, int n_c2,
                     int *total_intersecta);

// Ejecutar el ejercicio 2
void ejercicio2();

#endif
