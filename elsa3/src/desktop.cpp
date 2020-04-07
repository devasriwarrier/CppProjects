#include "customer.h"
#include "order.h"
#include "desktop.h"
#include "options.h"
#include "store.h"


 void Desktop::add_option(Options& option) {
  //double totaloptions = 0;
  options.push_back(&option);
};

std::ostream& operator << (std::ostream &ost, const Desktop& desktop) {
int i = 0;
for(i=0; i<desktop.options.size(); i++){
  ost << (desktop.options[i])->to_string();
};
  return ost;
}

double Desktop::price(){
  double totalprice = 0.0;
 
  for(int i=0; i<options.size(); i++) {
  totalprice += options[i]->cost();
  }
 return totalprice;
};
