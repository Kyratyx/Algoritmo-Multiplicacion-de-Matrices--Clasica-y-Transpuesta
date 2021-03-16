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
#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED

/*Funciones para la toma de tiempos de ejecución del programa*/
extern void sample_start();
extern void sample_stop();
extern void sample_end();


void initMatrixT(int N, double *a, double *b, double *bT, double *c);
void initMatrix(int N, double *a, double *b, double *c);
void impresion(int N, double *matriz);
#endif