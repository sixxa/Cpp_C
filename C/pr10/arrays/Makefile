# ******************************************************************
# ProgrammingI.  Year2024-2025# Libraryproject compilation
# ******************************************************************

CC = gcc -Wall

all: library

access.o: access.c access.h
	$(CC) -c access.c

database.o: database.c database.h 
	$(CC) -c database.c 

library: library.c access.o database.o 
	$(CC) access.o database.o library.c -o library

run: library 
	./library


clean: 
	rm  -f  library *.o  *.bak  *~
