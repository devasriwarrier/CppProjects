CXXFLAGS = --std=c++17

all: coin

logger: CXXFLAGS += -DLOGGER
logger: coin

rebuild: clean coin

coin: test.o coin.o *.h
	$(CXX) $(CXXFLAGS) test.o coin.o -o coin
test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
coin.o: coin.cpp
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o
clean:
	rm -f *.o *.gch *~ coin
	##I hope this is a correct and good makefile???????????????????//
