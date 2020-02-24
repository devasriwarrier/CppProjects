#include "product.h"
#include "taxed.h"
#include "taxfree.h"


Product::Product(std::string Name, double Cost): _name{Name}, _cost{Cost}, _quantity{0} {
//  if(_cost =< -.01){
    //runtime error in cpp
  //}
};

Product::~Product() {
};//destructor

int Product::set_quantity (int quantity) {
  _quantity = quantity;
  return _quantity;
};

std::ostream& operator <<(std::ostream& ost, const Product& product){

  if (product._quantity == 0) {
    ost << product._name << " " << "(" << "$" << product._cost << ")" << std::endl;
    //use end of line
  } else if (product._quantity <= 1) {
    ost << product._name << " " << "(" << product._quantity << "@" << "$" << product._cost << ")" << std::endl;
  }
  return ost;
};
