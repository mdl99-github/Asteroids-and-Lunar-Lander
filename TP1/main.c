#include <SDL2/SDL.h>

#include "config.h"
#include "naves.h"
#include "memoria.h"
#include "cinematica.h"
#include "puntos.h"
#include "rectas.h"
#include "caracteres.h"
#include "dibujado.h"

int main() {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	SDL_CreateWindowAndRenderer(VENTANA_ANCHO, VENTANA_ALTO, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Lunar Lander");

	int dormir = 0;

	// BEGIN código del alumno

	srand(time(NULL));

	const float (*nave)[2] = nave_grande;
	size_t nave_tam = sizeof(nave_grande) / sizeof(nave_grande[0]);

	float chorro[3][2] = {
		{-NAVE_GRANDE_TOBERA_X, NAVE_GRANDE_TOBERA_Y},
		{0, NAVE_GRANDE_TOBERA_Y},
		{NAVE_GRANDE_TOBERA_X, NAVE_GRANDE_TOBERA_Y}
	};

	int potencia = NAVE_POTENCIA_INICIAL;
	float combustible = JUEGO_COMBUSTIBLE_INICIAL;
	float cronometro = 0;
	int puntaje = 0;
	int altura;
	float tiempo = 1/(float)JUEGO_FPS;

	double angulo = NAVE_ANGULO_INICIAL;

	float px = NAVE_X_INICIAL;
	float py = NAVE_Y_INICIAL;

	float vx = NAVE_VX_INICIAL;
	float vy = NAVE_VY_INICIAL;

	float ax;
	float ay;

	size_t terreno_tam;
	float **terreno = crear_terreno(&terreno_tam);

	int factor_letras = 2;

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
						if(potencia < NAVE_MAX_POTENCIA){
							potencia += 1;
						}
						break;
					case SDLK_DOWN:
						if(potencia > 0){
							potencia -= 1;

						}
						break;
					case SDLK_RIGHT:
						if(angulo > 0){
							angulo -= NAVE_ROTACION_PASO;
							combustible -= JUEGO_COMBUSTIBLE_RADIANES*NAVE_ROTACION_PASO;
						}
						break;
					case SDLK_LEFT:
						if(angulo < PI){
							angulo += NAVE_ROTACION_PASO;
							combustible -= JUEGO_COMBUSTIBLE_RADIANES*NAVE_ROTACION_PASO;
						}
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
		ax = potencia * cos(angulo);
		ay = -G + potencia * sin(angulo);
		
		vx = computar_velocidad(vx, ax, tiempo);		
		vy = computar_velocidad(vy, ay, tiempo);

		px = computar_posicion(px, vx, tiempo);
		py = computar_posicion(py, vy, tiempo);

		dibujar_terreno(terreno, terreno_tam, renderer);

		inicializar_nave(nave, nave_tam, chorro, px - NAVE_X_INICIAL, py - NAVE_Y_INICIAL, vx, vy, angulo - PI/2, potencia, renderer);

		cronometro += tiempo;

		altura = -altura_en_recta(terreno, px, terreno_tam) + py + NAVE_GRANDE_TOBERA_Y;

		combustible -= JUEGO_COMBUSTIBLE_POT_X_SEG * potencia/(float)JUEGO_FPS;

		if(altura <= 0){
			dormir = 3000;
			if(fabs(vx) < 1 && fabs(vy) < 10 && fabs(NAVE_ANGULO_INICIAL - angulo) < 0.01){
				puntaje += 50;
				dibujar_caracteres("YOU HAVE LANDED", VENTANA_ALTO/2, VENTANA_ANCHO/16.0, 10, 60, renderer);
			}

			else if(fabs(vx) < 2 && fabs(vy) < 20 && fabs(NAVE_ANGULO_INICIAL - angulo) < 0.01){
				puntaje += 15;
				dibujar_caracteres("YOU LANDED HARD", VENTANA_ALTO/2, VENTANA_ANCHO/16.0, 10, 60, renderer);
				}
				else {
					puntaje += 5;
					combustible -= 250;
					dibujar_caracteres("DESTROYED", VENTANA_ALTO/2, VENTANA_ANCHO/4.0, 10, 60, renderer);
				}
		
			px = NAVE_X_INICIAL;
			py = NAVE_Y_INICIAL;

			vx = NAVE_VX_INICIAL;
			vy = NAVE_VY_INICIAL;

			angulo = NAVE_ANGULO_INICIAL;

			potencia = NAVE_POTENCIA_INICIAL;

			altura = 0;

			vector_destruir(terreno, terreno_tam, 2);	
			terreno_tam = 0;

			terreno = crear_terreno(&terreno_tam);	

		}
	

		char aux[24];

		sprintf(aux, "SCORE %04d", puntaje);
		dibujar_caracteres(aux, POSICION_IZQ_Y,POSICION_IZQ_X + factor_letras, factor_letras, factor_letras*CARACTER_ANCHO, renderer);
	
		sprintf(aux, "TIME  %04d", (int)cronometro);
		dibujar_caracteres(aux, POSICION_IZQ_Y + factor_letras*2*CARACTER_ALTO, POSICION_IZQ_X, factor_letras, factor_letras*CARACTER_ANCHO, renderer);
		
		sprintf(aux, "FUEL  %04d", (int)combustible);
		dibujar_caracteres(aux, POSICION_IZQ_Y + factor_letras*4*CARACTER_ALTO, POSICION_IZQ_X, factor_letras, factor_letras*CARACTER_ANCHO, renderer);
		
		sprintf(aux, "ALTITUDE         %4d", altura);
		dibujar_caracteres(aux, POSICION_DER_Y + factor_letras, POSICION_DER_X, factor_letras, factor_letras*CARACTER_ANCHO, renderer);

		sprintf(aux, "HORIZONTAL SPEED %4d %c", (int)fabs(vx), vx > 0 ? '>':'<');
		dibujar_caracteres(aux, POSICION_DER_Y + factor_letras*2*CARACTER_ALTO, POSICION_DER_X, factor_letras, factor_letras*CARACTER_ANCHO, renderer);

		sprintf(aux, "VERTICAL SPEED   %4d %c", (int)fabs(vy), vy > 0 ? '^':'v');
		dibujar_caracteres(aux, POSICION_DER_Y + factor_letras*4*CARACTER_ALTO, POSICION_DER_X, factor_letras, factor_letras*CARACTER_ANCHO, renderer);


		if(px >= VENTANA_ANCHO)
			px -= VENTANA_ANCHO;
		if(px <= 0)
			px += VENTANA_ANCHO;


		if(combustible == 0){
			printf("SCORE: %d\n", puntaje);
			break;
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
	vector_destruir(terreno, terreno_tam, 2);
	// END código del alumno

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}

