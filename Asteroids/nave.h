#ifndef NAVE_H
#define NAVE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cinematica.h"
#include "graficador.h"
#include "config.h"

typedef struct nave{
	int potencia;
	float vx;
	float vy;
	float x;
	float y;
	double angulo;
}nave_t;

void nave_mover(nave_t *nave, float dt);
//Actualiza posicion y estado de la nave.

bool nave_dibujar(const nave_t *nave);
//Dibuja la nave recibida en pantalla.

nave_t *nave_crear();
//Crea la nave.

bool nave_chorro_dibujar(const nave_t *nave);
//De ser necesario, dibuja el chorro de la nave recibida en pantalla.

void nave_rotar(nave_t *nave, double ang);
//Incrementa o decrementa el angulo de la nave recibida en ang.

void nave_aplicar_impulso(nave_t *nave);
//Aplica a la nave un impulso en su potencia.

void nave_destruir(nave_t *nave);
//Elimina la memoria ocupada por la nave recibida.

#endif