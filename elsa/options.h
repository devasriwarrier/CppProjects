#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <string>
#include <vector>

class Options {
  public:

  Options(std::string Name, double Cost);

  friend std::ostream& operator<<(std::ostream& ost, const Options& option);

  ~Options();
  virtual std::string to_string() const;

  double cost();

protected:
  std::string _name; 
  double _cost; 
};

#endif
