#------ ID BOX ----------------------------
# COMP 201 - ALEC - ORTIZ - X04L - 3114013
#------ GLOBAL VARIABLES ------------------
CC = gcc
CFLAGS=-Wall -std=c11 
outName= appGame
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
HDR=$(wildcard *.h)
#------ MAIN COMPILE ------------------------
$(outName): $(OBJ)
	$(CC) $(CFLAGS) -lncurses -ltinfo $^ -o $@
#------ OBJECT FILE --------------------------
%.o:%.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
#------ PHONY ----------------------------------
.Phony:clean debug Doc Mem_valgrind
#------ CLEAN -----------------------------------
clean:
	rm *.o 
	rm debug
#------ DEBUGGING TARGETS ------------------------
debug:$(OBJ)
	$(CC) $(CFLAGS) -lncurses -ltinfo -g $^ -o debug

Doc: Documentation
	doxygen $^

Mem_valgrind: debug
	valgrind --leak-check=yes ./debug
#------ FIN -----------------------------------------------
