# Charles Buyas, cjb8qf, 3-13-17, Makefile

CXXFLAGS=-O2 -Wall
CXX=clang++ $(CXXFLAGS)
DEBUG=-g
OFILES= wordPuzzle.o hashtable.o timer.o
.SUFFIXES: .o .cpp

wordPuzzle: $(OFILES)
	$(CXX) $(OFILES)
	@echo "Done."

wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp

hashtable.o: hashtable.cpp hashtable.h
	$(CXX) -c hashtable.cpp

timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp


clean:
	-rm -f *.o *~ wordPuzzle
