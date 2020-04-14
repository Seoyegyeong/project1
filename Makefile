CC = gcc

main : main.c restaurants.o
	$(CC) -o main main.c restaurants.o

members.o : restaurants.c restaurants.h
	$(CC) -c restaurants.c -o restaurants.o

clean :
	rm *.o main
