#include "coin.h"
#include "logger.h"


Coin::Coin(Coin_size Size, Year Yr): _size{Size}, _year{Yr}, _notes{nullptr} {
  LOG("Coin::Coin");
}; // non default constructor

Coin::Coin(const Coin &rhs) : _size{rhs._size}, _year{rhs._year}, _notes{nullptr} {
LOG("Coin::Coin copy constructor");
}; //copy constructor


Coin& Coin::operator = (const Coin& rhs) {
  //copy assignment
  if (this != &rhs) {
    _size = rhs._size;
   _year = rhs._year;
   LOG("Coin::operator=");
 }
  return *this;
};


Coin::~Coin() {
if(_notes){
delete _notes;
}
LOG("Coin::~Coin");
};//destructors

void Coin::add_note(std::string s) {
  if (!_notes) _notes = new std::string;
  *_notes += s;
};

std::ostream& operator <<(std::ostream& ost, const Coin & coin){
std::string us_coin;

if (coin._size==Coin_size::PENNY) {
  us_coin = "PENNY";
}
else if (coin._size==Coin_size::NICKEL) {
  us_coin = "NICKEL";
}
else if (coin._size==Coin_size::DIME) {
  us_coin = "DIME";
}
else (coin._size==Coin_size::QUARTER); {
  us_coin = "QUARTER";
}
ost << coin._year << " " << us_coin << std::endl;
//how to print out enum classcoin._size << std::endl;
ost << *coin._notes;
return ost;
};

std::istream& operator >> (std::istream & ist, Coin& coin){
  //int y,s;
  //ist >> y >> s >> std::endl;
//  coin = Coin {y,s};
  return ist;
}
