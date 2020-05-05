#ifndef CART_H
#define CART_H

#include <iostream>
#include "item.h"
#include <string>
#include <iterator>
#include <vector>

class Cart{
public:

Cart(std::string customer);

~Cart();

Cart(const Cart& cart);

double cost();

void add_item(Item& item);


Cart& operator=(const Cart& cart);

 

std::vector<Item*>::iterator begin();
std::vector<Item*>::iterator end();

private:
std::string _customer;
std::vector<Item*> _items;
};

#endif
