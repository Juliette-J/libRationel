#include <iostream>

#ifndef RATIONNELS_HPP
#define RATIONNELS_HPP

class Rational {
    private :
        int numerator;
        int denominator;

    public :
        // Constructors
        Rational(const int &a = 1, const int &b = 1);
        Rational(const float &a = 1, const float &b = 1);

        Rational(const Rational &r) = default; // by copy

        // Destructor
        ~Rational() = default;


        // Operators
        Rational operator+(const Rational &ratio);
        Rational operator-(const Rational &ratio);
        bool operator>=(const Rational &ratio);
        bool operator==(const Rational &ratio);

        //ne fonctionne pas
        Rational operator-();

        Rational operator*(const Rational &ratio);
        Rational operator/(const Rational &ratio);
        
        // inverse the rational
        Rational InvRatio();

        // make it irreductible
        Rational irreductible();

        // square root pas complet jsp comment mieux faire
        Rational squareroot();

        // log
        Rational log();

        // absolute value
        Rational absolute();

        // entier
        int entier();

        // Methods
        int getNumerator() const {return numerator; }; // get the numerator of the rational
        int getDenominator() const {return denominator; }; // get the denominator of the rational
        Rational floatToRatio(const float &x, unsigned int nbIter);
        
        
};

// Operations
Rational power(const Rational &ratio, const int &power);


std::ostream& operator<< (std::ostream& stream, const Rational &ratio);

/*
template<typename T>
class Rational {
    private :
        int numerator;
        int denominator;

    public :
        // Constructors
        Rational() = default; // by default
        //Rational(const T &a = static_cast(1));
        Rational(const T &a = static_cast(1), const T &b = static_cast(1));
        Rational(const Rational &r) = default; // by copy

        // Destructor
        ~Rational() = default;

        // Methods
        Rational floatToRatio(const float &x, unsigned int nbIter);

        // Operators

};
*/



#endif