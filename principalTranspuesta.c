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

/*
Se asigna la memoria estática
*/
#define SIZE (1024*1024*64*3)
static double MEM_CHUNK[SIZE];

/*
* Función que realiza la multiplicación de matrices transpuesta
*/
void multiplicacionT (int hilos,double *a, double *b, double *c, double *bT, int N){

    int i,j,k;
    omp_set_num_threads(hilos); //Número de hilos en que se divide teniendo como referencia la variable de entrada
#pragma omp parallel
{
#pragma omp master // Se inicia el hilo maestro que ejecuta la acción establecida
    initMatrixT(N,a,b,bT,c);

#pragma omp for

     for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            double *auxA, *auxB, suma = 0;
            auxA = a+(i*N);
            auxB = bT+(j*N);
            for(k=0; k<N; k++, auxA++, auxB++){
                suma += (*auxA * *auxB);
            }
            c[i*N+j] = suma;
        }
    }


}

}
/*
* Función principal donde se guarda los valores entregados por consola, se inicializa los punteros,
* se llama a las funciones de multiplicación e inicialización de matrices
*/
int main (int argc, char **argv){
    //Tamaño de la matriz
    int N = (int) atof(argv[1]); argc--; argv++;


    int hilos = (int) atof(argv[1]); argc--; argv++;
    //Inicializar punteros
    double *a;
    double *b;
    double *bT;
    double *c;

    a = MEM_CHUNK; //Apunta al primer elemento de MEM_CHUNK
    b = a + N*N;
    bT = b + N*N;
    c = bT + N*N;

    //Toma de tiempo para cuando comience con la multiplicación y la división de los procesos con hilos
    sample_start();
    multiplicacionT(hilos, a,b,c,bT,N);
    sample_stop();
    /* Imprime el tiempo de ejecucion */
    sample_end();


/*
    impresion(N,a);

    printf("\n\n");
    impresion(N,b);
    printf("\n\n");
    impresion(N,bT);
    printf("\n\n");
    impresion(N,c);
*/

}
