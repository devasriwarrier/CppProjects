CXXFLAGS = --std=c++17

all: coin

logger: CXXFLAGS += -DLOGGER
logger: coin

rebuild: clean coin

coin: test.o coin.o *.h
	$(CXX) $(CXXFLAGS) -DLOGGER test.o coin.o -o coin
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -DLOGGER test.cpp -c -o test.o
coin.o: coin.cpp *.h
	$(CXX) $(CXXFLAGS) -DLOGGER coin.cpp -c -o coin.o
clean:
	rm -f *.o *.gch *~ coin
	##I hope this is a correct and good makefile???????????????????//
