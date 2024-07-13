#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include <SDL2/SDL.h>

#define PAQUETE 10

typedef float (*sprites_t)[2];

bool graficador_inicializar(const char *fn, SDL_Renderer *r);
//Recibe fn que es el nombre del archivo de sprites y un renderer r e inicializa dinamicamente todas la variables necesarias para utilizar el resto del modulo.

void graficador_finalizar();
//Libera todos los recursos asociados al modulo.

bool graficador_dibujar(const char *nombre, float escala, float x, float y, double angulo);
//Recibe el nombre del sprite a dibujar, donde dibujarlo y su angulo, y lo dibuja en pantalla.

void graficador_ajustar_variables(float *x, float *y);
//Recibe dos variables x e y y las ajusta dentro del ancho y alto de la pantalla.

#endif
