#ifndef DESKTOP_H
#define DESKTOP_H

#include <iostream>
#include <string>
#include <vector>
#include "options.h"

class Desktop {
  public:
  
  void add_option(Options& option);

  friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);

  double price();


	Desktop(std::ostream&);

	void Save(std::ostream&);

private:
  std::vector <Options*> options; 
};

#endif
