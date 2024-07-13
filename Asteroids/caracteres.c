#include "caracteres.h"
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

const int caracter_a[7][2] = {
	{0, 0},
	{0, 4},
	{2, 6},
	{4, 4},
	{4, 0},
	{4, 2},
	{0, 2}
};

const int caracter_b[12][2] = {
	{0, 3},
	{0, 6},
	{3, 6},
	{4, 5},
	{4, 4},
	{3, 3},
	{0, 3},
	{0, 0},
	{3, 0},
	{4, 1},
	{4, 2},
	{3, 3},
};

const int caracter_c[4][2] = {
	{4, 0},
	{0, 0},
	{0, 6},
	{4, 6},
};

const int caracter_d[7][2] = {
	{0, 0},
	{0, 6},
	{2, 6},
	{4, 4},
	{4, 2},
	{2, 0},
	{0, 0}
};

const int caracter_e[7][2] = {
	{4, 0},
	{0, 0},
	{0, 3},
	{3, 3},
	{0, 3},
	{0, 6},
	{4, 6},
};

const int caracter_f[6][2] = {
	{0, 0},
	{0, 3},
	{3, 3},
	{0, 3},
	{0, 6},
	{4, 6},
};

const int caracter_g[7][2] = {
	{2, 2},
	{4, 2},
	{4, 0},
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 4},
};

const int caracter_h[6][2] = {
	{0, 0},
	{0, 6},
	{0, 3},
	{4, 3},
	{4, 6},
	{4, 0},
};

const int caracter_i[6][2] = {
	{0, 0},
	{4, 0},
	{2, 0},
	{2, 6},
	{4, 6},
	{0, 6},
};

const int caracter_j[4][2] = {
	{0, 2},
	{2, 0},
	{4, 0},
	{4, 6},
};

const int caracter_k[6][2] = {
	{0, 0},
	{0, 6},
	{0, 3},
	{3, 6},
	{0, 3},
	{3, 0},
};

const int caracter_l[3][2] = {
	{4, 0},
	{0, 0},
	{0, 6},
};

const int caracter_m[5][2] = {
	{0, 0},
	{0, 6},
	{2, 4},
	{4, 6},
	{4, 0},
};

const int caracter_n[4][2] = {
	{0, 0},
	{0, 6},
	{4, 0},
	{4, 6},
};

const int caracter_o[5][2] = {
	{4, 0},
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 0},
};

const int caracter_p[5][2] = {
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 3},
	{0, 3},
};

const int caracter_q[9][2] = {
	{2, 2},
	{3, 1},
	{2, 0},
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 2},
	{3, 1},
	{4, 0},
};

const int caracter_r[7][2] = {
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 3},
	{0, 3},
	{1, 3},
	{4, 0},
};

const int caracter_s[6][2] = {
	{0, 0},
	{4, 0},
	{4, 3},
	{0, 3},
	{0, 6},
	{4, 6},
};

const int caracter_t[4][2] = {
	{2, 0},
	{2, 6},
	{4, 6},
	{0, 6},
};

const int caracter_u[4][2] = {
	{0, 6},
	{0, 0},
	{4, 0},
	{4, 6},
};

const int caracter_v[3][2] = {
	{0, 6},
	{2, 0},
	{4, 6},
};

const int caracter_w[5][2] = {
	{0, 6},
	{0, 0},
	{2, 2},
	{4, 0},
	{4, 6},
};

const int caracter_x[5][2] = {
	{0, 0},
	{4, 6},
	{2, 3},
	{0, 6},
	{4, 0},
};

const int caracter_y[5][2] = {
	{0, 6},
	{2, 4},
	{4, 6},
	{2, 4},
	{2, 0},
};

const int caracter_z[4][2] = {
	{0, 6},
	{4, 6},
	{0, 0},
	{4, 0},
};

const int caracter_0[5][2] = {
	{4, 0},
	{0, 0},
	{0, 6},
	{4, 6},
	{4, 0},
};

const int caracter_1[2][2] = {
	{2, 0},
	{2, 6},
};

const int caracter_2[6][2] = {
	{0, 6},
	{4, 6},
	{4, 3},
	{0, 3},
	{0, 0},
	{4, 0},
};

const int caracter_3[7][2] = {
	{0, 0},
	{4, 0},
	{4, 3},
	{0, 3},
	{4, 3},
	{4, 6},
	{0, 6},
};

const int caracter_4[5][2] = {
	{0, 6},
	{0, 3},
	{4, 3},
	{4, 6},
	{4, 0},
};

const int caracter_5[6][2] = {
	{0, 0},
	{4, 0},
	{4, 3},
	{0, 3},
	{0, 6},
	{4, 6},
};

const int caracter_6[5][2] = {
	{0, 6},
	{0, 0},
	{4, 0},
	{4, 3},
	{0, 3},
};

const int caracter_7[3][2] = {
	{0, 6},
	{4, 6},
	{4, 0},
};

const int caracter_8[7][2] = {
	{0, 3},
	{0, 6},
	{4, 6},
	{4, 0},
	{0, 0},
	{0, 3},
	{4, 3},
};

const int caracter_9[5][2] = {
	{4, 0},
	{4, 6},
	{0, 6},
	{0, 3},
	{4, 3},
};

const int caracter_derecha[5][2] = {
	{0, 3},
	{12, 3},
	{9, 5},
	{9, 1},
	{12, 3},
};

const int caracter_izquierda[5][2] = {
	{12, 3},
	{0, 3},
	{3, 5},
	{3, 1},
	{0, 3},
};

const int caracter_arriba[5][2] = {
	{5, -2},
	{5, 10},
	{3, 7},
	{7, 7},
	{5, 10},
};

const int caracter_abajo[5][2] = {
	{5, 10},  
	{5, -2},
	{3, 1},   
	{7, 1},
	{5, -2},
};

const int caracter_espacio[1][2] = {
	{0, 0},
};


static char caracteres[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','>','<','^', 'v',' '};

static size_t tamagnos_car[] = {7,12,4,7,7,6,7,6,6,4,6,3,5,4,5,5,9,7,6,4,4,3,5,5,5,4,5,2,6,7,5,6,5,3,7,5,5,5,5,5,1};

static char_t vector_car[] = {caracter_a, caracter_b, caracter_c, caracter_d, caracter_e, caracter_f, caracter_g, caracter_h, caracter_i, caracter_j, caracter_k, caracter_l, caracter_m, caracter_n, caracter_o, caracter_p, caracter_q, caracter_r, caracter_s, caracter_t, caracter_u, caracter_v, caracter_w, caracter_x, caracter_y, caracter_z, caracter_0, caracter_1, caracter_2, caracter_3, caracter_4, caracter_5, caracter_6, caracter_7, caracter_8, caracter_9, caracter_derecha, caracter_izquierda, caracter_arriba, caracter_abajo, caracter_espacio};

static size_t elementos = sizeof(vector_car)/sizeof(char_t);

size_t caracter_a_tamagno(char c){
	size_t i;
	for(i = 0; i < elementos; i++){
		if(caracteres[i] == c)
			break;
	}
	return tamagnos_car[i];
}

char_t caracter_a_vector(char c){
	size_t i;
	for(i = 0; i < elementos; i++){
		if(caracteres[i] == c)
			break;
	}
	return vector_car[i];
}

void caracteres_dibujar(char * frase, int altura, int largo, int factor, int espacio, SDL_Renderer *renderer){
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

