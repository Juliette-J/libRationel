#include "Rational.hpp"

#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <cassert>


/* Constructors */

Rational::Rational(const int &a, const int &b) {
    // 0 exception
    assert(b != 0); 

    // make it irreductible
    if(std::abs(std::gcd(a,b)) != 1) {
        numerator /= std::abs(std::gcd(a,b));
        denominator /= std::abs(std::gcd(a,b));
    }

    // case b < 0
    if(b < 0) {
        numerator = -a;
        denominator = -b;
    }
    else {
        numerator = a;
        numerator = b;
    }
};


/* Operators */ 

Rational Rational::operator+(const Rational &ratio) {
	int numerator = this->numerator*ratio.getDenominator() + this->denominator*ratio.getNumerator();
    int denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}


/* Operations */

Rational pow(const Rational &ratio, const int &power) {
    int pow_numerator = std::pow(ratio.getNumerator(), power);
    int pow_denominator = std::pow(ratio.getDenominator(), power);
    return Rational(pow_numerator, pow_denominator);
}


/* Methods*/

Rational floatToRatio(const float &x, unsigned int nbIter) {
    // keep the sign of x
    int sign;
    (x<0) ? sign = -1 : sign = 1;

    // stop conditions
    if(x==0 || nbIter == 0) {
        return Rational(0,1);
    }
    // decimal part
    else if(x < 1) {
        return pow((floatToRatio(1/x, nbIter)), -1);
    }
    // int part
    else {
        int int_part = std::floor(x);
        return Rational(int_part, 1) + floatToRatio(x-int_part, nbIter-1);
    }
}