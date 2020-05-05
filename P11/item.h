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

  private:
  std::string _name;
  double _price;
};

#endif
