#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cinematica.h"
#include "graficador.h"
#include "lista.h"
#include "nave.h"
#include "config.h"
#include "disparos.h"


void disparo_mover(disparo_t *disparo, float dt){
	disparo->x = computar_posicion(disparo->x, disparo->vx, dt);
	disparo->y = computar_posicion(disparo->y, disparo->vy, dt);
}

bool disparo_dibujar(disparo_t *disparo){
	return graficador_dibujar("SHOT", 3, disparo->x, disparo->y, disparo->angulo);
}

bool disparo_crear(lista_t *l, float x, float y, double angulo){
	disparo_t *nuevo = malloc(sizeof(disparo_t));
	nuevo->angulo = angulo;	
	nuevo->x = x;
	nuevo->y = y;
	nuevo->vx = cos(angulo)*DISPARO_VELOCIDAD;
	nuevo->vy = sin(angulo)*DISPARO_VELOCIDAD;
	nuevo->tiempo_vida = 0;

	return lista_insertar_final(l, nuevo);
}

void disparo_actualizar_tiempo(lista_t *l, float dt){
	lista_iterador_t *li = lista_iterador_crear(l);
	
	for(; !lista_iterador_termino(li); lista_iterador_siguiente(li)){
		disparo_t *aux = lista_iterador_actual(li);
		aux->tiempo_vida += dt;
	}
	lista_iterador_destruir(li);
}

static int disparo_comparar_tiempo_vida(const void *a, const void *b){
//Compara el tiempo de vida de los disparos a y b.
	const disparo_t *auxa = a;
	const disparo_t *auxb = b;

	return auxa->tiempo_vida - auxb->tiempo_vida;
}

void disparo_desaparecer(lista_t *l){
	disparo_t *aux = malloc(sizeof(disparo_t));
	aux->tiempo_vida = DISPARO_TIEMPO_VIDA + 1;			
	lista_borrar(l, aux, disparo_comparar_tiempo_vida);
	free(aux);
}

void disparo_destruir(void *disparo){
	disparo_t *aux = disparo;
	free(aux);
}