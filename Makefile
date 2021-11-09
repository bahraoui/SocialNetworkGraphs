CC=g++
OPT=-Wall
FILES=graph.cpp graph.h vertices.h
EXE=graph

all: graph.h vertices.h
	$(CC) $(OPT) $(FILES) -o $(EXE)

clean:
	rm $(EXE)