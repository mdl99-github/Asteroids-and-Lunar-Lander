#ifndef DISPAROS_H
#define DISPAROS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cinematica.h"
#include "graficador.h"
#include "lista.h"
#include "nave.h"
#include "config.h"

typedef struct disparo{
	double angulo;
	float vx;
	float vy;
	float x;
	float y;
	float tiempo_vida;
}disparo_t;

void disparo_mover(disparo_t *disparo, float dt);
//Actualiza posicion y estado del disparo recibido.

bool disparo_dibujar(disparo_t *disparo);
//Dibuja el disparo recibido en pantalla.

bool disparo_crear(lista_t *l, float x, float y, double angulo);
//Agrega un disparo a la lista recibida.

void disparo_actualizar_tiempo(lista_t *l, float dt);
//Le "avisa" a cada disparo activo que paso un tiempo dt.

void disparo_desaparecer(lista_t *l);
//Elimina los disparos con tiempo de vida maximo.

void disparo_destruir(void *disparo);
//Elimina la memoria ocupada por el disparo recibido.

#endif