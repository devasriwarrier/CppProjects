#include "color.h"
#include "logger.h"

int main()
{
  Coin Penny{0.01, 2006, history};
  Coin Nickel{0.05, 2008, history2};
  Coin Dime{0.1, 2010, history3};
  Coin Quarter{0.25, 2012, history4};
//coin objects

  //something with constructor
  LOG("Coin::Coin");

  std::string str_red = "Ruby Red";
  std::string str_green = "Great Green";
  std::string str_blue = "Beautiful Blue";

  std::cout << red << str_red << std::endl; //std::cout << red goes to operator, and op func changes color to red
  std::cout << green << str_green << std::endl;
  std::cout << blue  << str_blue << grey << std::endl;
  //  blue.colorize(temp3, temp5);

  std::cout << "Please enter 3 integer values representing red, green, blue (spaces inbetween): ";
  //prints to user, cin takes in r g b values respectivley
  Color user_color; //object after variable, defined after user entered values   //object of color which user entered
  std::cin >> user_color; //istream function
  //std::string output = "(" + std::to_string(user_color.r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
  //to string of user input, seperated by "," and entire result stored into "output"

  std::cout  << user_color << user_color.print_string() << std::endl; //ostream function
  return 0;
}
