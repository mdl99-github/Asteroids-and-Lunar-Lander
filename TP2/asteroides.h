#ifndef ASTEROIDES_H
#define ASTEROIDES_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "cinematica.h"
#include "graficador.h"
#include "lista.h"
#include "nave.h"
#include "config.h"

typedef struct asteroide{
	float x;
	float y;
	float vx;
	float vy;
	double angulo;
	int radio;
	int tipo;
	int numero;
}asteroide_t;

void asteroide_mover(asteroide_t *asteroide, float dt);
//Actualiza posicion y estado del asteroide recibido.

bool asteroide_dibujar(const asteroide_t *asteroide);
//Dibuja el asteroide recibido en pantalla.

bool asteroide_crear(lista_t *l, float x, float y, int radio, int *numero);
//Agrega un asteroide a la lista recibida.

bool asteroide_choco(lista_t *l, float x, float y, int *numero);
//Recibe una lista con asteroides y devuelve "true" si las coordenadas recibidas coinciden con las de algun asteroide(teniedo en cuenta su radio),
//o "false" en caso contrario.

void asteroide_eliminar_lista(lista_t *l, asteroide_t *asteroide);
//Elimina el asteroide recibido de la lista.

void asteroide_destruir(void *asteroide);
//Elimina la memoria ocupada por el asteroide recibido.

#endif