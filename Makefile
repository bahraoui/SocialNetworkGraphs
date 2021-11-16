CC=g++
OPT=-Wall
MAIN=main.cpp 
EXE=executable.out
DEPS=graph.h bronKerbosch.h bronKerboschPivot.h bronKerboschDegeneracy.h manoussakis.h random.h
PRECOMP=graph.o bronKerbosch.o bronKerboschPivot.o bronKerboschDegeneracy.o manoussakis.o random.o

all: $(PRECOMP)
	clear
	$(CC) $(OPT) $(MAIN) $(PRECOMP) -o $(EXE)
	if [ -e $(EXE) ]; then clear; echo 'Compilation bien effectué\npour lancer, faites : \n./$(EXE)\n'; fi

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm *.o
	rm $(EXE)
