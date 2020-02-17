#include "coin.h"
#include "logger.h"


Coin(Coin_size Size, Year Yr): _size{Size}, _year{Yr}, _notes{nullptr} {
  LOG("Coin::Coin");
}; // non default constructor

Coin(const Coin &rhs) : _size{rhs.Size()} _year{rhs.Year()} _notes = {new string{*(rhs._notes)}} {
LOG("Coin::Coin copy constructor");
}; //copy constructor


Coin& operator = (const Coin& rhs) {
  //copy assignment
  if (this != &rhs) _size = new Coin_size{*(rhs.Size())} _year = new Year{*(rhs.Year())LOG("Coin::operator=")};
  return *this;
};

Coin_size Size() {return _size;};
Year Year() {return _year;}; //add in h file

Coin::~Coin() {delete _notes}LOG("Coin::~Coin"); //destructorssss

std::string add_note() {
  if (!_notes) _notes = new string;
};

std::ostream& operator << (std::ostream & ost, const Coin & coin) {
  if (coin._size == .01) { //sets boolean to true, == does it twice so bad practice
    ost << coin._year << " " << coin._size <<\n << coin._notes;
  } else if (coin._size == .05) {
  ost << coin._year << " " << coin._size <<\n << coin._notes;
  }
  else if (coin._size == .1) {
  ost << coin._year << " " << coin._size <<\n << coin._notes;
  }
  else if (coin._size == .25) {
  ost << coin._year << " " << coin._size <<\n << coin._notes;
  }
  else {
    std::cout << "program doesnt like that"<< std::endl;
  };
  return ost;
}

std::istream & operator >> (std::istream & ist, Coin & coin) {
  int y, s, h;
  ist >> s >> y >> h;
  coin = Coin {s, y, h};
  return ist;
}
