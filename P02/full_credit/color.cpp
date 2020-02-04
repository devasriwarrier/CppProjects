#include <iostream>
#include <string>
class Color {
  int red;
  int green;
  int blue;
  
public:
std::string rainbow;

Color( int red, int green, int blue): red(red), green(green), blue(blue)
{
  //std::cout<<to_string();
};


std::string to_string()
{
  rainbow = std::to_string(red)+";"+std::to_string(green)+";"+std::to_string(blue);
  return rainbow;
};

std::string colorize(std::string text)
{
  std::cout << "\033[38;2;"+rainbow+";177m"<< text<< "\033[0m" <<std::endl;

};

};


int main() { 
Color red(255,0,0);
Color green(0,255,0);
Color blue(0,0,255);

  int r, g, b;
red.to_string();
green.to_string();
blue.to_string();

std::cout << red.colorize("Red") << std::endl;
std::cout << green.colorize("Green") << std::endl;
std::cout << blue.colorize("Blue") << std::endl;

std::cout << "Please enter 3 integer values representing red, green, blue (spaces inbetween): ";
std::cin>>r>>g>>b;
std::string output = "(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";

//std::cout<< output<<std::endl;

Color color(r,g,b);
color.to_string();
std::cout << color.colorize(output) << std::endl;

}
