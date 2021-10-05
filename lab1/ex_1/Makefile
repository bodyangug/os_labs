all: compile-static run

compile-static: main.c lib/libmathStatic.a
	gcc -c *.c
	gcc -o main.out *.o -L lib -lmathStatic -lm

compile-dynamic: main.c lib/libmathDynamic.so
	gcc -c *.c
	gcc -o main.out *.o -L lib -lmathDynamic -Wl,-rpath,lib/ -lm
	
run: main.out
	./main.out