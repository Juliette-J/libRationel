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
        constexpr Rational(const T &a = 1, const T &b = 1);
        constexpr Rational(const Rational &r) = default; // by copy

        /* ---------------- Destructor ---------------- */
        ~Rational() = default;

        /* ---------------- Operators ---------------- */

        constexpr Rational operator+(const Rational &ratio);
        constexpr Rational operator-(const Rational &ratio);
        constexpr Rational operator-();
        constexpr Rational operator*(const Rational &ratio);
        constexpr Rational operator*(const float &f); // extern product
        constexpr Rational operator/(const Rational &ratio);

        constexpr bool operator>=(const Rational &ratio);
        constexpr bool operator<=(const Rational &ratio);
        constexpr bool operator<(const Rational &ratio);
        constexpr bool operator>(const Rational &ratio);
        constexpr bool operator==(const Rational &ratio);
        constexpr bool operator!=(const Rational &ratio);

        /* ---------------- Methods ---------------- */

        /* ----- Getter ----- */
        constexpr int getNumerator() const {return numerator; }; // get the numerator of the rational
        constexpr int getDenominator() const {return denominator; }; // get the denominator of the rational

        /* ----- Arithmetics ----- */
        constexpr Rational invRatio(); // invert the rational

        constexpr Rational squareRoot(); // square root
        constexpr Rational squareRoot2();

        constexpr Rational power(const int &factor); // power

        constexpr Rational log(); // logarithm
        constexpr Rational log2(); // logarithm

        constexpr Rational absolute(); // absolute value
        constexpr int integerPart(); // integer part

        constexpr Rational cosTaylor();
        constexpr Rational sinTaylor();
        constexpr Rational tanTaylor();
        constexpr Rational expTaylor();

        constexpr Rational cosRatio();
        constexpr Rational sinRatio();
        constexpr Rational tanRatio();
        constexpr Rational expRatio();

        /* ----- Manipulations ----- */
        constexpr Rational makeIrreductible(); // make a rational irreductible

};

/* ------- Methods outside Rational class ------- */
template<typename T>
constexpr Rational<T> floatToRatio(const float &x, unsigned int nbIter = 5); // conversion float to rational

template<typename T>
constexpr std::ostream& operator<< (std::ostream& stream, const Rational<T> &ratio);

template<typename T>
constexpr Rational<T> extProductReal(const float &f, const Rational<T> &ratio); // extern product for float


/* ---------------- Constructors ---------------- */

template<typename T>
constexpr Rational<T>::Rational(const T &a, const T &b) {
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

#endif