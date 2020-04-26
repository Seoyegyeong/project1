CC = gcc
CFLAGS = -W -Wall

main : main.c eating.o
	$(CC) $(CFLAGS) -o $@ $^

eating.o : eating.c eating.h
	$(CC) $(CFLAGS) -c eating.c -o $@

clean :
	rm *.o main
