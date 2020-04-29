#include "term.h"
#include <cmath>
#include <locale>
#include <codecvt>
#include <iostream>						
#include <fstream>

Term::Term(double coefficient, double exponent) : _coeff{coefficient}, _exp{exponent} { }
Term::Term(std::istream& ist) {ist >> _coeff >> _exp;}
void Term::save(std::ostream& ost) {ost << _coeff << ' ' << _exp << '\n';}
double Term::eval(double x) {return _coeff * pow(x, _exp);}

std::ostream& operator<<(std::ostream& ost, const Term& term) {
    if     (term._coeff ==  0) return ost;
    else if(term._coeff == -1) ost << '-';
    else if(term._coeff ==  1) ost << '+';
    else if(term._coeff  >  0) ost << '+' << term._coeff;
    else                       ost << term._coeff;

    if(term._exp == 0) return ost;
    ost << 'x';

    if(term._exp == 1) return ost;

    // EXTREME BONUS: Print the exponent as Unicode exponent characters
    //   found at https://en.wikipedia.org/wiki/Unicode_subscripts_and_superscripts

    ost << '^' << term._exp;
	/*std::wcout << L"hello\x00B2!" << std::endl;
	std::wcout << L"O\x00B3 x\x2080 + x\x2081 + x\x2082" << std::endl;
	std::wcout << L"x\x2083\x208A\x2084" << std::endl;
	std::wcout << L"\x20AC Euro!" << std::endl;
	std::wcout << L"2\x2077\x207B\x2079" << std::endl;
*/
    return ost;

}
