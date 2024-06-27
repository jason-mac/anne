all: ttd

ttd: templateTestDriver.o List.h Node.h ElementDoesNotExistException.o UnableToInsertException.o EmptyListException.o
	g++ -Wall -o ttd templateTestDriver.o ElementDoesNotExistException.o UnableToInsertException.o EmptyListException.o
	
templateTestDriver.o: templateTestDriver.cpp
	g++ -Wall -c templateTestDriver.cpp 

ElementDoesNotExistException.o: ElementDoesNotExistException.cpp ElementDoesNotExistException.h
	g++ -Wall -c ElementDoesNotExistException.cpp

UnableToInsertException.o: UnableToInsertException.cpp UnableToInsertException.h
	g++ -Wall -c UnableToInsertException.cpp
		
EmptyListException.o: EmptyListException.cpp EmptyListException.h 
	g++ -Wall -c EmptyListException.cpp
	
clean:
	rm -f ttd *.o

