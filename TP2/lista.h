#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

struct lista;
typedef struct lista lista_t;

lista_t *lista_crear();
//Crea una lista vacia, y la devuelve por el nombre.

void lista_destruir(lista_t *l, void (*destruir_dato)(void *d));
//Recibe una lista y un procedimiento para destruir el tipo de dato que almacena y la borra.

bool lista_es_vacia(const lista_t *l);
//Devuelve "true" si la lista recibida esta vacia, "false" en caso contrario.

bool lista_insertar_final(lista_t *l, void *d);
//Recibe una lista y un dato y lo inserta como ultimo elemento de ella.

void lista_borrar(lista_t *l, const void *d, int(*cmp)(const void *a, const void *b));
//Recibe una lista, un dato y un procedimiento para comparar los datos, y, si lo encuentra, lo elimina de la lista.

typedef struct lista_iterador lista_iterador_t;

lista_iterador_t *lista_iterador_crear(lista_t *l);
//Crea un iterador apuntando al primer elemento de la lista recibida, y lo devuelve por el nombre.

void lista_iterador_destruir(lista_iterador_t *li);
//Elimina el iterador recibido.

void *lista_iterador_actual(const lista_iterador_t *li);
//Devuelve un puntero al dato del elemento al que el iterador esta apuntando en ese momento.

bool lista_iterador_siguiente(lista_iterador_t *li);
//Incrementa el iterador recibido en una posicion, devuelve "true" si la accion se realizo, y "false" si ya termino de recorrer la lista.

bool lista_iterador_termino(const lista_iterador_t *li);
//Devuelve "true" si el iterador recibido se encuentra en la ultima posicion de la lista, "false" en caso contrario.

#endif
