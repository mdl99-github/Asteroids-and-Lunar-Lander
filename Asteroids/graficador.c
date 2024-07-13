#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "graficador.h"
#include "puntos.h"
#include "memoria.h"
#include "config.h"

static char **nombres;
static uint16_t *elementos;
static sprites_t *coords;
static FILE *f;
static SDL_Renderer *renderer;

bool graficador_inicializar(const char *fn, SDL_Renderer *r){
	f = fopen(fn, "rb");
	if(f == NULL) return false;

	size_t i;

	size_t n = PAQUETE + 1;

	elementos = malloc(sizeof(uint16_t) * PAQUETE);

	coords = malloc(sizeof(sprites_t) * PAQUETE);

	nombres = malloc(sizeof(char *) * PAQUETE);
	for(i = 0; i < PAQUETE; i++){
		nombres[i] = malloc(10);
		if(nombres[i] == NULL) return false;
	}

	if(elementos == NULL || coords == NULL || nombres == NULL) return false;
	
	for(i = 0; fread(nombres[i], sizeof(char), 10, f) == 10; i++){
		fread(elementos + i , sizeof(uint16_t), 1, f);
		coords[i] = malloc(2 * 4 * elementos[i]);							
		fread(coords[i], 2 * 4 * elementos[i], 1, f);

		if(i == PAQUETE - 1){
			char **auxn = realloc(nombres, n);
			auxn[n- 1] = malloc(10);

			uint16_t *auxe = realloc(elementos, n);

			sprites_t *auxc = realloc(coords, n);

			if(auxn == NULL || auxe == NULL || auxc == NULL || auxn[n - 1] == NULL) return false;

			nombres = auxn;
			elementos = auxe;
			coords = auxc;			

			n++;
		}	
	}	

	renderer = r;

	return true;
}

void graficador_finalizar(){
	for(size_t i = 0; i < sizeof(nombres); i++)
		free(nombres[i]);
	free(nombres);
	free(elementos);
	free(coords);
	
	fclose(f);
	
	renderer = NULL;
}

bool graficador_dibujar(const char *nombre, float escala, float x, float y, double angulo){
	size_t j;
	int w;
	int h;
	for(j = 0; j < SPRITES; j++){	
		if(strcmp(nombre, nombres[j]) == 0)
			break;
	}
	if(j == SPRITES) return false;

	size_t tamagno = (size_t)elementos[j];
	float **dibujo = matriz_a_vector(coords[j], tamagno);

	vector_rotar(dibujo,tamagno, angulo);

	SDL_GetRendererOutputSize(renderer, &w, &h);

	for(size_t i = 0; i < tamagno - 1; i++)
	SDL_RenderDrawLine(
		renderer,
		dibujo[i][0] * escala + x,
		-dibujo[i][1] * escala + h  - y,
		dibujo[i+1][0] * escala + x,
		-dibujo[i+1][1] * escala + h - y
	);
	
	vector_destruir(dibujo, tamagno, 2);
	return true;
}
	
void graficador_ajustar_variables(float *x, float *y){			
	int w;
	int h;								
	SDL_GetRendererOutputSize(renderer, &w, &h);

	if(*x > w)
		*x = 0;
	if(*x < 0)
		*x = w;

	if(*y > h)
		*y = 0;
	if(*y < 0)
		*y = h;

}
















	
