#include "color.h"

std::string Color::to_string() const {
  rainbow = std::to_string(red) + ";" + std::to_string(green) + ";" + std::to_string(blue);
  return rainbow;
};

//function takes colors and seperates with semicolons, returns rainbow

//void Color::colorize(std::string rainbow2, std::string text) {
 // std::cout << "\033[38;2;" + rainbow2 + ";177m" << text << "\033[0m" << std::endl;
//};

std:: ostream& operator<<(ostream& ost, const Color& color) {
  ost color.to_string();
  return ost;
//do I need to tell the program to stream out ANSI escape code as I did in "\033[38;2;" + rainbow2 + ";177m" << text << "\033[0m"??
}
//where do I put the cout of 38;2;" +red green blue +etc..? is this the cout of ost?

std:: istream& operator>>(std::istream& ist, Color& color) {
  int red, green, blue;
  if (ist >> red >> green >> blue) color = Color(red, green, blue);
  return ist;
}
//no return, passes rainbow and text as it is used in function
