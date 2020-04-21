#include "customer.h"
#include "order.h"
#include "desktop.h"
#include "options.h"
#include "store.h"
#include <vector>

Order::Order(Customer& customer): customer{&customer} {}

Order::~Order(){};

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

void Order::save(std::ostream& ost) {
    customer->save(ost);
    ost << _products.size() << '\n';
    for (auto p : _products) p->save(ost);
}

int Order::add_product(Desktop& desktop){
_products.push_back(&desktop);
return _products.size()-1;
}; 

double Order::price() const {
    double pr = 0;
    for(auto p : _products) pr += p->price();
    return pr;
}


Order::Order(std::istream& ist) {
    customer = new Customer{ist};
    int vsize;
    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) _products.push_back(new Desktop{ist});
}


