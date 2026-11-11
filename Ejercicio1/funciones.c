#include "practica4.h"

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

     double* unionConjuntos(double* conjunto1, int cardinalidad1, double* conjunto2, int cardinalidad2, int *total) {

         int cardinalidadResultado = cardinalidad1+cardinalidad2;
         double *resultado = (double*) calloc(cardinalidadResultado, sizeof(double));

             if (resultado == NULL) {
        printf("Error al reservar memoria para la union.\n");
        return NULL;
            }

        for (int i = 0; i < cardinalidad1; i++) {
        *(resultado+i) = *(conjunto1+i);
        }

        int k = cardinalidad1;

            
        for (int j = 0; j < cardinalidad2; j++) {

            int encontrado = 0;

            
            for (int i = 0; i < k; i++) {

                if (*(resultado+i) == *(conjunto2+j)) {
                encontrado = 1;
                }
            }

            
            if (encontrado == 0) {
                *(resultado+k) = *(conjunto2+j);
                k++;
            }
        }

        *total = k;
        return resultado;
    }



    void ejercicio1(){

        int cardinalidad1, cardinalidad2, cardinalidadUnion;
        double *conjunto1, *conjunto2, *conjuntoUnion, *capturaConjunto();

        printf("Ingrese la cardinalidad del conjunto 1: ");
        scanf("%d", &cardinalidad1);
        conjunto1 = capturaConjunto(cardinalidad1);
       

        printf("Ingrese la cardinalidad del conjunto 2: ");
        scanf("%d", &cardinalidad2);
        conjunto2 = capturaConjunto(cardinalidad2);
    

         conjuntoUnion = unionConjuntos(conjunto1, cardinalidad1, conjunto2, cardinalidad2, &cardinalidadUnion);


        imprimeConjunto(conjuntoUnion, cardinalidadUnion);

        free(conjunto1);
        free(conjunto2);
        free(conjuntoUnion);




    }

