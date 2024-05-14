all: ca

ca: circle_array.o Circle.o
	g++ -Wall -o ca circle_array.o Circle.o

Circle.o: Circle.h Circle.cpp
	g++ -Wall -c Circle.cpp

Circle_array.o: circle_array.cpp Circle.h
	g++ -Wall -c circle_array.cpp

clean:
	rm -f ca *.o
