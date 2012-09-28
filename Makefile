CC=g++
LINX=../linx-2.5.1


linxpp.o: linxpp.cpp
	g++ -c linxpp.cpp -I. -I$(LINX)/include  -o linxpp.o

test: linxpp.o test.cpp
	g++ -I. -I$(LINX)/include test.cpp linxpp.o -L$(LINX)/lib -llinx -o test

all: test

clean:
	rm *.o test
