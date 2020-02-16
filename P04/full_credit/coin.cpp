#include "coin.h"
#include "logger.h"



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
