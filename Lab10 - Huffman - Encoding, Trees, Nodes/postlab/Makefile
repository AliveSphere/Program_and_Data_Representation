# Charles Buyas, cjb8qf, 4-17-16, Makefile

# Defines the C++ compiler we'll be using
CXX	= clang++

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS	= -Wall -g

# All of the .o files for our program
OFILES	= heap.o huffmanenc.o huffmanTree.o huffmandec.o

all: encoder decoder

# This tells make to create a .o file from a .cpp file, using the
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# This tells make to create a .o file from a .s file, using the
# defaults above (i.e. the AS and ASFLAGS macros)
# .SUFFIXES: .o .s

# How to compile our final program.  Note that we do NOT specify an
# output executable name -- in order for this to work with the grading
# system, the file needs to be a.out (a.exe in Cygwin).
main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	/bin/rm -f *.o *~

# We don't have any dependencies for this small program
heap.o: heap.cpp huffTreeNode.h heap.h

huffmanenc.o: huffmanenc.cpp huffTreeNode.h huffmanTree.h

huffmanTree.o: huffmanTree.cpp huffTreeNode.h heap.h huffmanTree.h

huffmandec.o: huffmandec.cpp huffTreeNode.h

encoder: heap.o huffmanenc.o huffmanTree.o
	$(CXX) -o encoder heap.o huffmanenc.o huffmanTree.o
decoder: huffmandec.o
	$(CXX) -o decoder huffmandec.o
