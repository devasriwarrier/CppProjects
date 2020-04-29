#include "polynomial.h"
#include "logger.h"
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <thread>
#include <pthread.h>
int main() {
    // BONUS: Modify main() to load and solve multiple polynomials
    //    simultaneously using a set of threads for each polynomial.
    //    Note that this will break "make poly", so if you want to
    //    preserve the threadless build, handle that situation, too.

    // Working variables
    double c, e, x;
    int nthreads = 1; // number of threads
    Polynomial f;
    int choice;
    std::vector<Polynomial*> poly;
 	   std::vector<std::thread*> threadz;

    // Load a default polynomial if available
    std::string filename = "untitled.poly";
    try {
        std::ifstream ifs{filename};
        if(!ifs) throw std::runtime_error{"file not found"};
        f = Polynomial(ifs);
        std::cout << "Loaded ";
    } catch(std::exception& e) {
        std::cout << "Failed to load";
    }
    std::cout << filename << ": " << f << std::endl;

    // Main menu
    std::string menu = R"(
   Polynomial Paradise
   ========== ========
1) Load or Enter Polynomial
2) Save Polynomial
3) Evaluate Polynomial
4) Solve Polynomial
0) Exit
==> )";

    // =============================================================
    // Main loop
    do {
        
        std::cout << menu;
        std::cin >> choice; std::cin.ignore(32767, '\n');

        if(choice == 1) {

            std::cout << "Filename (blank to enter by hand): ";
            std::getline(std::cin, filename);
            if(filename.empty()) {
                Polynomial f = Polynomial{};
                do {
                    std::cout << "Enter coefficient then exponent: ";
                    std::cin >> c >> e;
                    f.add_term(c, e);
                } while(e != 0.0);
            } else {
                try {
                    std::ifstream ifs{filename};
                    Polynomial *f =new  Polynomial(ifs);
//trying
      //poly.push_back(new std::poly{[=]{this->solve_recursive(start, end, i, slicesPerThread, precision);}}); //
    		  poly.push_back(f); //
//***********end of my stuff
                    std::cout << "Loaded " << filename << ": " << *f << std::endl;
                } catch(std::exception& e) {
                    std::cerr << "Could not load " << filename << ": " 
                      << e.what() << std::endl;
                }
            }
        } else if(choice == 2) {
            std::cout << "Filename: ";
            std::getline(std::cin, filename);
            if(filename.size()) {
                 try {
                    std::ofstream ofs{filename};
                    f.save(ofs);
                    std::cout << "Saved " << filename << ": " << f << std::endl;
                } catch(std::exception& e) {
                    std::cerr << "Could not save " << filename << ": " 
                      << e.what() << std::endl;
                }
            }
        } else if(choice == 3) {
            do {
                std::cout << "Enter x (0 exits): ";
                std::cin >> x;
                std::cout << "f(" << x << ") = " << f(x) << std::endl;
            } while (x != 0.0);
       } else if(choice == 4) {
std::cout << "Solve between min max (== exits): ";
            std::cin >> c >> e; if(c >= e) break;
            std::cout << "Number of threads: ";
            std::cin >> nthreads;
            LOG("   MAIN: Ready to solve");
            auto start = std::chrono::high_resolution_clock::now(); 
           // f.solve(c, e, nthreads);
//new code*********************************************************************************
	for (int i =0; i < poly.size(); i++){
		Polynomial *P = poly[i];
		threadz.push_back(new std::thread{[=] {P->solve(e, c, nthreads);}});
	 	std::cout << std::hex << " has ID MAIN" << threadz.back()->get_id() << std::endl; 
	}for (auto& t : threadz) t->join(); 
//new code*********************************************************************************
            auto stop = std::chrono::high_resolution_clock::now();
            LOG("   MAIN: Solved!");
            std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() << " seconds\n";
	for(int i=1; i<poly.size(); i++){
std::cout << std::hex << "Task "<<std::endl;
	    	Polynomial P = *poly[i];
            std::vector<double> roots = poly[i]->roots(); //why dont we go into solve_recursive function??? this is why roots vector is EMPTY!

             if(roots.empty()) {
                std::cout << "No roots found!\n";
            } else {
                std::ios cout_state(nullptr);
                cout_state.copyfmt(std::cout);
                std::cout << std::fixed << std::setprecision(16);

                std::cout << "\nx = \n";
                for(double r : roots) {
                    std::cout << "    " << std::setw(21) << r << " f(x) = " << std::setw(21) << P(r) << std::endl;
                }
                std::cout.copyfmt(cout_state);
            }
}
        } else {
            if(choice != 0) std::cerr << "INVALID CHOICE\n";
        }
    } while(choice != 0);

}
