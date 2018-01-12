# Charles Buyas, cjb8qf, 4-25-16, Makefile

OFILES	= traveling.o middleearth.o

.SUFFIXES: .o .cpp

main:	$(OFILES)
	clang++ -Wall -g $(OFILES)
	doxygen

clean:
	/bin/rm -f *.o *~

#dependencies
middleearth.o: middleearth.cpp middleearth.h
