CC=g++
CFLAGS=-c -Wall

all: problemsOutput

problemsOutput: main.o SearchInsertPosition.o
	$(CC)  main.o SearchInsertPosition.o -o problemsOutput

SearchInsertPosition.o: SearchInsertPosition.c int.h
	$(CC) $(CFLAGS) SearchInsertPosition.c

main.o: main.c int.h
	$(CC) $(CFLAGS) main.c
	
clean: 
	rm -rf *o problemsOutput
