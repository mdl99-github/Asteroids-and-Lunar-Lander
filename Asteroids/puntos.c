#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "puntos.h"

void vector_rotar(float **v, int n, double rad){
	int i;
	double x;
	double y;
	double seno = sin(rad);
	double coseno = cos(rad);
	
	for(i=0;i<n;i++){
		x = v[i][0] * coseno - v[i][1] * seno;
		y = v[i][0] * seno+v[i][1] * coseno;
		
		v[i][0] = x;
		v[i][1] = y;
	}
}

void vector_trasladar(float **v, int n ,float dx ,float dy){
	int i;
	for(i=0;i<n;i++){
		v[i][0] += dx;
		v[i][1] += dy;
	}
}
