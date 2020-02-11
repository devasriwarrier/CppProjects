#include "color.h"

std::string Color::to_string() const {
  std::string rainbow;
  rainbow = std::to_string(Red) + ";" + std::to_string(Green) + ";" + std::to_string(Blue);
  return rainbow;
};
//function takes colors and seperates with semicolons, returns rainbow

std::string Color::print_string() const {
  std::string rainbow;
  rainbow = "(" + std::to_string(Red) + "," + std::to_string(Green) + "," + std::to_string(Blue) + ")";
  return rainbow;
};
//if reset is true use end line, if false use begining of line
//using color class like operaroor

//std:: is class in std lib, ostream is what is grabbed from lib
std::ostream& operator << (std::ostream & ost, const Color & color) {
  if (color.reset == true) {
    ost << "\033[0m";
    //use end of line
  } else if (color.reset == false) {
    ost << "\033[38;2;" << color.to_string() << ";177m";
  }
  return ost;
}

std::istream & operator >> (std::istream & ist, Color & color) {
  int r, g, b;
  ist >> r >> g >> b;
  color = Color {r, g, b};
  return ist;
}
