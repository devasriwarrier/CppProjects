#include "ram.h"
#include "options.h"


    Ram:: Ram(std::string Name,double Cost, int gb) : Options(Name,Cost), _gb{gb} {}
    Ram::~Ram(){}

    Ram::Ram(std::istream& ist) : Options(ist){
    ist >> _gb; }

    std::string Ram::to_string() const  {
	static_cast<Ram>(*this)._gb;
}

   void Ram::save(std::ostream& ost){
	//ost << static_cast<Options>(*this) <<' ' << _gb;
    Options::save(ost);
    ost<< _gb << "\n";
} 



