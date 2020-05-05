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
//prof code example
class custom_exception:public std::exception{
public:
custom_exception(std::string s, std::string t){
 _msg = "Invalid price shown: |'"+s+"\' ==> "+"\'"+t+"\'"'}
const char* what() const nonexception override{
return _msg.c_str();}
private: std::string _msg;};


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

