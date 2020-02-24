#include "product.h"
#include "taxed.h"
#include "taxfree.h"
#include <vector>
#include <iostream>

int main()
{
  Taxed poptart{"Poptarts", 3.49};
  Taxed oreos{"Oreos", 5.99};
  Taxed icecream{"Ice Cream", 4.95};
  Taxfree milk{"Milk", 2.85};
  Taxfree bread{"Bread", 1.99};
  Taxfree cheese{"Cheese", 0.99};
//tax and taxfree objects
  int quantity;
  int index;
  std::vector <Product*> cart;
  bool menu = true;

  while (menu != false) {
    std::cout << "=====================\n Welcome to the Store\n =====================\n" << std::endl;
    std::cout << "1) Poptarts ($3.49)\n";
    std::cout << "2) Oreos ($5.99)\n";
    std::cout << "3) Ice Cream ($4.95)\n";
    std::cout << "4) Milk ($2.85)\n";
    std::cout << "5) Bread ($1.99)\n";
    std::cout << "6) Cheese ($0.99)\n";
    std::cout << "Enter quantity (0 to exit) and product index:\n\n";
    std::cin >> quantity, index;
    switch (index)
    {
      case 1:
      poptart.set_quantity(quantity);
      cart.push_back(&poptart);
      break;
      case 2:
      oreos.set_quantity(quantity);
      cart.push_back(&oreos);
      break;
      case 3:
      icecream.set_quantity(quantity);
      cart.push_back(&icecream);
      break;
      case 4:
      milk.set_quantity(quantity);
      cart.push_back(&milk);
      break;
      case 5:
      bread.set_quantity(quantity);
      cart.push_back(&bread);
      break;
      case 6:
      cheese.set_quantity(quantity);
      cart.push_back(&cheese);
      break;
    }
  std::cout << "Current Order: \n -------------\n";
  //Taxed::Taxed item;
  //std::cout << ost << std::endl; //not sure?
  //  std:: cout << "Total price:" << poptart.price()  << std::endl; do this with overload
//operator overload of vector... it is objec t
float ordertotal = 0;
for (auto &it: (cart)){
std::cout <<it;
ordertotal += it->price();
}
std::cout << "HELLLOOOOO";
std::cout << ordertotal << "\n";
  }

  return 0;
}
