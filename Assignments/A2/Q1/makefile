all: std

std: Stack.o StackTestDriver.o
	g++ -o std Stack.o StackTestDriver.o

Stack.o: Stack.cpp
	g++ -c Stack.cpp

StackTestDriver.o: StackTestDriver.cpp
	g++ -c StackTestDriver.cpp

clean:
	rm -f *.o std
