CC := gcc
MAIN_FLAGS := -lSDL2
FLAGS := -Wall -std=c99 -g -lm


all: Asteroids

main.o: main.c config.h graficador.h lista.h puntos.h memoria.h cinematica.h nave.h disparos.h asteroides.h caracteres.h
	$(CC) $(FLAGS) $(MAIN_FLAGS) main.c -c	

caracteres.o: caracteres.h caracteres.c
	$(CC) $(FLAGS) caracteres.c -c

cinematica.o: cinematica.c cinematica.h
	$(CC) $(FLAGS) cinematica.c -c

memoria.o: memoria.c memoria.h
	$(CC) $(FLAGS) memoria.c -c

puntos.o: puntos.c puntos.h
	$(CC) $(FLAGS) puntos.c -c

rectas.o: rectas.c rectas.h memoria.h config.h
	$(CC) $(FLAGS) rectas.c -c 

lista.o: lista.c lista.h
	$(CC) $(FLAGS) lista.c -c

graficador.o: graficador.c graficador.h puntos.h memoria.h
	$(CC) $(FLAGS) $(MAIN_FLAGS) graficador.c -c

nave.o: nave.c nave.h cinematica.h graficador.h config.h 
	$(CC) $(FLAGS) nave.c -c

disparos.o: disparos.c disparos.h cinematica.h graficador.h lista.h nave.h config.h
	$(CC) $(FLAGS) disparos.c -c

asteroides.o: asteroides.c asteroides.h cinematica.h graficador.h lista.h nave.h config.h
	$(CC) $(FLAGS) asteroides.c -c

Asteroids: main.o graficador.o lista.o puntos.o memoria.o cinematica.o nave.o disparos.o asteroides.o caracteres.o
	$(CC) main.o graficador.o lista.o puntos.o memoria.o cinematica.o nave.o disparos.o asteroides.o caracteres.o $(FLAGS) $(MAIN_FLAGS) -o Asteroids

clean:
	rm *.o
