#ifndef __RAM_H
#define __RAM_H

#include "options.h"
#include <iostream>
#include <string>

class Ram: public Options {
  public:
    Ram(std::string Name, double Cost, int _gb);
    Ram(std::istream& ist);   // Open
     ~Ram();

    std::string to_string() const override;
    void save(std::ostream& ost)override; // Save


  protected:
    int _gb;
};

#endif
