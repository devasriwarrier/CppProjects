#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>
class Color {
  private:

  int red;
  int green;
  int blue;
  
public:
std::string rainbow;

Color( int red, int green, int blue): red(red), green(green), blue(blue)
{};


std::string to_string();

void colorize(std::string rainbow2, std::string text);

};

#endif
