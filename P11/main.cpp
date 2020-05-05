#include "cart.h"
#include "item.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

int main(){
Cart cart("Devasri");

std::cout << "enter product names and price" << std::endl;

while(std::cin){
try{
Iten item(" ",0);
std::cin >> item;
cart.add_item(item);}
} catch(std::exception& e){
std::cerr << e.what() << std::endl;}

std::cout<"Register Reciept" <<std::endl;

for(vector<Item*>::iterator p = cart.begin; p!=cart.end(); ++p){
std::cout<<*(*p)<<std::endl;} 
std::string w(25, '=');
std::cout << w <<std::endl;
std::cout<<cart.cost()<<"Total Cost" <<std::endl;

}
