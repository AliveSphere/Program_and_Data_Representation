#Brady Zhang
#bwz3kt@virginia.edu
#February 27, 2016
#Makefile

CXXFLAGS=-O2 -Wall
CXX=clang++ $(CXXFLAGS)
DEBUG=-g
OFILES= wordPuzzle.o hashTable.o timer.o
.SUFFIXES: .o .cpp

wordPuzzle: $(OFILES)
	$(CXX) $(OFILES)
	@echo "Done."
	
wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp
	
hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp
	
timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp
	
	
clean:
	-rm -f *.o *~ wordPuzzle
