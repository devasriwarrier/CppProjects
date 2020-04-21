#include "store.h"
#include "desktop.h"
#include "options.h"
#include "customer.h"
#include "order.h"


  void Store::add_customer(Customer& customer){
  customers.push_back(customer);
}; //pushes the parameter onto the vector

  int Store:: num_customers(){
  return customers.size();
}; //which returns the size() method of the vector

  Customer& Store::customer(int index){
  return customers.at(index);
}; //returns a reference to the object in the vector at the index provided as a parameter.
  
  void Store:: add_option(Options& option){
  options.push_back(&option); //maybe&
}; //pushes the parameter onto the vector
 
  int Store:: num_options(){ 
  return options.size();
}; //which returns the size() method of the vector

  Options& Store::option(int index){
  return *options.at(index);
}; //returns a reference to the object in the vector at the index provided as a parameter.

  int Store::new_desktop(){
  Desktop* desktop = new Desktop();
  desktops.push_back(*desktop);
  return desktops.size()-1;
}; //which pushes a new object onto the vector and returns its index. The index is used to add options to the new desktop or desktops to the new order. !?????????????????

  void Store::add_option(int option, int desktop){
  Options& choice = this->option(option);
  Desktop& computer = this->desktop(desktop);
  computer.add_option(choice);
  
}; // which is given the index of the option to add to the desktop at the provided index / the index of the desktop to add to the order at the provided index. Thus, these two methods are used to add an existing option / desktop to an existing desktop / order !???????

  int Store::num_desktops(){
  return desktops.size();
};

  Desktop& Store:: desktop(int index){
  return desktops.at(index);
};

//^^work exactly like num_customers and customer, enabling a 3-term for loop that iterates over each vector element.

  int Store::new_order(int customer){
  Customer& c = this->customer(customer);
  Order* order = new Order(c);
  orders.push_back(*order);
  return orders.size()-1;

}; //which pushes a new object onto the vector and returns its index. The index is used to add options to the new desktop or desktops to the new order.

  void Store::add_desktop(int desktop, int order){
  Order& o = this->order(order);
  Desktop& d = this->desktop(desktop);
  o.add_product(d);
 
}; // which is given the index of the option to add to the desktop at the provided index / the index of the desktop to add to the order at the provided index. Thus, these two methods are used to add an existing option / desktop to an existing desktop / order

  int Store::num_orders(){
  return orders.size();
};

  Order& Store::order(int index){
  return orders.at(index);
};

//^^work exactly like num_customers and customer, enabling a 3-term for loop that iterates over each vector element.
  
  
void Store::save(std::ostream& ost) {
    ost << ELSA_COOKIE << "\n";
    ost << ELSA_FILE_VERSION << "\n";

    ost << customers.size() << '\n';  
    for(auto c : customers) c.save(ost);

    ost << options.size() << '\n';
    for(auto o : options) o->save(ost);

    ost << desktops.size() << '\n';
    for(auto d : desktops) d.save(ost);

    ost << orders.size() << '\n';
    for(auto o : orders) o.save(ost);

   // ost << ram.size() << '\n';
   // for(auto o : ram) o.save(ost); //dont know about this
}

Store::Store(){}
Store::Store(std::istream& ist) {

    std::string s;
    int vsize;

    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) orders.push_back(Order{ist});
    if(!ist) throw std::runtime_error{"Bad Data"};

    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) customers.push_back(Customer{ist});
    if(!ist) throw std::runtime_error{"Bad Data"};

    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) desktops.push_back(Desktop{ist});
    if(!ist) throw std::runtime_error{"Bad Data"};

    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) options.push_back(new Options{ist});
    if(!ist) throw std::runtime_error{"Bad Data"};

    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) options.push_back(new Options{ist});
    if(!ist) throw std::runtime_error{"Bad Options Data"};

  //  ist >> vsize; ist.ignore(32767, '\n');
  //  while(vsize--) ram.push_back(new Ram{ist});
  //  if(!ist) throw std::runtime_error{"Bad Ram Data"}; //not sure

}
