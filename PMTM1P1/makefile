
td:	testDriver.o DataCollection.o 
	g++ -o td -Wall DataCollection.o testDriver.o 

testDriver.o:	testDriver.cpp DataCollection.h 
	g++ -c -Wall testDriver.cpp

DataCollection.o:	DataCollection.cpp DataCollection.h 
	g++ -c -Wall DataCollection.cpp
	
clean:	
	rm -f *.o td
