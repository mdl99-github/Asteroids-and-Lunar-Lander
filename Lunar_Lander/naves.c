#include <SDL2/SDL.h>
#include "naves.h"
#include "dibujado.h"
#include "cinematica.h"
#include "puntos.h"
#include "memoria.h"

const float nave_grande[28][2] = {
	{-3, -5},
	{-6, -2},
	{-6, 2},
	{-2, 6},
	{2, 6},
	{6, 2},
	{6, -2},
	{3, -5},
	{6, -5},
	{6, -8},
	{8.5, -13},
	{10, -13},
	{7, -13},
	{8.5, -13},
	{6, -8},
	{3, -8},
	{5, -12},
	{-5, -12},
	{-3, -8},
	{3, -8},
	{-6, -8},
	{-8.5, -13},
	{-10, -13},
	{-7, -13},
	{-8.5, -13},
	{-6, -8},
	{-6, -5},
	{6, -5},
};

const float nave_chica[17][2] = {
	{-9, -11},
	{-6, -6},
	{-2, -6},
	{-6, -2},
	{-6, 2},
	{-2, 6},
	{2, 6},
	{6, 2},
	{6, -2},
	{2, -6},
	{-2, -6},
	{-1.5, -6},
	{-4, -9.5},
	{4, -9.5},
	{1.5, -6},
	{6, -6},
	{9, -11},
};

void inicializar_nave(const float nave[][2],size_t tamagno, const float chorro[][2], float x, float y, float vx, float vy, double angulo, int potencia, SDL_Renderer *renderer){
	float **nave_din = matriz_a_vector(nave, tamagno);
	float **chorro_din = matriz_a_vector(chorro, 3);

	//Ajusto el chorro de acuerdo con la potencia.
	chorro_din[1][1] -= sin(NAVE_ANGULO_INICIAL)*potencia;
	chorro_din[1][0] -= cos(NAVE_ANGULO_INICIAL)*potencia;

	vector_rotar(nave_din, tamagno, angulo);
	vector_trasladar(nave_din, tamagno, x, y);

	vector_rotar(chorro_din, 3, angulo);
	vector_trasladar(chorro_din, 3, x, y);

	dibujar_nave(nave_din, tamagno, chorro_din, renderer);

	vector_destruir(nave_din, tamagno, 2);
	vector_destruir(chorro_din, 3, 2);
}
























	

