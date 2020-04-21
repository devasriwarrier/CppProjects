 #include "customer.h"
#include "order.h"
#include "desktop.h"
#include "options.h"
#include "store.h"


Options::Options(std::string Name, double Cost): _name{Name}, _cost{Cost} {};

std::ostream& operator << (std::ostream &ost, const Options& option) {
    ost << option.to_string();
    return ost;
}

  Options::~Options(){};

std::string Options::to_string() const{
std::string op;
  op = _name + " ($" + std::to_string(_cost) + ")";

};

double Options::cost(){
return _cost;
};

void Options::save(std::ostream& ost) {
    ost << _name << '\n' << _cost << '\n';
}

Options::Options(std::istream& ist) {
    std::getline(ist, _name);
    ist >> _cost; ist.ignore(32767, '\n');
}

