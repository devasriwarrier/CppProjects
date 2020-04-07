#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "desktop.h"

class Order {
  public:
  Order(Customer& customer);

  friend std::ostream& operator<<(std::ostream& ost, const Order& order);


  ~Order(); // destructor

  int add_product(Desktop& desktop);

  double price() const;

	Order(std::ostream&);

	void Save(std::ostream&);


private:
  Customer& customer; 
  std::vector<Desktop*> _products;
};

#endif
