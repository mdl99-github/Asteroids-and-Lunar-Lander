#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

struct nodo {
	struct nodo *sig;
	void *dato;
};

struct lista {
	struct nodo *prim;
};

//TDA Lista

static struct nodo *nodo_crear(void *d) {
	struct nodo *n = malloc(sizeof(struct nodo));
	if(n == NULL)
		return NULL;

	n->sig = NULL;
	n->dato = d;

	return n;
}

lista_t *lista_crear() {
	lista_t *l = malloc(sizeof(lista_t));
	if(l == NULL)
		return NULL;

	l->prim = NULL;
	return l;
}


void lista_destruir(lista_t *l, void (*destruir_dato)(void *d)) {
	struct nodo *n = l->prim;
	while(n != NULL) {
		struct nodo *sig = n->sig;

		if(destruir_dato != NULL)
			destruir_dato(n->dato);

		free(n);

		n = sig;
	}

	free(l);
}

bool lista_es_vacia(const lista_t *l) {
	return l->prim == NULL;
}

bool lista_insertar_final(lista_t *l, void *d) {
	struct nodo *n = nodo_crear(d);
	if(n == NULL) return false;

	if(l->prim == NULL) {
		l->prim = n;
		return true;
	}

	struct nodo *aux = l->prim;
	while(aux->sig != NULL)
		aux = aux->sig;

	aux->sig = n;

	return true;
}

void lista_borrar(lista_t *l, const void *d, int(*cmp)(const void *a, const void *b)){
	while(l->prim && cmp(l->prim-> dato, d) == 0){
		struct nodo *aux = l->prim->sig;
		free(l->prim);
		l->prim = aux;
	}
	
	if(l->prim == NULL)
		return;

	struct nodo *ant = l->prim;
	while(ant->sig){
		struct nodo *actual = ant->sig;
		if(cmp(actual->dato, d) == 0){
			ant->sig = actual->sig;
			free(actual);
		}
		else ant = actual;
	}
}

//TDA Iterador

struct lista_iterador {
	struct nodo **pn;
};


lista_iterador_t *lista_iterador_crear(lista_t *l){
	lista_iterador_t *li = malloc(sizeof(lista_iterador_t));
	if(li == NULL)
		return NULL;
	li->pn = &(l->prim);
	return li;
}

void lista_iterador_destruir(lista_iterador_t *li){
	free(li);
}

void *lista_iterador_actual(const lista_iterador_t *li){
	if((*li->pn) == NULL)
		return NULL;

	return (*li->pn)->dato;
}

bool lista_iterador_siguiente(lista_iterador_t *li){
	if(*li->pn == NULL)
		return false;

	(*li->pn) = (*li->pn)->sig;
	return true;
}

void *lista_iterador_eliminar(lista_iterador_t *li){
	void *d = lista_iterador_actual(li);
	struct nodo *aux = (*li->pn);
	lista_iterador_siguiente(li);
	free(aux);
	return d;
}

bool lista_iterador_termino(const lista_iterador_t *li){
	if((*li->pn) == NULL)
		return true;
	return false;
}














































