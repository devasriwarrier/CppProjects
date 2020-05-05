#include "cart.h"
#include "item.h"
#include <string>
#include <iostream>
#include <iomanip>

int main(){
Cart cart("Devasri");
Iten item(" ",0);

std::cout << "enter product names and price" << std::endl;

while( 1 == 1){
try{
std::cin >> item;
} catch(std::exception& e){
std::cerr << e.what() << std::endl;}
cart.add_item(item);}

std::cout<"Register Reciept" <<std::endl;

for(vector<Item*>::iterator p = cart.begin; p!=cart.end(); ++p){
std::cout<<*(*p)<<std::endl;} 
std::string w(20, '-');
std::cout << w <<std::endl;
std::cout<<cart.cost()<<"Total Cost" <<std::endl;
return 1;
}
