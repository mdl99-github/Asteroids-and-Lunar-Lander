#include <SDL2/SDL.h>

#include "config.h"
#include "lista.h"
#include "graficador.h"
#include "puntos.h"
#include "memoria.h"
#include "cinematica.h"
#include "nave.h"
#include "disparos.h"
#include "asteroides.h"
#include "caracteres.h"

int main() {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	SDL_CreateWindowAndRenderer(VENTANA_ANCHO, VENTANA_ALTO, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Asteroids");

	int dormir = 0;
	

	// BEGIN código del alumno

	graficador_inicializar("sprites.bin", renderer);

	srand(time(NULL));

	nave_t *nave = nave_crear();

	lista_t *l_disparos = lista_crear();
	lista_t *l_asteroides = lista_crear();

	int contador_asteroides = 1;

	asteroide_crear(l_asteroides, 0, rand()%(VENTANA_ALTO + 1), 32, &contador_asteroides);
	asteroide_crear(l_asteroides, 0, rand()%(VENTANA_ALTO + 1), 32, &contador_asteroides);
	asteroide_crear(l_asteroides, rand()%(VENTANA_ANCHO + 1), 0, 32, &contador_asteroides);
	asteroide_crear(l_asteroides, rand()%(VENTANA_ANCHO + 1), 0, 32, &contador_asteroides);
	
	int puntaje = 0;
	int puntaje_maximo = 0;
	size_t dificultad = 0;
	int vidas = 4;

	float tiempo_espera = 0;
	float factor_espera = 0;

	int factor_letras = 5;
	
	bool boton_inicio = false;
	bool boton_continuar = false;

	float dt = 1/(float)JUEGO_FPS;
	
	// END código del alumno

	unsigned int ticks = SDL_GetTicks();
	while(1) {
		if(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				break;
	    		if (event.type == SDL_KEYDOWN) {
				// BEGIN código del alumno
				switch(event.key.keysym.sym) {
					case SDLK_UP:
						if(nave != NULL)
							nave_aplicar_impulso(nave);
						break;
					case SDLK_RIGHT:
						if(nave != NULL)
							nave_rotar(nave, -NAVE_ROTACION_PASO);
						break;
					case SDLK_LEFT:
						if(nave != NULL)
							nave_rotar(nave, NAVE_ROTACION_PASO);
						break;
					case SDLK_SPACE:
						if(nave != NULL)
							disparo_crear(l_disparos, nave->x, nave->y, nave->angulo);
						if(vidas == 0)
							boton_continuar = true;
						else boton_inicio = true;
						break;
				}
				// END código del alumno


			}
			continue;
		}
        	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        	SDL_RenderClear(renderer);
        	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);


		// BEGIN código del alumno
		
		int numero_ast = 0;

		char letras[15];

		lista_iterador_t *li = NULL;

		if(vidas == 0){

				caracteres_dibujar("GAME OVER", VENTANA_ALTO/2, VENTANA_ANCHO/2 - 9 * 15, CARACTER_ALTO, 30, renderer);
				sprintf(letras, "SCORE   %d", puntaje);
				caracteres_dibujar(letras, VENTANA_ALTO/2 + 30, VENTANA_ANCHO/2 -  6 * 15, CARACTER_ALTO/1.8, 30/1.8, renderer);
				caracteres_dibujar("PRESS SPACE TO TRY AGAIN", VENTANA_ALTO/2 + 60, VENTANA_ANCHO/2 -  12 * 15, CARACTER_ALTO/1.8, 30/1.8, renderer);
				
				if(l_disparos != NULL){
					lista_destruir(l_disparos, disparo_destruir);
					lista_destruir(l_asteroides, asteroide_destruir);
					l_disparos = NULL;
					l_asteroides = NULL;
				}

				if(puntaje > puntaje_maximo)
					puntaje_maximo = puntaje;

				if(nave != NULL){
					nave_destruir(nave);
					nave = NULL;
				}
	
				if(boton_continuar){
					nave = nave_crear();

					l_disparos = lista_crear();
					l_asteroides = lista_crear();	

					asteroide_crear(l_asteroides, 0, rand()%(VENTANA_ALTO + 1), 32, &contador_asteroides);
					asteroide_crear(l_asteroides, 0, rand()%(VENTANA_ALTO + 1), 32, &contador_asteroides);
					asteroide_crear(l_asteroides, rand()%(VENTANA_ANCHO + 1), 0, 32, &contador_asteroides);
					asteroide_crear(l_asteroides, rand()%(VENTANA_ANCHO + 1), 0, 32, &contador_asteroides);
				
					vidas = 4;
					puntaje = 0;

					boton_continuar = false;
				}
			}

		if(!boton_inicio)
			caracteres_dibujar("PRESS SPACE TO START", VENTANA_ALTO/2, VENTANA_ANCHO/2 - CARACTER_ANCHO * factor_letras * 9.5, CARACTER_ALTO, CARACTER_ANCHO * factor_letras, renderer);

		if(boton_inicio && vidas > 0 && l_disparos != NULL && l_asteroides != NULL){
	
			sprintf(letras, "%02d", puntaje);
			caracteres_dibujar(letras, 50, 100, CARACTER_ALTO, CARACTER_ANCHO * factor_letras, renderer);

			sprintf(letras, "%02d", puntaje_maximo);
			caracteres_dibujar(letras, 50, VENTANA_ANCHO/2 - CARACTER_ANCHO * factor_letras, CARACTER_ALTO/2, CARACTER_ANCHO/2 * factor_letras, renderer);

			int espacio = 0;
			for(size_t i = 0; i < vidas - 1; i++){
				graficador_dibujar("SHIP", VIDA_TAMAGNO, VIDA_X - espacio, VIDA_Y, NAVE_ANGULO_INICIAL);
				espacio += CARACTER_ANCHO * factor_letras;
			}
			espacio = 0;

			for(li = lista_iterador_crear(l_asteroides); !lista_iterador_termino(li); lista_iterador_siguiente(li)){
				asteroide_t *aux = lista_iterador_actual(li);
				graficador_ajustar_variables(&(aux->x), &(aux->y));
				asteroide_dibujar(aux);
				asteroide_mover(aux, dt);
			}

			lista_iterador_destruir(li);

			if(nave != NULL){

				graficador_ajustar_variables(&(nave->x), &(nave->y));
				nave_dibujar(nave);
				if(nave->potencia > 1) nave_chorro_dibujar(nave);
				nave_mover(nave, dt);
				nave->potencia *= 0.9;
				nave->vx *= 0.99;
				nave->vy *= 0.99;

				for(li = lista_iterador_crear(l_disparos); !lista_iterador_termino(li); lista_iterador_siguiente(li)){
					disparo_t *aux = lista_iterador_actual(li);
					graficador_ajustar_variables(&(aux->x), &(aux->y));
					disparo_dibujar(aux);
					disparo_mover(aux, dt);
					int radio;
					float x;
					float y;
					if(asteroide_choco(l_asteroides, aux->x, aux->y, &numero_ast)){
						lista_iterador_t *li_ast = NULL;
						for(li_ast = lista_iterador_crear(l_asteroides); !lista_iterador_termino(li_ast); lista_iterador_siguiente(li_ast)){
							asteroide_t *asteroide = lista_iterador_actual(li_ast);
							if(asteroide->numero == numero_ast){
								radio = asteroide->radio;
								x = asteroide->x;
								y = asteroide->y;
								asteroide_eliminar_lista(l_asteroides, asteroide);
								break;
							}
						}
						if(radio == 32){
							asteroide_crear(l_asteroides, x, y, 16, &contador_asteroides);
							asteroide_crear(l_asteroides, x, y, 16, &contador_asteroides);
							puntaje += 20;
						}
						else if(radio == 16){
							asteroide_crear(l_asteroides, x, y, 8, &contador_asteroides);
							asteroide_crear(l_asteroides, x, y, 8, &contador_asteroides);
							puntaje += 50;
						}
							else if(radio == 8) puntaje += 100;
	
						if(lista_es_vacia(l_asteroides)){
							for(size_t i = 0; i < dificultad + 3; i++){
								asteroide_crear(l_asteroides, 0, rand()%(VENTANA_ALTO + 1), 32, &contador_asteroides);
								asteroide_crear(l_asteroides, rand()%(VENTANA_ANCHO + 1), 0, 32, &contador_asteroides);
							}
							dificultad++;
						}
						lista_iterador_destruir(li_ast);
						
					}
				
				}

				lista_iterador_destruir(li);
		
				disparo_actualizar_tiempo(l_disparos, dt);
				disparo_desaparecer(l_disparos);

				if(asteroide_choco(l_asteroides, nave->x, nave->y, &numero_ast)){
					int radio;
					float x;
					float y;
					lista_iterador_t *li_ast = NULL;
					for(li_ast = lista_iterador_crear(l_asteroides); !lista_iterador_termino(li_ast); lista_iterador_siguiente(li_ast)){
							asteroide_t *asteroide = lista_iterador_actual(li_ast);
							if(asteroide->numero == numero_ast){
								radio = asteroide->radio;
								x = asteroide->x;
								y = asteroide->y;
								asteroide_eliminar_lista(l_asteroides, asteroide);
								break;
							}
						}
						if(radio == 32){
							asteroide_crear(l_asteroides, x, y, 16, &contador_asteroides);
							asteroide_crear(l_asteroides, x, y, 16, &contador_asteroides);
							puntaje += 20;
						}
						else if(radio == 16){
							asteroide_crear(l_asteroides, x, y, 8, &contador_asteroides);
							asteroide_crear(l_asteroides, x, y, 8, &contador_asteroides);
							puntaje += 50;
						}
							else if(radio == 8) puntaje += 100;
	
						if(lista_es_vacia(l_asteroides)){
							for(size_t i = 0; i < dificultad + 3; i++){
								asteroide_crear(l_asteroides, 0, rand()%(VENTANA_ALTO + 1), 32, &contador_asteroides);
								asteroide_crear(l_asteroides, rand()%(VENTANA_ANCHO + 1), 0, 32, &contador_asteroides);
							}
							dificultad++;
						}					
					
					nave_destruir(nave);
					nave = NULL;
					vidas -= 1;

					lista_iterador_destruir(li_ast);
				}
			}

			if(nave == NULL && vidas > 0){
				if(tiempo_espera >= 1 + (int)factor_espera * 0.1 && !asteroide_choco(l_asteroides, VENTANA_ANCHO/2, VENTANA_ALTO/2, NULL)){
					nave = nave_crear();
					tiempo_espera = 0;
					factor_espera = 0;
				}
				else{ 
					tiempo_espera += dt;
					factor_espera += dt;
				}
			}
		}

		// END código del alumno


        	SDL_RenderPresent(renderer);
		ticks = SDL_GetTicks() - ticks;
		if(dormir) {
			SDL_Delay(dormir);
			dormir = 0;
		}
		else if(ticks < 1000 / JUEGO_FPS)
			SDL_Delay(1000 / JUEGO_FPS - ticks);
		ticks = SDL_GetTicks();
	}

	// BEGIN código del alumno

	graficador_finalizar();
	lista_destruir(l_disparos, disparo_destruir);
	lista_destruir(l_asteroides, asteroide_destruir);
	nave_destruir(nave);

	// END código del alumno

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}

