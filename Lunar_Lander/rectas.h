#ifndef RECTAS_H
#define RECTAS_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool vector_esta_arriba(float **v, int n, float x, float y);
//Recibe una matriz con n coordenadas en R^2, ordenadas ascendientemente respecto a x y un punto (x,y) y devuelve verdadero si ese punto se encuenrtra arriba del segmento delimitado
//por (x0,y0) y (x1,y1) con x0 <= x <= x1.

float altura_en_recta(float **v, float x, size_t n);
//Recibe un puntero a n vectores de 2 coordenadas ordenadas ascendientemente respecto a su primera componente, y un numero x, y devuelve la y que le corresponde
//tal que x pertenezca al segmento entre (x0,y0) y (x1,y1) (que pertenecen al puntero a vectores) siendo x0 <= x <= x1.

float **vector_densificar(float **v, size_t nv, size_t nn, float margen);
//Recibe un vector dinamico v de nv coordenadas en R^2 y devuelve un nuevo vector dinamico con nn coordenadas generadas dentro de +/- margen respecto a los segmentos
//que forman los puntos en el plano. El vector devuelto esta ordenado ascendientemente respecto a la coordenada x de cada punto. El vector recibido debe estar 
//ordenado de la misma manera.

float **crear_terreno(size_t * n);
// Devuelve un vector que representa el terreno y su tamagno n.

#endif