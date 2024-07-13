#include <stdio.h>
#include <stdlib.h>
#include "memoria.h"

void vector_destruir(float **v, size_t n, size_t m){
	for(size_t i = 0; i < n; i++)
		free(v[i]);
	free(v);
}

float  **vector_crear(float **v, size_t n){
	size_t i;

	v = malloc(sizeof(float*)*n);
		if(v == NULL){
			free(v);
			return NULL;
		}

	for(i = 0; i < n; i++){
		v[i] = malloc(sizeof(float)*2);
		if(v[i] == NULL){
			vector_destruir(v, i, 2);
			return NULL;
		}
	}
	return v;
}

float **matriz_a_vector(const float m[][2], size_t n){
	float **aux = NULL;
	aux = vector_crear(aux, n);
	
	if(aux == NULL)
		return NULL;

	for(size_t i = 0; i < n; i++){
		for(int j = 0; j < 2; j++)
			 aux[i][j] = m[i][j];
	}
	return aux;
}
