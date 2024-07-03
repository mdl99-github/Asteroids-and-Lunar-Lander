#ifndef _NAVES_H_
#define _NAVES_H_

#include <SDL2/SDL.h>
#include "naves.h"
#include "dibujado.h"
#include "cinematica.h"
#include "puntos.h"
#include "memoria.h"

#define NAVE_GRANDE_TOBERA_X 5
#define NAVE_GRANDE_TOBERA_Y -12

#define NAVE_CHICA_TOBERA_X 4
#define NAVE_CHICA_TOBERA_Y 9.5

extern const float nave_grande[28][2];
extern const float nave_chica[17][2];

void inicializar_nave(const float nave[][2],size_t tamagno, const float chorro[][2], float x, float y, float vx, float vy, double angulo, int potencia, SDL_Renderer *renderer);
//Recibe la nave y el chorro representados como conjuntos de puntos en el espacio, asi tambien como su desplazamiento (x,y) para un ciclo de iteracion del main, su angulo y su potencia
//y los crea en memoria dinamica, rota, traslada, dibuja y destruye para dicho ciclo.

#endif // _NAVES_H_
