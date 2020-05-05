CXXFLAGS = --std=c++17

all: cart

cart: cart.o item.o main.o *.h
	$(CXX) $(CXXFLAGS) cart.o item.o main.o -o cart
cart.o: cart.cpp *.h
	$(CXX) $(CXXFLAGS) cart.cpp -c -o cart.o
item.o: item.cpp *.h
	$(CXX) $(CXXFLAGS) item.cpp -c -o item.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o
clean:
	rm -f *.o *.gch ~* cart


