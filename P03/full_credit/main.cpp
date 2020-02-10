#include "color.h"

int main()
{
  Color red{255, 0, 0};
  Color green{0, 255, 0};
  Color blue{0, 0, 255}; //passing nums sets reset to false bc of way this color constructor is made
  Color grey{}; //default const
//color objects
  std::string str_red = "Red is";
  std::string str_green = "Green is";
  std::string str_blue = "Blue is";

  std::cout << red << str_red << std::endl; //std::cout << red goes to operator, and op func changes color to red
  std::cout << green << str_green << std::endl;
  std::cout << blue  << str_blue << grey << std::endl;
  //  blue.colorize(temp3, temp5);

  std::cout << "Please enter 3 integer values representing red, green, blue (spaces inbetween): ";
  //prints to user, cin takes in r g b values respectivley
  Color user_color; //object after variable, defined after user entered values   //object of color which user entered
  std::cin >> user_color;
  //std::string output = "(" + std::to_string(user_color.r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
  //to string of user input, seperated by "," and entire result stored into "output"

  std::cout  << user_color << user_color.print_string() << std::endl;
  return 0;
}
