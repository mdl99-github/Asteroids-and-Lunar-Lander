#ifndef _LETRAS_H_
#define _LETRAS_H_

#include <stdlib.h>
#include <SDL2/SDL.h>

#define CARACTER_ANCHO 4
#define CARACTER_ALTO 4

#define POSICION_Y 50
#define POSICION_X 100


extern const int caracter_a[7][2];
extern const int caracter_b[12][2];
extern const int caracter_c[4][2];
extern const int caracter_d[7][2];
extern const int caracter_e[7][2];
extern const int caracter_f[6][2];
extern const int caracter_g[7][2];
extern const int caracter_h[6][2];
extern const int caracter_i[6][2];
extern const int caracter_j[4][2];
extern const int caracter_k[6][2];
extern const int caracter_l[3][2];
extern const int caracter_m[5][2];
extern const int caracter_n[4][2];
extern const int caracter_o[5][2];
extern const int caracter_p[5][2];
extern const int caracter_q[9][2];
extern const int caracter_r[7][2];
extern const int caracter_s[6][2];
extern const int caracter_t[4][2];
extern const int caracter_u[4][2];
extern const int caracter_v[3][2];
extern const int caracter_w[5][2];
extern const int caracter_x[5][2];
extern const int caracter_y[5][2];
extern const int caracter_z[4][2];

extern const int caracter_0[5][2];
extern const int caracter_1[2][2];
extern const int caracter_2[6][2];
extern const int caracter_3[7][2];
extern const int caracter_4[5][2];
extern const int caracter_5[6][2];
extern const int caracter_6[5][2];
extern const int caracter_7[3][2];
extern const int caracter_8[7][2];
extern const int caracter_9[5][2];

extern const int caracter_derecha[5][2];
extern const int caracter_izquierda[5][2];
extern const int caracter_arriba[5][2];
extern const int caracter_abajo[5][2];

extern const int caracter_espacio[1][2];

typedef const int (*char_t)[2];

size_t caracter_a_tamagno(char c);
//Recibe un caracter(A-Z, 0-9, espacio, <, >, v o ^) y devuelve la cantidad de puntos en el plano por los que esta representado al dibujarse.

char_t caracter_a_vector(char c);
//Recibe un caracter(A-Z, 0-9, espacio, <, >, v o ^) y devuelve la matriz correspondiente.

void caracteres_dibujar(char * frase, int altura, int largo, int factor, int espacio, SDL_Renderer *renderer);
//Recibe una cadena de caracteres, una altura y largo de la pantalla en donde dibujar el primer caracter, un tamagno factor y el espacio entre las letras
//y dibuja la frase recibida en la pantalla.

#endif // _LETRAS_H_
