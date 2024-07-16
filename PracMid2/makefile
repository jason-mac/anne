# Default target
all: main

# Link object files to create the final executable
main: TestDriver.o UnableToInsertException.o BST.o
	g++ -o main TestDriver.o UnableToInsertException.o BST.o

# Compile BST.cpp to BST.o
BST.o: BST.cpp BST.h
	g++ -c BST.cpp -o BST.o

# Compile UnableToInsertException.cpp to UnableToInsertException.o
UnableToInsertException.o: UnableToInsertException.cpp UnableToInsertException.h
	g++ -c UnableToInsertException.cpp -o UnableToInsertException.o

# Compile TestDriver.cpp to TestDriver.o
TestDriver.o: TestDriver.cpp
	g++ -c TestDriver.cpp -o TestDriver.o

# Clean up generated files
clean:
	rm -f *.o main
