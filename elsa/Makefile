
CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

elsa: main.o mainwin.o store.o entrydialog.o 
	$(CXX) $(CXXFLAGS) main.o mainwin.o store.o entrydialog.o $(GTKFLAGS) -o elsa
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o
entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp -o entrydialog.o
clean:
	rm -f *.o *.gch elsa

OR

CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: elsa 

elsa: main.cpp mainwin.cpp entrydialog.cpp customer.cpp options.cpp desktop.cpp order.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp entrydialog.cpp customer.cpp options.cpp desktop.cpp order.cpp $(GTKFLAGS) -o hello
clean:
	rm -f *.o *.gch elsa
