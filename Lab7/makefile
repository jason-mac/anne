all: lab7

lab7: Lab7TestDriver.o Queue.o Profile.o EmptyQueueException.o
	g++ -o lab7 Lab7TestDriver.o Queue.o Profile.o EmptyQueueException.o

# Note, this makefile is very strong in terms of dependencies.
# It assumes most classes can depend on others, just to be safe.
# This results in much redundant compilation, and one could remove some of these dependencies.

Lab7TestDriver.o: Lab7TestDriver.cpp Queue.h Profile.h EmptyQueueException.h
	g++ -c Lab7TestDriver.cpp
	
Queue.o: Queue.cpp Queue.h Profile.h EmptyQueueException.h
	g++ -c Queue.cpp

Profile.o: Profile.cpp Profile.h
	g++ -c Profile.cpp

EmptyQueueException.o: EmptyQueueException.cpp EmptyQueueException.h
	g++ -c EmptyQueueException.cpp

clean:
	rm -f lab7 *.o
