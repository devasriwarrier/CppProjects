#ifndef ORDER_H
#define ORDER_H

#include "customer.h"
#include "desktop.h"

class Order {
  public:
  Order(Customer& customer);

  friend std::ostream& operator<<(std::ostream& ost, const Order& order);


  virtual ~Order(); // destructor

  int add_product(Desktop& desktop);

  double price() const;

  Order(std::istream& ist);
  void save(std::ostream& ost);




private:
  Customer* customer; 
  std::vector<Desktop*> _products;
};

#endif

