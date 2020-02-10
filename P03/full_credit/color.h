#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>

class Color {
  public:
  Color () {
    reset = true;
  };

  Color( int red, int green, int blue): Red{red}, Green{green}, Blue{blue} {
    reset = false;
  };
  //constructor using initialization list and empty body
  std::string to_string() const;
  std::string print_string() const;
  friend std::ostream& operator<<(std::ostream& ost, const Color& color);
  friend std::istream& operator>>(std::istream& ost, Color& color);
  //void colorize(std::string rainbow2, std::string text);
//};
  private:
  int Red;
  int Green;
  int Blue;
  bool reset;
};
#endif
