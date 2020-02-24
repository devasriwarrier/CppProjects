#include "product.h"
#include "taxed.h"
#include "taxfree.h"

Taxfree::Taxfree(std::string Name, double Cost): Product(Name, Cost){};

Taxfree::~Taxfree(){

};

const double Taxfree::price(){
  double totalprices;
  totalprices = _quantity * _cost;
  return totalprices;
};
