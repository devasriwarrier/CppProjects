#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "cart.h"
#include <string>
#include <iterator>
#include <vector>

class Item{
  public:

  Item(std::string name, double price);
  double cost();
  friend std::ostream& operator<<(std::ostream& ost, const Item& item);
  friend std::istream& operator>>(std::istream& ist, Item& item);

  private:
  std::string _name;
  double _price;
};

#endif
