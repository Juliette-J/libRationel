#ifndef RATIONNELS_HPP
#define RATIONNELS_HPP


class Rational {
    private :
        int numerator;
        int denominator;

    public :
        // Constructors
        Rational() = default; // by default

        Rational(const int &a = 1) : numerator(a), denominator(1) {};
        Rational(const float &a = 1);

        Rational(const int &a = 1, const int &b = 1);
        Rational(const float &a = 1, const float &b = 1);

        Rational(const Rational &r) = default; // by copy

        // Destructor
        ~Rational() = default;

        // Methods
        int getNumerator() const {return numerator; }; // get the numerator of the rational
        int getDenominator() const {return denominator; }; // get the denominator of the rational
        Rational floatToRatio(const float &x, unsigned int nbIter);
        Rational pow(const Rational &ratio, const int &power);

        // Operators
        Rational operator+(const Rational &ratio);

};

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