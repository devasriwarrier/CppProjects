#include "cart.h"
#include "item.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>

Cart::Cart(std::string customer): _customer{customer}{};

Cart::~Cart(){};

Cart::Cart(const Cart& cart): _customer(cart._customer), _items(cart._items){}


std::vector<Item*> ::iterator Cart::begin(){ return _items.begin();}

std::vector<Item*> ::iterator Cart::end(){return _items.end();}

double Cart::cost(){
int j=0;
double totalcost=0;
for(std::vector<Item*>::iterator p = _items.begin(); p!=_items.end(); ++p){
totalcost+= _items[j]->cost();
j++;}
return totalcost;}

//Cart& operator=(const Cart& cart){};

void Cart::add_item(Item& item){_items.push_back(new Item{item});}



