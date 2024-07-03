#ifndef DIBUJADO_H
#define DIBUJADO_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include "caracteres.h"
#include "config.h"

void dibujar_caracteres(char * frase, int altura, int largo, int factor, int espacio, SDL_Renderer *renderer);
//Recibe una cadena de caracteres, una altura y largo de la pantalla en donde dibujar el primer caracter, un tamagno factor y el espacio entre las letras
//y dibuja la frase recibida en la pantalla.

void dibujar_nave(float **nave, size_t tamagno,float **chorro, SDL_Renderer *renderer);
//Recibe un puntero de tamagno punteros a flotantes, y otro mas de 3 punteros a flotantes y los dibjua en pantalla represententando la nave y su chorro.

void dibujar_terreno(float **terreno, size_t tamagno, SDL_Renderer *renderer);
//Recibe un puntero de tamagno punteros a flotantes y lo dibuja en pantalla representando al terreno.

#endif