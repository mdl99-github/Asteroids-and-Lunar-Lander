  #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "cinematica.h"
#include "graficador.h"
#include "lista.h"
#include "nave.h"
#include "config.h"
#include "asteroides.h"

void asteroide_mover(asteroide_t *asteroide, float dt){
	asteroide->x = computar_posicion(asteroide->x, asteroide->vx, dt);
	asteroide->y = computar_posicion(asteroide->y, asteroide->vy, dt);
}

bool asteroide_dibujar(const asteroide_t *asteroide){
	char aux[6];
	sprintf(aux, "ROCK%d", asteroide->tipo);
	return graficador_dibujar(aux, asteroide->radio, asteroide->x, asteroide-> y, asteroide->angulo);
}

bool asteroide_crear(lista_t *l, float x, float y, int radio, int *numero){
	asteroide_t *asteroide = malloc(sizeof(asteroide_t));
	asteroide->x = x;
	asteroide->y = y;
	asteroide->angulo = (rand()/(float)RAND_MAX)*2*PI;
	asteroide->radio = radio;
	float mod_vel = 1000.0/asteroide->radio + rand()%201 - 100;
	asteroide->vx = cos(asteroide->angulo)*mod_vel;
	asteroide->vy = sin(asteroide->angulo)*mod_vel;
	asteroide->tipo = rand()%4 + 1;
	asteroide->numero = *numero;

	*numero = *numero + 1;
	
	return lista_insertar_final(l, asteroide);
}

bool asteroide_choco(lista_t *l, float x, float y, int *numero){
	lista_iterador_t *li = lista_iterador_crear(l);
	for(; !lista_iterador_termino(li); lista_iterador_siguiente(li)){
		asteroide_t *aux = lista_iterador_actual(li);
		if(aux->x - aux->radio <= x && x <= aux->x + aux->radio ){
			if(aux->y - aux->radio <= y && y <= aux->y + aux->radio){
				if(numero != NULL) *numero = aux->numero;
				return true;
			}
		}
	}
	lista_iterador_destruir(li);
	return false;
}

static int asteroide_comparar(const void *a, const void *b){
	const asteroide_t *a1 = a;
	const asteroide_t *a2 = b;
	
	return a1->numero - a2->numero;
}

void asteroide_eliminar_lista(lista_t *l, asteroide_t *asteroide){
	lista_borrar(l, asteroide, asteroide_comparar);
}

void asteroide_destruir(void *asteroide){
	asteroide_t *aux = asteroide;
	free(aux);
}

	