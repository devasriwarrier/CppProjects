 #include "cart.h"
#include "item.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>

Item(std::string name, double price): _name{name}, _price{price};

double cost(){ return _price;}

std::ostream& operator<<(std::ostream& ost, const Item& item){ ost << "$" << item._price << " " << item._name;}


std::istream& operator>>(std::istream& ist, Item& item){
std::string value;
double Price;

std::getline(ist, value);

try{
Price = std::stod(Price);
}catch (std::exception& e){
	throw custom_exception(ist, Price);
}
item._price = Price;
return ist;
}

