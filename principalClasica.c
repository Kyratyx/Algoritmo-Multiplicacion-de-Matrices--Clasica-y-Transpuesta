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
* Función que realiza la multiplicación de matrices normal, utilizando punteros y las librerias omp y modulo.h
*/
void multiplicacion (int hilos,double *a, double *b, double *c, int N){

    int i,j,k;
    omp_set_num_threads(hilos); //Número de hilos en que se divide teniendo como referencia la variable de entrada
#pragma omp parallel
{
#pragma omp master // Se inicia el hilo maestro que ejecuta la acción establecida
    initMatrix(N,a,b,c);

#pragma omp for

     for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            double *auxA, *auxB, suma = 0;
            auxA = a+(i*N);
            auxB = b+j;
            for(k=0; k<N; k++, auxA++, auxB+=N){
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
    
    int N = (int) atof(argv[1]); argc--; argv++;


    int hilos = (int) atof(argv[1]); argc--; argv++;

    //Inicializar los punteros
    double *a;
    double *b;
    double *c;

    a = MEM_CHUNK;
    b = a + N*N;
    c = b + N*N;

    //Toma de tiempo para el proceso de la multiplicacion
    sample_start();
    multiplicacion(hilos, a,b,c,N);
    sample_stop();
    /* Imprime el tiempo de ejecucion del programa */
    sample_end();

/*
    impresion(N,a);

    printf("\n\n");
    impresion(N,b);
    printf("\n\n");
    impresion(N,c);
*/

}
