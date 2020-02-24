#ifndef TAXFREE_H
#define TAXFREE_H

#include <iostream>
#include "product.h"
#include "taxed.h"
#include <string>

class Taxfree: public Product {
  public:

  Taxfree(std::string Name, double Cost);

  ~Taxfree();

  const double price() override;

};

#endif
