all: td

td: templateTestDriver.o List.o Node.o ElementDoesNotExistException.o UnableToInsertException.o EmptyListException.o 
	g++ -Wall -o td templateTestDriver.o List.o Node.o ElementDoesNotExistException.o UnableToInsertException.o EmptyListException.o 

templateTestDriver.o: templateTestDriver.cpp List.h 
	g++ -Wall -c templateTestDriver.cpp
	
List.o: List.h List.cpp
	g++ -Wall -c List.cpp
		
Node.o: Node.h Node.cpp
	g++ -Wall -c Node.cpp

ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -Wall -c ElementDoesNotExistException.cpp

UnableToInsertException.o: UnableToInsertException.h UnableToInsertException.cpp
	g++ -Wall -c UnableToInsertException.cpp
		
EmptyListException.o: EmptyListException.h EmptyListException.cpp
	g++ -Wall -c EmptyListException.cpp
	
clean:
	rm -f td *.o
