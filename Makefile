CC=gcc
CFLAGS=-Wall -Wextra -std=c99

TARGETS=marching_squares

build: $(TARGETS)

marching: marching_squares.c 
	$(CC) $(CFLAGS) marching_squares.c -o marching_squares

pack:
	zip -FSr 315CA_SerbanLucasNicolae_Tema2.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS)

.PHONY: pack clean