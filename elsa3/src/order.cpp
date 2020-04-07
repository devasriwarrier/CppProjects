#include "customer.h"
#include "order.h"
#include "desktop.h"
#include "options.h"
#include "store.h"
#include <vector>

Order:: Order(Customer& customer): customer{customer}
{};

std::ostream& operator << (std::ostream &ost, const Order& order) {
    ost << "Customer: " << order.customer;
    for(auto p : order._products) ost << "\n  " << *p;
    ost << "\nTotal price: $" << order.price();
    return ost;

/*for (auto i = order._products.begin(); i != order._products.end(); ++i)
    ost << *i;
  return ost;
*/
};

Order::~Order(){};

int Order::add_product(Desktop& desktop){
_products.push_back(&desktop);
return _products.size()-1;
}; 

double Order::price() const {
    double pr = 0;
    for(auto p : _products) pr += p->price();
    return pr;
}
