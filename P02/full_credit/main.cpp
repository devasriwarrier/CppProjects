#include "color.h"

int main() {
  Color red(255, 0, 0);
  Color green(0, 255, 0);
  Color blue(0, 0, 255);
//color objects

  int r, g, b;
  std::string temp1, temp2, temp3;
  std::string temp = "Red";
  std::string temp4 = "Green";
  std::string temp5 = "Blue";

  //all of temps (1,2,3,6) are holding return output from to_string function (rainbow)

  temp1 = red.to_string();
  temp2 = green.to_string();
  temp3 = blue.to_string();
//puts to_string of red into temp1. same logic respectivley for green into temp 2 and blue into temp 3

  red.colorize(temp1, temp);
  green.colorize(temp2, temp4);
  blue.colorize(temp3, temp5);
//value of temp - "Red" text, to stringed(function) of temp1, made it red colored (colorize function). same logic for green and blue (read backwards)

  std::cout << "Please enter 3 integer values representing red, green, blue (spaces inbetween): ";
  std::cin >> r >> g >> b;
  //prints to user, cin takes in r g b values respectivley 

  std::string output = "(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
  //to string of user input, seperated by "," and entire result stored into "output"

  std::string temp6;
  //temp string initialized

  Color color(r, g, b); 
  //object of color which user entered

  temp6 = color.to_string();
  //tostring of object, stored into temp6

  color.colorize(temp6, output); 
  //string of user input, to string, 

  return 0;
}
