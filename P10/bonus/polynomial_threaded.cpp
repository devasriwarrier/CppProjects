#include "polynomial.h"
#include <cmath>
#include <thread>
#include <vector>
#include <mutex>

std::mutex m;

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



void Polynomial::solve(double min, double max, int nthreads, double slices, double precision) {
    _roots = {};
    std::vector<std::thread*> threads;
    double range = max - min;
    double workPerThread = range/nthreads;
    double slicesPerThread = slices/nthreads;

    for (int i = 0; i < nthreads; i++) {
      double start = min + (workPerThread * i);
      double end = start + workPerThread;

      threads.push_back(new std::thread{[=]{this->solve_recursive(start, end, i, slicesPerThread, precision);}}); 
std::cout << std::hex << "Task " << i << " has start " << start << " has end "<< end << " has ID " << threads.back()->get_id() << std::endl; 
		} for (auto& t : threads) t->join();
} 

void Polynomial::solve_recursive(double min, double max, int tid, double slices, double precision, int recursions) { 
    Polynomial& f = *this;
    double delta = (max - min) / slices;
    double x1 = min;
    double y1 = f(min);
    double x2 = x1 + delta;
    double y2;

    while(x1 < max) {
std::cout << "Are we here inside this function?" << std::endl;
        y2 = f(x2);
        if(std::signbit(y1) != std::signbit(y2)) {         
            if((abs(f(x1+x2)/2) > precision) && ((x2 - x1) > precision) && (recursions < 20)) {
		m.lock(); 
                solve_recursive(x1, x2, tid, std::min(slices, (x2-x1)/precision), precision, recursions+1); 
             // recurse for more precision
            } else {
	//std::cout << "int string pushing back: " << (x1+x2)/2 << std::endl;
                _roots.push_back((x1+x2)/2);
		m.unlock();
            }
        }
        x1 = x2; 
        x2 = x1 + delta;
        y1 = y2;
    }
}

std::vector<double> Polynomial::roots() {return _roots;}

std::ostream& operator<<(std::ostream& ost, const Polynomial& polynomial) {
    for(auto& t : polynomial._terms) ost << t;
    return ost;
}
