CC = gcc
CFLAGS = -Wall -std=c99

all: complete_dict

dictionary.o: dictionary.c dictionary.h 
	$(CC) $(CFLAGS) -c dictionary.c

complete_dict.o: complete_dict.c dictionary.o dictionary.h
	$(CC) $(CFLAGS) -c complete_dict.c
	
complete_dict: complete_dict.o 
	$(CC) $(CFLAGS) -o complete_dict dictionary.o complete_dict.o 

clean:
	rm *.o complete_dict
