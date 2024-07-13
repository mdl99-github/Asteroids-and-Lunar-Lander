#ifndef MEMORIA_H
#define MEMORIA_H
#include <stdio.h>
#include <stdlib.h>

void vector_destruir(float **v, size_t n, size_t m);
//Recibe un puntero dinamico v que apunta a n punteros dinamicos, donde cada uno apunta  a m numeros del tipo float, y libera la memoria que ocupaba v.

float  **vector_crear(float **v, size_t n);
//Recive una matriz y crea para cada fila espacio en la memoria para un punto de dos coordenadas float.

float **matriz_a_vector(const float m[][2], size_t n);
//Recibe una matriz de R^(nx2) en donde cada fila es un punto en el plano, y crea y devuelve un vector dinamico que contenga los mismos elementos que ella.

#endif