#include "Rational.hpp"

#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <cassert>


/* Constructors */

Rational::Rational(const int &a, const int &b) {
    // 0 exception
    if(b == 0) {
        if(a==1) {
            std::cout << "You reached the infinite !" << std::endl;
            numerator = 1;
            denominator = 0;
        }
        else {
            std::cout << "It's impossible to divide by 0 ! We let you to 0." << std::endl;
            numerator = 0;
            denominator = 1;
        }
    }

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
        denominator = b;
    }
};


/* Operators */ 

Rational Rational::operator+(const Rational &ratio) {
	int numerator = this->numerator*ratio.getDenominator() + this->denominator*ratio.getNumerator();
    int denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

Rational Rational::operator*(const Rational &ratio) {
	int numerator = this->numerator*ratio.getNumerator();
    int denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
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
        return power((floatToRatio(1/x, nbIter)), -1);
    }
    // int part
    else {
        int int_part = std::floor(x);
        return Rational(int_part, 1) + floatToRatio(x-int_part, nbIter-1);
    }
}

/* Operations */

Rational power(const Rational &ratio, const int &power) {
    int pow_numerator = std::pow(ratio.getNumerator(), power);
    int pow_denominator = std::pow(ratio.getDenominator(), power);
    return Rational(pow_numerator, pow_denominator);
}