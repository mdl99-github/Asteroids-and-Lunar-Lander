#ifndef CINEMATICA_H
#define CINEMATICA_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double computar_velocidad(double vi,double a, double dt);
//Recibe la velocidad y aceleracion instantanea de un cuerpo y el paso temporal dt, y devuleve la velocidad al proximo instante.

double computar_posicion(double pi, double vi, double dt);
//Recibe la posicion y velocidad actual de un cuerpo y el paso temporal dt, y devuelve la posicion al proximo instante.

#endif