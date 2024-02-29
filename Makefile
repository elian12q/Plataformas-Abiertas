all: p1 p2

p1:
	gcc `pkg-config --cflags gtk+-3.0` -o exe proyecto1.c `pkg-config --libs gtk+-3.0` -rdynamic

p2: 
	gcc proyecto2.c -o exe
