#include "color.h"

int main() {
  Color red(255, 0, 0);
  Color green(0, 255, 0);
  Color blue(0, 0, 255);

  int r, g, b;
  std::string temp1, temp2, temp3;
  std::string temp = "Red";
  std::string temp4 = "Green";
  std::string temp5 = "Blue";

  //all of temps (1,2,3,6) are holding return output from to_string function

  temp1 = red.to_string();
  temp2 = green.to_string();
  temp3 = blue.to_string();

  red.colorize(temp1, temp);
  green.colorize(temp2, temp4);
  blue.colorize(temp3, temp5);

  std::cout << "Please enter 3 integer values representing red, green, blue (spaces inbetween): ";
  std::cin >> r >> g >> b;

  std::string output = "(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";

  std::string temp6;

  Color color(r, g, b);
  temp6 = color.to_string();
  color.colorize(temp6, output);

  return 0;
}
