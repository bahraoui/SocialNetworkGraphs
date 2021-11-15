CC=g++
OPT=-Wall
FILES=main.cpp graph.cpp graph.h bronKerbosch.h bronKerbosch.cpp manoussakis.cpp manoussakis.h random.cpp random.h
EXE=executable.out

all:
	clear
	$(CC) $(OPT) $(FILES) -o $(EXE)
	if [ -e $(EXE) ]; then clear; echo 'Compilation bien effectuépour lancer, faites : \n./$(EXE)\n'; fi

clean:
	rm $(EXE)
