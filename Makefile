bc : main.o addition.o comparison.o createnum.o
	gcc -o bc addition.o comparison.o createnum.o main.o

main.o : main.c number.h
	gcc -c main.c

addition.o : addition.c number.h
	gcc -c addition.c
	
comparison.o : comparison.c number.h
	gcc -c comparison.c
	
createnum.c : createnum.c number.h
	gcc -c createnum.c

clean :
	rm bc main.o createnum.o comparison.o addition.o 
