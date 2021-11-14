CC=g++
OPT=-Wall
FILES=main.cpp graph.h
EXE=graph.out

all: graph.h
	o='ok'
	clear
	$(CC) $(OPT) $(FILES) -o $(EXE)
	if [ -e $(EXE) ]; then echo '\n\n\nCompilation bien effectué\npour lancer, faites ./$(EXE)'; fi

clean:
	rm $(EXE)
