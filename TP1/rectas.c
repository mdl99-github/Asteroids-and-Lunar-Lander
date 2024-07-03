#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "rectas.h"
#include "memoria.h"
#include "config.h"

bool vector_esta_arriba(float **v, int n, float x, float y){
	int i;	
	
	for(i=0; i < n; i++){		
		float x0 = v[i][0];
		float x1 = v[i + 1][0];
		float y0 = v[i][1];
		float xv = v[i][0] - v[i+1][0];
		float yv = v[i][1] - v[i+1][1];
			
 		if(x0 <= x && x <= x1)
			if(((x - x0) * yv) / xv + y0 < y)
				return true;
	}
	return false;
}

static float num_aleatorio(float x_max, float x_min){
//Recibe los extremos de un intervalo, y genera y devuelve un valor aleatorio comprendido en este.
	float x_rand = ((float)rand()/(float)RAND_MAX)*(x_max - x_min) + x_min;
	return x_rand;
}

float altura_en_recta(float **v, float x, size_t n){
	size_t i;
	
	for(i = 0; i < n - 1; i++){
		if(x >= v[i][0] && x<=v[i + 1][0])
			break;
	}
	if(i < n -1)
	//Chequeo por si en alguna de las iteraciones del main la posicion en x de la nave excede el ancho de la pantalla.
		return (v[i + 1][1] - v[i][1])/(v[i + 1][0] - v[i][0])*(x - v[i][0]) + v[i][1];
	else return 0;
}

static void insertar_elemento(float **v, float x, float y, size_t n){
//Recibe un vector dinamico v de n coordenadas en R^2, y un par ordenado (x,y) y lo inserta en el vector de manera que este quede ordenado. El vector recibido
//que representa a una matriz, debe tener espacio en memoria para una fila mas de las que ya tiene asignadas. El vector recibido debe estar ordenado
//ascendientemente respecto a la coordenada x de cada punto.
	size_t i;
	
	for(i = 0; i < n; i++){
		if(x < v[i][0])
			break;
	}
	for(size_t j = n; j > i; j--){
		v[j][0] = v[j - 1][0];
		v[j][1] = v[j - 1][1];
	}
	v[i][0] = x;
	v[i][1] = y;
}
		
float **vector_densificar(float **v, size_t nv, size_t nn, float margen){
	size_t i;
	size_t j;	
	float x;
	float y;
	float altura;

	float **aux = NULL;
	aux = vector_crear(aux, nn);
	if(aux == NULL)
		return NULL;
	for(i = 0; i < nv; i++){
		for(j = 0; j < 2; j++)
			 aux[i][j] = v[i][j];
	}
	
	for(i = 0; i < nn - nv; i++){
		x = num_aleatorio(v[0][0], v[nv - 1][0]);
		altura = altura_en_recta(v, x, nv);
		y = num_aleatorio(altura + margen, altura - margen);
		insertar_elemento(aux, x, y, nv + i);
	}
	return aux;
}

float **crear_terreno (size_t *n) {
	*n = 0;

	const float terreno_estatico [][2] = {
		{0 , 100} ,
		{ -1 , VENTANA_ALTO * 2.0 / 3} ,
		{ VENTANA_ANCHO , 100}
	};

	size_t nt = 3;
	float ** terreno = matriz_a_vector(terreno_estatico, nt) ;
	if ( terreno == NULL ) 
		return NULL ;
// Asignamos la coordenada del medio aleatoriamente :
	terreno [1][0] = rand () % VENTANA_ANCHO ;

// Iterativamente densificamos 30 veces achicando el margen cada vez :
	for ( size_t i = 1; i < 30; i ++) {
		float ** aux = vector_densificar ( terreno , nt , 2 * ( i + 5) , 100 / i ) ;
		vector_destruir ( terreno , nt , 2) ;
		if ( aux == NULL ) return NULL ;
		terreno = aux ;
		nt = 2 * ( i + 5) ;
	}
	* n = nt ;
	return terreno ;
}