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

//
// F I L E   I / O
//

void Customer::save(std::ostream& ost) {
    ost << _name << '\n' << _phone << '\n' << _email  << '\n';
} 

Customer::Customer(std::istream& ist) {
    std::getline(ist, _name);
    std::getline(ist, _phone);
    std::getline(ist, _email);
}
