#include <stdio.h>
#include <SDL2/SDL.h>
#include "caracteres.h"
#include "config.h"
#include "dibujado.h"

void dibujar_caracteres(char * frase, int altura, int largo, int factor, int espacio, SDL_Renderer *renderer){
	int k = 0;
	size_t n = strlen(frase);
	for(size_t i = 0; i < n ; i++){
		size_t tam = caracter_a_tamagno(frase[i]);
		char_t letra = caracter_a_vector(frase[i]);
		for(size_t j = 0; j < tam - 1; j++){
			SDL_RenderDrawLine(
			renderer,
				letra[j][0] * factor + largo + k,
				-letra[j][1] * factor + altura,
				letra[j+1][0] * factor + largo + k,
				-letra[j+1][1] * factor + altura
			);
		}
	k += espacio;
	} 
}

void dibujar_nave(float **nave, size_t tamagno,float **chorro, SDL_Renderer *renderer){
	for(int i = 0; i < tamagno - 1; i++)
		SDL_RenderDrawLine(
			renderer,
			nave[i][0] + NAVE_X_INICIAL,
			-nave[i][1] + VENTANA_ALTO  - NAVE_Y_INICIAL,
			nave[i+1][0] + NAVE_X_INICIAL,
			-nave[i+1][1] + VENTANA_ALTO - NAVE_Y_INICIAL
		);

	for(int i = 0; i < 3 - 1; i++)
		SDL_RenderDrawLine(
			renderer,
			chorro[i][0] + NAVE_X_INICIAL,
			-chorro[i][1] + VENTANA_ALTO - NAVE_Y_INICIAL,
			chorro[i+1][0] + NAVE_X_INICIAL,
			-chorro[i+1][1] + VENTANA_ALTO - NAVE_Y_INICIAL
		);

}

void dibujar_terreno(float **terreno, size_t tamagno, SDL_Renderer *renderer){
	for(int i = 0; i < tamagno - 1; i++)
		SDL_RenderDrawLine(
			renderer,
			terreno[i][0],
			-terreno[i][1] + VENTANA_ALTO,
			terreno[i+1][0],
			-terreno[i+1][1] + VENTANA_ALTO 
		);
}