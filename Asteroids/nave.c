#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cinematica.h"
#include "nave.h"
#include "graficador.h"
#include "config.h"

void nave_mover(nave_t *nave, float dt){
	nave->vx = computar_velocidad(nave->vx, cos(nave->angulo)*(nave->potencia), dt);
	nave->vy = computar_velocidad(nave->vy, sin(nave->angulo)*(nave->potencia), dt);

	nave->x = computar_posicion(nave->x, nave->vx, dt);
	nave->y = computar_posicion(nave->y, nave->vy, dt);
}

bool nave_dibujar(const nave_t *nave){
	return graficador_dibujar("SHIP", 1, nave->x, nave->y, nave->angulo);
}

bool nave_chorro_dibujar(const nave_t *nave){
	return graficador_dibujar("THURST", 1, nave->x, nave->y, nave->angulo);
}

nave_t *nave_crear(){
	nave_t *nave = malloc(sizeof(nave_t));
	nave->potencia = NAVE_POTENCIA_INICIAL;
	nave->vx = 0;
	nave->vy = 0;
	nave->x = VENTANA_ANCHO/2;
	nave->y = VENTANA_ALTO/2;
	nave->angulo = NAVE_ANGULO_INICIAL;

	return nave;
}

void nave_rotar(nave_t *nave, double ang){
	nave->angulo += ang;
}

void nave_aplicar_impulso(nave_t *nave){
	nave->potencia += NAVE_IMPULSO;
}

void nave_destruir(nave_t *nave){
	free(nave);
	nave = NULL;
}
