CXXFLAGS = --std=c++17

all: product

product: product.o taxed.o taxfree.o main.o *.h
	$(CXX) $(CXXFLAGS) product.o taxed.o taxfree.o main.o -o product
product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) product.cpp -c -o product.o
taxed.o: taxed.cpp *.h
	$(CXX) $(CXXFLAGS) taxed.cpp -c -o taxed.o
taxfree.o: taxfree.cpp *.h
	$(CXX) $(CXXFLAGS) taxfree.cpp -c -o taxfree.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o
clean:
	rm -f *.o *.gch ~* product
