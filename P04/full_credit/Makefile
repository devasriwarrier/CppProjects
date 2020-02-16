CXXFLAGS = --std=c++17

all: coin

coin: main.o coin.o *.h
	$(CXX) $(CXXFLAGS) main.o coin.o -o coin
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
coin.o: coin.cpp
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o
clean:
	rm -f *.o *.gch ~* a.out coin
	##I hope this is a correct and good makefile
