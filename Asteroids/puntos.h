#ifndef PUNTOS_H
#define PUNTOS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void vector_rotar(float **v, int n, double rad);
//Recibe una matriz con n coordenadas en R^2, y un angulo en radianes y rota cada punto respecto al origen.
 
void vector_trasladar(float **v, int n ,float dx ,float dy);
//Recibe una matriz con n coordenadas en R^2, dos numeros dx y dy, y le suma a cada punto dx en x y dy en y.

#endif