#include "coin.h"
#include "logger.h"


Coin::Coin(Coin_size Size, Year Yr): _size{Size}, _year{Yr}, _notes{nullptr} {
  std::cout <<"copy1 constructor" << std::endl;
  LOG("Coin::Coin");
}; // non default constructor

Coin::Coin(const Coin &rhs) : _size{rhs._size}, _year{rhs._year}, _notes{nullptr} {
  std::cout <<"copy2 constructor" << std::endl;
LOG("Coin::Coin copy constructor");
}; //copy constructor


Coin& Coin::operator = (const Coin& rhs) {
  //copy assignment
  if (this != &rhs) {
    _size = rhs._size;
   _year = rhs._year;
  std::cout <<"copyassign constructor" << std::endl;
   LOG("Coin::operator=");
 }
  return *this;
};


Coin::~Coin() {
  std::cout <<"delete constructor" << std::endl;
if(_notes){
delete _notes;
}

LOG("Coin::~Coin"); 
};//destructors

void Coin::add_note(std::string s) {
  std::cout <<"addnotes" << std::endl;
  if (!_notes) _notes = new std::string;
  *_notes += s;
};

//std::ostream& operator <<(std::ostream& ost, const Coin & coin){
//ost << coin._year << " " << coin._size << std::endl;
//ost << coin._notes;
//return ost;
//};
