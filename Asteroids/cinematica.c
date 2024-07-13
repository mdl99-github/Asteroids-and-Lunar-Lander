#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cinematica.h"

double computar_velocidad(double vi,double a, double dt)
{
	return a*dt+vi;
}
double computar_posicion(double pi, double vi, double dt)
{
	return vi*dt+pi;
}