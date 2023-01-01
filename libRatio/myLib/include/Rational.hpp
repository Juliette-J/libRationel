#include <iostream>
#include <numeric>

#ifndef RATIONNELS_HPP
#define RATIONNELS_HPP

//template<typename T>
class Rational {
    private :
        int numerator;
        int denominator;

    public :
        /* ---------------- Constructors ---------------- */ 

        template<typename U>
        Rational(const U &a = 1, const U &b = 1);

        Rational(const Rational &r) = default; // by copy


        /* ---------------- Destructor ---------------- */

        ~Rational() = default;


        /* ---------------- Operators ---------------- */

        Rational operator+(const Rational &ratio);
        Rational operator-(const Rational &ratio);
        Rational operator*(const Rational &ratio);
        Rational operator*(const float &f); // extern product
        Rational operator/(const Rational &ratio);

        //ne fonctionne pas
        Rational operator-();

        bool operator>=(const Rational &ratio);
        bool operator<=(const Rational &ratio);
        bool operator<(const Rational &ratio);
        bool operator>(const Rational &ratio);
        bool operator==(const Rational &ratio);
        bool operator!=(const Rational &ratio);


        /* ---------------- Methods ---------------- */

        /* ----- Getter/Setter ----- */

        int getNumerator() const {return numerator; }; // get the numerator of the rational
        int getDenominator() const {return denominator; }; // get the denominator of the rational

        /* ----- Arithmetics ----- */

        Rational invRatio(); // invert the rational

        // square root pas complet jsp comment mieux faire
        Rational squareRoot();

        Rational log(); // logarithm
        Rational absolute(); // absolute value
        

        /* ----- Manipulations ----- */

        int integerPart(); // integer part
        Rational makeIrreductible(); // make a rational irreductible

};


/* ------- Methods outside Rational class ------- */

Rational power(const Rational &ratio, const int &power);
Rational cosTaylor(const Rational &ratio);
Rational sinTaylor(const Rational &ratio);
Rational expTaylor(const Rational &ratio);
Rational cosRatio(const Rational &ratio);
Rational sinRatio(const Rational &ratio);
Rational expRatio(const Rational &ratio);
Rational floatToRatio(const float &x, unsigned int nbIter = 5); // conversion float to rational
std::ostream& operator<< (std::ostream& stream, const Rational &ratio);


/* ---------------- Constructors ---------------- */

template<typename U>
Rational::Rational(const U &a, const U &b) {
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
}
*/

#endif