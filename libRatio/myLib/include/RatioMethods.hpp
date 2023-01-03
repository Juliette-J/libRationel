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

    /* if (this->getNumerator()==0){
        if(this->getDenominator() == 1) {
            std::cout << "You reached the infinite !" << std::endl;
            return Rational(1,0); 
        }
        std::cout << "Impossible to inverse numerator = 0. Let you to 0." << std::endl;
        return Rational(0,1);

    }
    else if (this->getNumerator() < 0) {
        Rational(-this->getDenominator(), -this->getNumerator());
    } */

    return Rational(this->getDenominator(), this->getNumerator());
}

template<typename T>
constexpr Rational<T> Rational<T>::squareRoot(){
    //assert(this->denominator==0 && "error: Rational::squareRoot denomerator null");
    int a = this->getNumerator();
    int b = this-> getDenominator();
    if (a<0){
        std::cout << "No square root for negative number !" << std::endl;
        return Rational(0,1);
    }

    float e = std::sqrt(a);
    float f = std::sqrt(b);

    Rational rat_e =  floatToRatio<T>(e , 10);
    Rational rat_f = floatToRatio<T>(f, 10);
    
    
    return rat_e / rat_f;
    //un peu moins précise, plus couteuse
}

template<typename T>
constexpr Rational<T> Rational<T>::squareRoot2(){
    //assert(this->denominator==0 && "error: Rational::squareRoot denomerator null");
    int a = this->getNumerator();
    int b = this-> getDenominator();
    if (a<0){
        std::cout << "No square root for negative number !" << std::endl;
        return Rational(0,1);
    }
    float e = sqrt((float)a/b);
    return  floatToRatio<T>(e , 10);
     //plus précise, moins couteuse
}

template<typename T>
constexpr Rational<T> Rational<T>::power(const int &power) {
    if(power < 0) {
        int pow_numerator = std::pow(this->getDenominator(), -power);
        int pow_denominator = std::pow(this->getNumerator(), -power);
        return Rational(pow_numerator, pow_denominator);
    }
    int pow_numerator = std::pow(this->getNumerator(), power);
    int pow_denominator = std::pow(this->getDenominator(), power);
    return Rational(pow_numerator, pow_denominator);
}

template<typename T>
constexpr Rational<T> Rational<T>::log(){
    int a = this->getNumerator();
    int b = this-> getDenominator();
    if (a<0){
        std::cout << "No log for negative number !" << std::endl;
        return Rational(0,1);
    }

    float e = std::log(a);
    float f = std::log(b);

    Rational rat_e =  floatToRatio<T>(e , 10);
    Rational rat_f = floatToRatio<T>(f, 10);
    
    
    return rat_e - rat_f;
    //soit c'est la soustraction qui bloque et fait que l'erreur n'est plus négligeable soit c'est parce qu'on est en int et le rationnel a des long int du coup des données sautent
}

template<typename T>
constexpr Rational<T> Rational<T>::log2(){
    int a = this->getNumerator();
    int b = this-> getDenominator();
    if (a<0){
        std::cout << "No log for negative number !" << std::endl;
        return Rational(0,1);
    }

    float e = std::log((float)a/b);
    return  floatToRatio<T>(e , 10);
    //meilleur moins couteuse, plus facile, plus précise
}


template<typename T>
constexpr Rational<T> Rational<T>::absolute(){
    //assert(this->denominator==0 && "error: Rational::absolute numerator null");
    return Rational(std::abs(this->numerator), this->denominator);
}

template<typename T>
constexpr int Rational<T>::integerPart(){
    int res = 0;
    int a = abs(this->getNumerator());
    if (this->getDenominator() > a){
        return 0;
    }
    else if (this->getDenominator() == a){
        res=1;
    }
    else {
        int e = a;
        while(e >= this->getDenominator()){
            e = e-this->getDenominator();
            res += 1;
        }
    }
    if(a != this->getNumerator()){
        res = -res;
    }
    return res;
}

template<typename T>
constexpr Rational<T> Rational<T>::cosTaylor() {
    return (Rational(1,1) - Rational(1,2)*(this->power(2)) + Rational(1,24)*(this->power(4))).makeIrreductible();
}

template<typename T>
constexpr Rational<T> Rational<T>::sinTaylor() {
    return (*this - Rational(1,6)*(this->power(3)) + Rational(1,120)*(this->power(5))).makeIrreductible();
}

template<typename T>
constexpr Rational<T> Rational<T>::expTaylor() {
    return (Rational(1,1) + (*this) + Rational(1,2)*(this->power(2)) + Rational(1,6)*(this->power(3)) + Rational(1,24)*(this->power(4)) + Rational(1,120)*(this->power(5))).makeIrreductible();
}

template<typename T>
constexpr Rational<T> Rational<T>::cosRatio() {
    Rational result(1,1);
    // Near 0, use Taylor
    if( Rational(3,4) > (*this) ) {
        result = this->cosTaylor();
    }
    else {
        Rational int_part = Rational(this->integerPart(), 1); // integer part of the rational
        Rational decimal_part = Rational((*this) - int_part); // decimal part of the rational
            // cos(integer_part + decimal_part) ~ cos(a + b) = cos(a)cos(b) - sin(a)sin(b)
        result = (decimal_part.cosTaylor())*(std::cos(int_part.getNumerator()))-(decimal_part.sinTaylor())*(std::sin(int_part.getNumerator()));
    }

    if(std::abs(((float)result.getNumerator())/((float)result.getDenominator())) > 1) {
        std::cout << "The result is not coherent due to the limitation of memory (integers encoded are too big for this rational)..." << std::endl; 
    }
    return result;
}

template<typename T>
constexpr Rational<T> Rational<T>::sinRatio() {
    Rational result(1,1);
    // Near 0, use Taylor
    if( Rational(3,4) > (*this) ) {
        result = this->sinTaylor();
    }
    else {
        Rational int_part = Rational(this->integerPart(), 1); // integer part of the rational
        Rational decimal_part = Rational((*this) - int_part); // decimal part of the rational
            // sin(integer_part + decimal_part) ~ sin(a + b) = sin(a)cos(b) - sin(b)cos(a)
        result = (decimal_part.cosTaylor())*(std::sin(int_part.getNumerator()))-(decimal_part.sinTaylor())*(std::cos(int_part.getNumerator()));
    }

    if(std::abs(((float)result.getNumerator())/((float)result.getDenominator())) > 1) {
        std::cout << "The result is not coherent due to the limitation of memory (integers encoded are too big for this rational)..." << std::endl; 
    }
    return result;
}

template<typename T>
constexpr Rational<T> Rational<T>::tanRatio(){
     Rational sin = this->sinRatio();
     Rational cos = this->cosRatio();
     return sin / cos;
}

template<typename T>
constexpr Rational<T> Rational<T>::expRatio() {
    Rational result(1,1);
    // Near 0, use Taylor
    if( Rational(1,1) > (*this) ) {
        result = this->expTaylor();
    }
    else {
        Rational int_part = Rational(this->integerPart(), 1); // integer part of the rational
        Rational decimal_part = Rational((*this) - int_part); // decimal part of the rational
            // sin(integer_part + decimal_part) ~ sin(a + b) = sin(a)cos(b) - sin(b)cos(a)
        result = (decimal_part.expTaylor())*(std::exp(int_part.getNumerator()));
    }
    return result;
}

/* ----- Manipulations ----- */

template<typename T>
constexpr Rational<T> Rational<T>::makeIrreductible(){
    //assert(this->denominator==0 && "error: Rational::makeIrreductible denominator null");
    int numerator = this->getNumerator();
    int denominator = this-> getDenominator();

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
        return Rational((int)(sign*(std::floor(absX))), 1) + floatToRatio<T>(sign*(absX-(std::floor(absX))), nbIter-1);
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