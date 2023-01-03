#include "Rational.hpp"

#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <cassert>

#ifndef RATIOMETHODS_HPP
#define RATIOMETHODS_HPP

/* ---------------- Methods ---------------- */

/* ----- Arithmetics ----- */

/// \brief Inversion of a rational number
/// \return a rational with the numerator and denominator exchanged or an error if the numerator equals 0

template<typename T>
constexpr Rational<T> Rational<T>::invRatio(){
    assert(this->denominator==0 && "error: Rational::squareRoot denominator null");
    if(this->getNumerator()==0){
        std::cerr << "error: Rational::invRatio: numerator null" << std::endl;
        return *this;
    }

    return Rational(this->getDenominator(), this->getNumerator());
}

/// \brief Square root of a rational number a/b by making sqrt(a.)/sqrt(b.)
/// \return a rational or an error if the numerator is negative

template<typename T>
constexpr Rational<T> Rational<T>::squareRoot(){
    assert(this->denominator==0 && "error: Rational::squareRoot denominator null");
    T num = this->getNumerator();
    T den = this-> getDenominator();
    if (num < 0){
        std::cerr << "error: Rational::sqareRoot: no square root for negative number" << std::endl;
        return *this;
    }

    float sqrtNum = std::sqrt(num);
    float sqrtDen = std::sqrt(den);

    Rational sqrtNumRatio(floatToRatio<T>(sqrtNum , 10));
    Rational sqrtDenRatio(floatToRatio<T>(sqrtDen, 10));
    
    //by using the formula : sqrt(a/b)=sqrt(a)/sqrt(b)

    return Rational(sqrtNumRatio/sqrtDenRatio);
    // less accurate, more costly
}

/// \brief Square root of a rational number by making the square root of the rational converted into a float
/// \return a rational or an error if the numerator is negative

template<typename T>
constexpr Rational<T> Rational<T>::squareRoot2(){
    assert(this->denominator==0 && "error: Rational::squareRoot2 denominator null");
    T num = this->getNumerator();
    T den = this-> getDenominator();
    if (num < 0){
        std::cerr << "error: Rational::sqareRoot: no square root for negative number" << std::endl;
        return *this;
    }
    float sqrtRatio = std::sqrt(((float)num)/((float)den));
    return  Rational(floatToRatio<T>(sqrtRatio , 10));
     // more acurate, less costly
}

/// \brief Power of a rational number 
/// \param factor : 
/// \return a rational 

template<typename T>
constexpr Rational<T> Rational<T>::power(const int &factor) {
    T powNum;
    T powDen;
    if(factor < 0) {
        powNum = std::pow(this->getDenominator(), -factor);
        powDen = std::pow(this->getNumerator(), -factor);
        return Rational(powNum, powDen);
    }
    powNum = std::pow(this->getNumerator(), factor);
    powDen = std::pow(this->getDenominator(), factor);
    return Rational(powNum, powDen);
}

/// \brief Logarithm of a rational number by making log(a.)-log(b.)
/// \return a rational or an error if the numerator is negative

template<typename T>
constexpr Rational<T> Rational<T>::log(){
    T num = this->getNumerator();
    T den  = this-> getDenominator();
    if (num < 0){
        std::cerr << "error: Rational::log: no log for negative number ! Let you to 0." << std::endl;
        return Rational(0,1);
    }

    float logNum = std::log(num);
    float logDen = std::log(den);

    Rational logNumRatio(floatToRatio<T>(logNum , 5));
    Rational logDenRatio(floatToRatio<T>(logDen, 5));

    //by using the formula : log(a/b)=log(a)-log(b)
    
    return logNumRatio - logDenRatio;
}

/// \brief Logarithm of a rational number by making the logarithm of the rational converted into a float 
/// \return a rational or an error if the numerator is negative

template<typename T>
constexpr Rational<T> Rational<T>::log2(){
    T num = this->getNumerator();
    T den = this->getDenominator();
    if (num < 0){
        std::cerr << "error: Rational::log: no log for negative number ! Let you to 0." << std::endl;
        return Rational(0,1);
    }

    float logRatio = std::log(((float)num)/((float)den));
    return  floatToRatio<T>(logRatio , 5);
    // better : more accurate, less costly, easier
}

/// \brief Absolute of a rational number 
/// \return a rational with a positive numerator


template<typename T>
constexpr Rational<T> Rational<T>::absolute(){
    assert(this->denominator==0 && "error: Rational::absolute denominator null");
    return Rational(std::abs(this->numerator), this->denominator);
}

/// \brief Integer part of a rational number 
/// \return a integer 

template<typename T>
constexpr int Rational<T>::integerPart(){
    T intPart = 0;
    T numAbs = std::abs(this->getNumerator());
    // rational < 1 -> integer part = 0
    if (this->getDenominator() > numAbs){
        return 0;
    }
    // rational = 1 -> integer part = 1
    else if (this->getDenominator() == numAbs){
        intPart = 1;
    }
    else {
        T numSubstract = numAbs;
        while(numSubstract >= this->getDenominator()){
            numSubstract -= this->getDenominator();
            intPart += 1;
        }
    }
    // sign of the integer part
    if(numAbs != this->getNumerator()){
        intPart = -intPart;
    }
    return intPart;
}

/// \brief Cosinus of a rational number 
/// \return a  

template<typename T>
constexpr Rational<T> Rational<T>::cosTaylor() {
    return Rational(1,1) - Rational(1,2)*(this->power(2)) + Rational(1,24)*(this->power(4));
}

/// \brief Sinus of a rational number 
/// \return a  

template<typename T>
constexpr Rational<T> Rational<T>::sinTaylor() {
    return *this - Rational(1,6)*(this->power(3)) + Rational(1,120)*(this->power(5));
}

/// \brief Exponential of a rational number 
/// \return a  

template<typename T>
constexpr Rational<T> Rational<T>::expTaylor() {
    return Rational(1,1) + (*this) + Rational(1,2)*(this->power(2)) + Rational(1,6)*(this->power(3)) + Rational(1,24)*(this->power(4)) + Rational(1,120)*(this->power(5));
}

/// \brief Cosinus of a rational number 
/// \return a  

template<typename T>
constexpr Rational<T> Rational<T>::cosRatio() {
    Rational cosRational(1,1);
    // Near 0, use Taylor
    if( Rational(1,1) > (*this) ) {
        cosRational = this->cosTaylor();
    }
    else {
        Rational intPart = Rational(this->integerPart(), 1); // integer part of the rational
        Rational decimalPart = Rational((*this) - intPart); // decimal part of the rational
            // cos(integer_part + decimal_part) ~ cos(a + b) = cos(a)cos(b) - sin(a)sin(b)
        cosRational = (decimalPart.cosTaylor())*(std::cos(intPart.getNumerator()))-(decimalPart.sinTaylor())*(std::sin(intPart.getNumerator()));
    }

    if(std::abs(((float)cosRational.getNumerator())/((float)cosRational.getDenominator())) > 1) {
        std::cout << "The result is not coherent due to the limitation of memory (integers encoded are too big for this rational)..." << std::endl; 
    }
    return cosRational;
}

/// \brief Sinus of a rational number 
/// \return a  

template<typename T>
constexpr Rational<T> Rational<T>::sinRatio() {
    Rational sinRational(1,1);
    // Near 0, use Taylor
    if( Rational(1,1) > (*this) ) {
        sinRational = this->sinTaylor();
    }
    else {
        Rational intPart = Rational(this->integerPart(), 1); // integer part of the rational
        Rational decimalPart = Rational((*this) - intPart); // decimal part of the rational
            // sin(integer_part + decimal_part) ~ sin(a + b) = sin(a)cos(b) - sin(b)cos(a)
        sinRational = (decimalPart.cosTaylor())*(std::sin(intPart.getNumerator()))-(decimalPart.sinTaylor())*(std::cos(intPart.getNumerator()));
    }

    if(std::abs(((float)sinRational.getNumerator())/((float)sinRational.getDenominator())) > 1) {
        std::cout << "The result is not coherent due to the limitation of memory (integers encoded are too big for this rational)..." << std::endl; 
    }
    return sinRational;
}

/// \brief Tangent of a rational number by making sin/cos
/// \return a rational number

template<typename T>
constexpr Rational<T> Rational<T>::tanRatio(){
     Rational sin(this->sinRatio());
     Rational cos(this->cosRatio());
     return sin/cos;
}

/// \brief Exponential of a rational number 
/// \return a rational 

template<typename T>
constexpr Rational<T> Rational<T>::expRatio() {
    Rational expRational(1,1);
    // Near 0, use Taylor
    if( Rational(1,1) > (*this) ) {
        expRational = this->expTaylor();
    }
    else {
        Rational intPart = Rational(this->integerPart(), 1); // integer part of the rational
        Rational decimalPart = Rational((*this) - intPart); // decimal part of the rational
            // sin(integer_part + decimal_part) ~ sin(a + b) = sin(a)cos(b) - sin(b)cos(a)
        expRational = (decimalPart.expTaylor())*(std::exp(intPart.getNumerator()));
    }
    return expRational;
}

/* ----- Manipulations ----- */

/// \brief Make a rational number into an irreducible rational number
/// \return a rational 

template<typename T>
constexpr Rational<T> Rational<T>::makeIrreductible(){
    //assert(this->denominator==0 && "error: Rational::makeIrreductible denominator null");
    T numerator = this->getNumerator();
    T denominator = this-> getDenominator();

    if(std::abs(std::gcd(numerator, denominator)) != 1) {
        numerator /= std::abs(std::gcd(numerator, denominator));
        denominator /= std::abs(std::gcd(numerator, denominator));
    }
    return Rational(numerator, denominator);
}

/* ---------- Methods outside Rational class ---------- */

/// \brief Make a rational number from a float and an iteration number
/// \param x a constant float
/// \param nbIter an unisgned integer
/// \return a rational 

template<typename T>
constexpr Rational<T> floatToRatio(const float &x, unsigned int nbIter) {
    // keep the sign of x
    float sign;
    (x<0) ? sign = -1.0 : sign = 1.0;

    // use abs(x) as the sign was kept
    float absX = std::abs(x);

    // majoration of nbIter to keep a coherent result
    (nbIter > 10) ? nbIter = 10 : nbIter = nbIter ;
    
    // stop conditions
    if(x == 0. || nbIter == 0) {
        return Rational(0,1);
    }

    // decimal part
    else if(absX < 1.0) {
        return floatToRatio<T>(sign/absX, nbIter).invRatio();
    }

    // integer part
    else {
        return Rational((T)(sign*(std::floor(absX))), 1) + floatToRatio<T>(sign*(absX-(std::floor(absX))), nbIter-1);
    }
}

/// \brief Display a rational number
/// \return return a rational in the form a/b or just a if b equals 1 or an error if a=b=0

template<typename T>
constexpr std::ostream& operator<< (std::ostream& stream, const Rational<T> &ratio) {
	if(ratio.getNumerator() == 0 && ratio.getDenominator() == 0){
		stream << "Not initialized yet -> 0/0 IMPOSSIBLE";
		return stream;
	}
    else if(ratio.getDenominator() == 1){
        stream << ratio.getNumerator();
    }
			
	else {
        stream << ratio.getNumerator() << "/" << ratio.getDenominator() ;
    }

	return stream;
}


/* ---------------- Extern product for float---------------- */

/// \brief Product of a float and a rational number
/// \param f a constant float
/// \param ratio a constant rational number
/// \return a rational 

template<typename T>
constexpr Rational<T> extProductReal(const float &f, const Rational<T> &ratio) {
    Rational fToRatio(floatToRatio<T>(f));
    return fToRatio*ratio;
}

#endif