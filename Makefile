CC=g++
OPT=-Wall
FILES=graph.cpp graph.h
EXE=graph.out

all: graph.h
	clear
	$(CC) $(OPT) $(FILES) -o $(EXE)

clean:
	rm $(EXE)
