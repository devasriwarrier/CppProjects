#include "polynomial.h"
#include <cmath>
#include <thread>
#include <vector>

Polynomial::Polynomial() { }
Polynomial::Polynomial(std::istream& ist) {
    int tsize; ist >> tsize;
    while(tsize--) _terms.push_back(Term{ist});
}
void Polynomial::save(std::ostream& ost) {
    ost << _terms.size() << '\n';
    for(auto t : _terms) t.save(ost);
}

void Polynomial::add_term(double coefficient, double exponent) {
    _terms.push_back(Term{coefficient, exponent});
}
double Polynomial::operator()(double x) {
    double y = 0.0;
    for(auto t : _terms) y += t.eval(x);
    return y;
}

// FULL CREDIT
// Modify solve and solve_recursive to split the range [min,max] 
//   into distinct ranges [min, min+(max-min)/slices] ... [max-(max-min)/slices, max]
//   and run solve_recursive once per range, **each as a thread**
// Then complete the questionaire in file results.txt and commit with your code

// Clear the roots and invoke recursive solution search
//   nthreads is the number of threads requested
//   tid is a thread id - useful for logger.h messages

//MEANING: we have a range of numbers... min 1 max 100. If i want 10 slices, splitting the range into 10 slices
//when you work itersvly through increasing values of x, at some point the sign of the polynomial changes 
//and that is where the solution is. thats the point of min.max 
//solve tells you where to start and end searching, how many slices precision needed. check for sign change between each slice
//


//void Polynomial::solve(double min, double max, int nthreads, double slices, double precision) {
 //   _roots = {};
//  solve_recursive(min, max, 1, slices, precision);
//}

void Polynomial::solve(double min, double max, int nthreads, double slices, double precision) {
    _roots = {};

    std::vector<std::thread*> threads;

    double range = max - min;
    double workPerThread = range/nthreads;
    double slicesPerThread = slices/nthreads;
    for (int i = 0; i < nthreads; i++) {
//attepmt 1
      double start = min + (workPerThread * i);
      double end = start + workPerThread ;

      threads.push_back(new std::thread{[start, end, i, slicesPerThread, precision] { Polynomial f; f.solve_recursive(start, end, i, slicesPerThread, precision);}});
//attempt 2
   // Polynomial& f = *this;
    //threads.push_back(new std::thread{&Polynomial::solve_recursive, f, start, end, i, slicesPerThread, precision});
//attepmt 3
    //threads.push_back(new std::thread{[min, max, i, slices, precision] { Polynomial f; f.solve_recursive(min, max, i, slices, precision);}});
        std::cout << "Task " << i << " has start " << start << " has end "<< end << std::endl;
    }

    for (auto& t : threads) t->join();
} 

//where to start ans where to end searching. 
// (Internal) recursive search for polynomial solutions
void Polynomial::solve_recursive(double min, double max, int tid, double slices, double precision, int recursions) { //
    Polynomial& f = *this;
    double delta = (max - min) / slices;
    double x1 = min;
    double y1 = f(min);
    double x2 = x1 + delta;
    double y2;

    while(x1 < max) {
        y2 = f(x2);
        if(std::signbit(y1) != std::signbit(y2)) {
            if((abs(f(x1+x2)/2) > precision) && ((x2 - x1) > precision) && (recursions < 20)) {
                solve_recursive(x1, x2, tid, std::min(slices, (x2-x1)/precision), precision, recursions+1); 
// recurse for more precision
            } else {
//problem 2 with data
	std::cout << "int string pushing back: " << (x1+x2)/2 << std::endl;
                _roots.push_back((x1+x2)/2);
            }
        }
        x1 = x2; 
        x2 = x1 + delta;
        y1 = y2;
    }
}
// recurse for more precision . //solutions somewhere between x1 and x2 so call recursive again make x1 x2 as min max and solve further until precision is specified 
//calls itself line 41 if precision is not high enough
//FIX SOLVE, divide range min to max into threads that divide that range. EX 10 threads, min 0 max 10. create one thread looks from 0-1, another that looks 1-2, 2-3 and so on. each threads gets portion of range to search
//divide slices by n threads so esch thread isnt searching same number of slices 
//only 1 place to change in solve recursive. data protection issue

std::vector<double> Polynomial::roots() {return _roots;}

std::ostream& operator<<(std::ostream& ost, const Polynomial& polynomial) {
    for(auto& t : polynomial._terms) ost << t;
    return ost;
}



