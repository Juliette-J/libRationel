#include <iostream>
#include <numeric>
#include <cmath>

#ifndef RATIONNELS_HPP
#define RATIONNELS_HPP

template<typename T = int>
class Rational {
    private :
        T numerator;
        T denominator;

    public :
        /* ---------------- Constructors ---------------- */
        Rational(const T &a = 1, const T &b = 1);
        Rational(const Rational &r) = default; // by copy

        /* ---------------- Destructor ---------------- */
        ~Rational() = default;

        /* ---------------- Operators ---------------- */

        Rational operator+(const Rational &ratio);
        Rational operator-(const Rational &ratio);
        Rational operator-();
        Rational operator*(const Rational &ratio);
        Rational operator*(const float &f); // extern product
        Rational operator/(const Rational &ratio);

        bool operator>=(const Rational &ratio);
        bool operator<=(const Rational &ratio);
        bool operator<(const Rational &ratio);
        bool operator>(const Rational &ratio);
        bool operator==(const Rational &ratio);
        bool operator!=(const Rational &ratio);

        /* ---------------- Methods ---------------- */

        /* ----- Getter ----- */
        int getNumerator() const {return numerator; }; // get the numerator of the rational
        int getDenominator() const {return denominator; }; // get the denominator of the rational

        /* ----- Arithmetics ----- */
        Rational invRatio(); // invert the rational

        Rational squareRoot(); // square root
        Rational squareRoot2();

        Rational power(const int &power); // power

        Rational log(); // logarithm
        Rational log2(); // logarithm

        Rational absolute(); // absolute value
        int integerPart(); // integer part

        Rational cosTaylor();
        Rational sinTaylor();
        Rational tanTaylor();
        Rational expTaylor();

        Rational cosRatio();
        Rational sinRatio();
        Rational tanRatio();
        Rational expRatio();

        /* ----- Manipulations ----- */
        Rational makeIrreductible(); // make a rational irreductible

};

/* ------- Methods outside Rational class ------- */
template<typename T>
Rational<T> floatToRatio(const float &x, unsigned int nbIter = 5); // conversion float to rational

template<typename T>
std::ostream& operator<< (std::ostream& stream, const Rational<T> &ratio);

template<typename T>
Rational<T> extProductReal(const float &f, const Rational<T> &ratio); // extern product for float


/* ---------------- Constructors ---------------- */

template<typename T>
Rational<T>::Rational(const T &a, const T &b) {
    // 0 exception
    if(b == 0) {
        // infinite
        if(a==1) {
            std::cout << "You reached the infinite !" << std::endl;
            numerator = 1;
            denominator = 0;
        }
        // zero
        else {
            std::cout << "It's impossible to divide by 0 ! We let you to 0." << std::endl;
            numerator = 0;
            denominator = 1;
        }
    }
    // case b < 0 (negative denominator)
    if(b < 0) {
        numerator = -a;
        denominator = -b;
    } 
    else {
        numerator = a;
        denominator = b;
    }
    // make it irreductible
    int GCD = std::gcd(numerator, denominator);
    if(std::abs(GCD) != 1) {
        numerator = numerator/std::abs(GCD);
        denominator = denominator/std::abs(GCD);
    }
}

/* Constructor based on floats [not working -> compilation error : already difined] */

/*
template<>
Rational::Rational<float>(const float &a, const float &b) {
    // 0 exception
    if(b == 0.) {
        if(a == 1.) {
            std::cout << "You reached the infinite !" << std::endl;
            numerator = 1;
            denominator = 0;
        }
        // zero
        else {
            std::cout << "It's impossible to divide by 0 ! We let you to 0." << std::endl;
            numerator = 0;
            denominator = 1;
        }
    }
    
    // conversion : float to ratio
    Rational a_to_ratio(floatToRatio(a,7));
    Rational b_to_ratio(floatToRatio(b,7));
    Rational ratio(a_to_ratio/b_to_ratio);
    ratio.makeIrreductible();

    // case negative denominator
    if(ratio.getDenominator() < 0) {
        numerator = -ratio.getNumerator();
        denominator = -ratio.getDenominator();
    } 
    else {
        numerator = ratio.getNumerator();
        denominator = ratio.getDenominator();
    }
} */

#endif