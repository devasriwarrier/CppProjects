#ifndef COIN_H
#define COIN_H

#include <iostream>
#include <string>
/*when your class allocates memory from the
heap, keeping a pointer to its address
● To copy the object, you also need to “deep copy” the allocated
heap memory to another heap memory area
● To assign the object, you need to deallocate the existing heap
memory before doing the “deep copy” to allocate the new heap
memory
● To delete the object, you also need to delete the heap memory
*/


enum class Coin_size {PENNY, NICKEL, DIME, QUARTER};
/*std::ostream& operator <<(std::ostream& ost, Coin_size & c){
if(c == Coin_size::PENNY) {
ost << "Penny";
}
else {
ost << "test";
}
return ost;
};
*/
typedef int Year;
class Coin {
  public:

  Coin(Coin_size Size, Year Yr);

  Coin(const Coin &rhs); //copy constructor

  Coin& operator = (const Coin& rhs); //copy assignment

  ~Coin(); //destructor

  void add_note(std::string s);

  friend std::ostream& operator<<(std::ostream& ost, const Coin& coin);
  friend std::istream& operator>>(std::istream& ist, Coin& coin);

  private:
  Coin_size _size;
  Year _year;
  std::string* _notes;
};

#endif
