/***
*
* Universidad Sergio Arboleda
* Escuela de Ciencias Exactas e Ingeniería
* Ciencias de la Computación e Inteligencia Artificial
* Autores: Juan Pablo Mora- Johan Villalba - Jairo Caro
* Correos: juan.mora03@correo.usa.edu.co, johan.villalba01@correo.usa.edu.co, jairo.caro01@correo.usa.edu.co
* Fecha: 14/MARZO/2021
*
* Título: Multiplicación de Matrices Clásica y Transpuesta
*
***/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "modulo.h"
#include <sys/time.h>
#include <time.h>
#include <math.h>


struct timeval start, end;

/* Punto de inicio de la medicion de tiempo*/
void sample_start(){
        gettimeofday(&start, NULL);
}
/* Punto de finalizacin del tiempo */
void sample_stop(){
        gettimeofday(&end, NULL);

}

/* Impresion de toma tiempo*/
void sample_end(){
  /*printf("\nTiempo de ejecucion de la multiplicacion:");*/
  printf("El tiempo fue de : %ld  Microsegundos\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
}

/*
* Función para la inicialización de matrices para la Transpuesta, se recibe de entrada los punteros y
* los inicializa con los valores establecidos
*/

void initMatrixT(int N, double *a, double *b, double *bT, double *c){
    int i,j;

    for(i = 0; i<N; i++){
        for(j = 0; j<N; j++){
           a[j+i*N] = 3.1*(j-i);
           if (j % 2 == 0){
                b[j+i*N] = 4.1*(j+i);

           }else{
               b[j+i*N] = 6.1*(j+i);
           }
           c[j+i*N] = 5.1;
        }
    }
    //Inicializar el puntero que es la transpuesta de b
    for(i = 0; i<N; i++){
        for(j = 0; j<N; j++){
           bT[j+i*N] = b[i+j*N];
        }
    }

}
/*
* Función para la inicialización de matrices para la Clasica, se recibe de entrada los punteros y
* los inicializa con los valores establecidos
*/
void initMatrix(int N, double *a, double *b, double *c){
    int i,j;

    for(i = 0; i<N; i++){
        for(j = 0; j<N; j++){
           a[j+i*N] = 3.1*(j-i);
           if (j % 2 == 0){
                b[j+i*N] = 4.1*(j+i);

           }else{
               b[j+i*N] = 6.1*(j+i);
           }
           c[j+i*N] = 5.1;
        }
    }

}

/*
* Función que imprime las matrices correspondientes
*/
void impresion(int N, double *matriz){
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%f ", matriz[j+i*N]);
        }
         printf("\n");
    }
}

