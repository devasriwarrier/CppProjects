#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>

class Color {
  public:
  std::string rainbow;

  Color( int red, int green, int blue): red(red), green(green), blue(blue)
{};
  //constructor using initialization list and empty body

  std::string to_string() const;
  friend std::ostream& operator<<(std::ostream& ost, const Color& color);
  friend std::istream& operator>>(std::istream& ost, Color& color);

  //void colorize(std::string rainbow2, std::string text);
//};
  //function with no return
  private:

  int red;
  int green;
  int blue;

#endif
