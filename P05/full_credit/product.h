#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
  public:

  Product(std::string Name, double Cost);

  ~Product(); //virtual destructor

  int set_quantity (int quantity);

  virtual const double price() = 0; //pure virtual bc set to 0

  friend std::ostream& operator<<(std::ostream& ost, const Product& product);

protected:
  int _quantity; //# of products purchase
  double _cost; //cost pre-tax
  std::string _name; //product for sale
};

#endif
