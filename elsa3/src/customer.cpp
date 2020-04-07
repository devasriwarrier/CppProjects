#include "customer.h"
#include "order.h"
#include "desktop.h"
#include "options.h"
#include "store.h"


Customer::Customer(std::string Name, std::string Phone, std::string Email): _name{Name}, _phone{Phone}, _email{Email}
{};

std::ostream& operator << (std::ostream & ost, const Customer& customer) {
   ost << customer._name <<"("<< customer._phone <<"," << customer._email <<")"; 
  return ost;
}
