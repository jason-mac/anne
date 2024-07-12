
all: tdQ

tdQ: testDriver_Q.o Event.o EmptyDataCollectionException.o Queue.o BinaryHeap.o
	g++ -o tdQ -Wall testDriver_Q.o Event.o EmptyDataCollectionException.o Queue.o BinaryHeap.o
	
Queue.o: Queue.cpp Queue.h
	g++ -c -Wall Queue.cpp 

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.h
	g++ -c -Wall BinaryHeap.cpp

testDriver_Q.o: testDriver_Q.cpp Queue.h BinaryHeap.h 
	g++ -c -Wall testDriver_Q.cpp
	
Event.o: Event.cpp Event.h
	g++ -c -Wall Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h 
	g++ -c -Wall EmptyDataCollectionException.cpp

clean:	
	rm -f tdQ *.o

