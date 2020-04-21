#include "desktop.h"

Desktop::Desktop() { }

 void Desktop::add_option(Options& option) {
  options.push_back(&option);
};

std::ostream& operator << (std::ostream &ost, const Desktop& desktop) {
int i = 0;
for(i=0; i<desktop.options.size(); i++){
  ost << (desktop.options[i])->to_string();
};
  return ost;
}

void Desktop::save(std::ostream& ost) {
    ost << options.size() << '\n';
    for(auto c : options) c->save(ost);
}

double Desktop::price(){
  double totalprice = 0.0;
  for(int i=0; i<options.size(); i++) {
  totalprice += options[i]->cost();
  }
 return totalprice;
};


Desktop::Desktop(std::istream& ist) {
    int vsize;
    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) options.push_back(new Options{ist});
}

