#include "customer.h"
#include "order.h"
#include "desktop.h"
#include "options.h"
#include "store.h"
#include <vector>

Order:: Order(Customer& customer): customer{customer}
{};

std::ostream& operator << (std::ostream &ost, const Order& order) {
for (auto i = order._products.begin(); i != order._products.end(); ++i)
    ost << *i;
  return ost;
};

Order::~Order(){};

int Order::add_product(Desktop& desktop){
_products.push_back(&desktop);
return _products.size()-1;
}; 

double Order::price(){
  double totalprice = 0.0;
 
  //for( int i=0; i<_products.size(); i++) {
 // Desktop& d = _products[i];
 // totalprice += d.price();
 // }
 return totalprice;
};
