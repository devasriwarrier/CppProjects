#include "product.h"
#include "taxed.h"
#include "taxfree.h"

double Taxed::tax = 0.0825;

Taxed::Taxed(std::string Name, double Cost): Product(Name, Cost){};

Taxed::~Taxed() {};

 void Taxed::set_tax_rate(double sales_tax){
    tax = sales_tax;
//  return tax;
 };

 const double Taxed:: price() {
  double totalprice;
  totalprice = _quantity * _cost * (1 + tax);
  return totalprice;
};
