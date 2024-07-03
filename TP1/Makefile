CC := gcc
MAIN_FLAGS := -lSDL2
FLAGS := -Wall -std=c99 -g -lm


all: Lunar_Lander

main.o: main.c caracteres.h config.h cinematica.h memoria.h naves.h puntos.h rectas.h dibujado.h
	$(CC) $(MAIN_FLAGS) $(FLAGS) main.c -c

caracteres.o: caracteres.h caracteres.c
	$(CC) $(FLAGS) caracteres.c -c

cinematica.o: cinematica.c cinematica.h
	$(CC) $(FLAGS) cinematica.c -c

memoria.o: memoria.c memoria.h
	$(CC) $(FLAGS) memoria.c -c

naves.o: naves.c naves.h cinematica.h puntos.h memoria.h dibujado.h
	$(CC) $(FLAGS) $(MAIN_FLAGS) naves.c -c

puntos.o: puntos.c puntos.h
	$(CC) $(FLAGS) puntos.c -c

rectas.o: rectas.c rectas.h memoria.h config.h
	$(CC) $(FLAGS) rectas.c -c 

dibujado.o: dibujado.c dibujado.h caracteres.h naves.h config.h
	$(CC) $(FLAGS) $(MAIN_FLAGS) dibujado.c -c

Lunar_Lander: main.o rectas.o puntos.o naves.o memoria.o cinematica.o caracteres.o dibujado.o 
	$(CC) main.o rectas.o puntos.o naves.o memoria.o cinematica.o caracteres.o dibujado.o $(FLAGS) $(MAIN_FLAGS) -o Lunar_Lander 

clean:
	rm *.o


	