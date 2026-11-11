#include "funciones.h"

double *capturaConjunto(int cardinalidad){

    // Reservar memoria para el conjunto
    double* conjunto = (double*)malloc(cardinalidad * sizeof(double));

    // VERIFICAR SI LA MEMORIA SE RESERVÓ CORRECTAMENTE
    if (conjunto == NULL) {
        printf("Error al reservar memoria para el conjunto.\n");
        return NULL; // Retornar NULL si no se pudo reservar memoria
    }
    // Capturar los elementos del conjunto
    printf("Ingrese los elementos del conjunto:\n");  
    for (int i = 0; i < cardinalidad; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%lf", conjunto+i);
    }
    return conjunto;
}

void imprimeConjunto(double* conjunto, int cardinalidad) {
    printf("El conjunto es: { ");

    for (int i = 0; i < cardinalidad; i++) {
        printf("%.2lf ", *(conjunto+i));
    }

    printf("}\n");
}

double* interseccion(double* c1, double* c2,
                     int n_c1, int n_c2,
                     int *total_intersecta) {

    int cardinalidadResultado;

    if (n_c1 < n_c2) {
        cardinalidadResultado = n_c1;
    } else {
        cardinalidadResultado = n_c2;
    }

    double *c_interseccion = (double*) calloc(cardinalidadResultado, sizeof(double));

    if (c_interseccion == NULL) {
        printf("Error al reservar memoria para la interseccion.\n");
        return NULL;
    }

     int k = 0;

    for (int i = 0; i < n_c1; i++) {

        int encontrado = 0;

        for (int j = 0; j < n_c2; j++) {

            if (*(c1+i) == *(c2+j)) {
                encontrado = 1;
            }

        }
        for (int x = 0; x < k; x++) {

        if (*(c_interseccion+x) == *(c1+i)) {
        encontrado = 0;
        }

        }
        if (encontrado == 1) {
            *(c_interseccion+k) = *(c1+i);
            k++;
        }   

    }
    *total_intersecta = k;
    return c_interseccion;

}

void ejercicio2() {

    int n_c1, n_c2;
    int total_intersecta;

    double *c1;
    double *c2;
    double *c_interseccion;

    printf("Ingrese la cardinalidad del conjunto 1: ");
    scanf("%d", &n_c1);
    if (n_c1 <= 0) {
    printf("La cardinalidad debe ser mayor que cero.\n");
    return;
    }

    c1 = capturaConjunto(n_c1);
    if (c1 == NULL) {
    return;
    }   

    printf("Ingrese la cardinalidad del conjunto 2: ");
    scanf("%d", &n_c2);

    if (n_c2 <= 0) {
    printf("La cardinalidad debe ser mayor que cero.\n");
    free(c1);
    return;
    }

    c2 = capturaConjunto(n_c2);
    if (c2 == NULL) {
    free(c1);
    return;
    }

    c_interseccion = interseccion(c1, c2, n_c1, n_c2, &total_intersecta);
    
    if (c_interseccion == NULL) {
    free(c1);
    free(c2);
    return;
    }

    printf("\nPrimer conjunto:\n");
    imprimeConjunto(c1, n_c1);

    printf("\nSegundo conjunto:\n");
    imprimeConjunto(c2, n_c2);

    printf("\nInterseccion de los conjuntos:\n");
    imprimeConjunto(c_interseccion, total_intersecta);

    free(c1);
    free(c2);
    free(c_interseccion);

}
