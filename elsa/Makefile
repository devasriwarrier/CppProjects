CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: elsa 

elsa: main.cpp mainwin.cpp entrydialog.cpp customer.cpp options.cpp desktop.cpp order.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp entrydialog.cpp customer.cpp options.cpp desktop.cpp order.cpp $(GTKFLAGS) -o elsa
clean:
	rm -f *.o *.gch elsa
