task1: 
	gcc -c printer.c 
	gcc -c writer.c 
	ar rcs staticLib.a printer.o writer.o
	gcc -c proccess.c -o proccess.o
	gcc -o task1 proccess.o -L. staticLib.a
	./task1