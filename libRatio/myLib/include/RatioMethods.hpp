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

template<typename T>
constexpr Rational<T> Rational<T>::invRatio(){
    //assert(this->numerateur==0 && "error: Rational::invRatio numerator null");

    return Rational(this->getDenominator(), this->getNumerator());
}

template<typename T>
constexpr Rational<T> Rational<T>::squareRoot(){
    //assert(this->denominator==0 && "error: Rational::squareRoot denomerator null");
    T num = this->getNumerator();
    T den = this-> getDenominator();
    if (num < 0){
        std::cout << "No square root for negative number ! Let you to 0." << std::endl;
        return Rational(0,1);
    }

    float sqrtNum = std::sqrt(num);
    float sqrtDen = std::sqrt(den);

    Rational sqrtNumRatio(floatToRatio<T>(sqrtNum , 10));
    Rational sqrtDenRatio(floatToRatio<T>(sqrtDen, 10));
    
    
    return Rational(sqrtNumRatio/sqrtDenRatio);
    // less accurate, more costly
}

template<typename T>
constexpr Rational<T> Rational<T>::squareRoot2(){
    //assert(this->denominator==0 && "error: Rational::squareRoot denomerator null");
    T num = this->getNumerator();
    T den = this-> getDenominator();
    if (num < 0){
        std::cout << "No square root for negative number ! Let you to 0." << std::endl;
        return Rational(0,1);
    }
    float sqrtRatio = std::sqrt(((float)num)/((float)den));
    return  Rational(floatToRatio<T>(sqrtRatio , 10));
     // more acurate, less costly
}

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

template<typename T>
constexpr Rational<T> Rational<T>::log(){
    T num = this->getNumerator();
    T den  = this-> getDenominator();
    if (num < 0){
        std::cout << "No log for negative number ! Let you to 0." << std::endl;
        return Rational(0,1);
    }

    float logNum = std::log(num);
    float logDen = std::log(den);

    Rational logNumRatio(floatToRatio<T>(logNum , 5));
    Rational logDenRatio(floatToRatio<T>(logDen, 5));
    
    
    return logNumRatio - logDenRatio;
    //soit c'est la soustraction qui bloque et fait que l'erreur n'est plus négligeable soit c'est parce qu'on est en int et le rationnel a des long int du coup des données sautent
}

template<typename T>
constexpr Rational<T> Rational<T>::log2(){
    T num = this->getNumerator();
    T den = this->getDenominator();
    if (num < 0){
        std::cout << "No log for negative number ! Let you to 0." << std::endl;
        return Rational(0,1);
    }

    float logRatio = std::log(((float)num)/((float)den));
    return  floatToRatio<T>(logRatio , 5);
    // better : more accurate, less costly, easier
}


template<typename T>
constexpr Rational<T> Rational<T>::absolute(){
    //assert(this->denominator==0 && "error: Rational::absolute numerator null");
    return Rational(std::abs(this->numerator), this->denominator);
}

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

template<typename T>
constexpr Rational<T> Rational<T>::cosTaylor() {
    return Rational(1,1) - Rational(1,2)*(this->power(2)) + Rational(1,24)*(this->power(4));
}

template<typename T>
constexpr Rational<T> Rational<T>::sinTaylor() {
    return *this - Rational(1,6)*(this->power(3)) + Rational(1,120)*(this->power(5));
}

template<typename T>
constexpr Rational<T> Rational<T>::expTaylor() {
    return Rational(1,1) + (*this) + Rational(1,2)*(this->power(2)) + Rational(1,6)*(this->power(3)) + Rational(1,24)*(this->power(4)) + Rational(1,120)*(this->power(5));
}

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

template<typename T>
constexpr Rational<T> Rational<T>::tanRatio(){
     Rational sin(this->sinRatio());
     Rational cos(this->cosRatio());
     return sin/cos;
}

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

template<typename T>
constexpr Rational<T> extProductReal(const float &f, const Rational<T> &ratio) {
    Rational fToRatio(floatToRatio<T>(f));
    return fToRatio*ratio;
}

#endif