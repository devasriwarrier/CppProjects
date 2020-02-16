#include "coin.h"


std::ostream& operator << (std::ostream & ost, const Coin & coin) {
  return ost;
}

std::istream & operator >> (std::istream & ist, Coin & coin) {
  return ist;
}
