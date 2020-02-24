#ifndef TAXED_H
#define TAXED_H

#include <iostream>
#include "product.h"
#include "taxfree.h"
#include <string>

class Taxed:public Product{
  public:

  Taxed(std::string Name, double Cost);

  ~Taxed();

 const double price();

 static void set_tax_rate(double sales_tax);


  private:
  static double tax;

};

#endif
