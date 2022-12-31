#include "Rational.hpp"

#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <cassert>


/* ---------------- Operators ---------------- */

Rational Rational::operator+(const Rational &ratio) {
	int numerator = this->numerator*ratio.getDenominator() + this->denominator*ratio.getNumerator();
    int denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

/*template<typename T>
Rational<T> Rational<T>::operator+(const Rational<T> &ratio) const
{
    assert(ratio.getDenominator() == 0 || *this->denominator && "error: Rational::operator+ denominator null");

	return Rational(this->numerator*ratio.getDenominator() + this->denominator*ratio.getNumerator(), this->denominator*ratio.getDenominator());

}*/


Rational Rational::operator-(const Rational &ratio) {
	int numerator = this->numerator*ratio.getDenominator() - this->denominator*ratio.getNumerator();
    int denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

/*template<typename T>
Rational<T> Rational<T>::operator-(const Rational<T> &ratio) const
{
    assert(ratio.getDenominator() == 0 || *this->denominator && "error: Rational::operator- denominator null");

	return Rational(this->numerator*ratio.getDenominator() - this->denominator*ratio.getNumerator(), this->denominator*ratio.getDenominator());

}*/


Rational Rational::operator-() {
	return Rational(-this->numerator, this->denominator);
}


/*template<typename T>
Rational<T> Rational<T>::operator-() const
{
    assert(*this->denominator && "error: Rational::operator- denominator null");

	return Rational(-this->numerator, this->denominator);;
}*/


Rational Rational::operator*(const Rational &ratio) {
	return Rational(this->numerator*ratio.getNumerator(), this->denominator*ratio.getDenominator());
}

/*template<typename T>
Rational<T> Rational<T>::operator*(const Rational<T> &ratio) const
{
    assert(ratio.getDenominator() == 0 || *this->denominator && "error: Rational::operator* denominator null");

	return Rational(this->numerator*ratio.getNumerator(), this->denominator*ratio.getDenominator());
}*/


Rational Rational::operator/(const Rational &ratio) {
    return Rational(this->numerator*ratio.getDenominator(), this->denominator*ratio.getNumerator());
}

/*
template<typename T>
Rational<T> Rational<T>::operator/(const Rational<T> &ratio) const
{
    assert(ratio.getDenominator() == 0 || *this->denominator && "error: Rational::operator* denominator null");

	return Rational(this->numerator*ratio.getDenominator(), this->denominator*ratio.getNumerator());
}*/

bool Rational::operator==(const Rational &ratio) {
    if (this->getNumerator() == ratio.getNumerator() && this->getDenominator() == ratio.getDenominator()) {
        return true;
    }
    return false;
}

/*
template<typename T>
bool Rational<T>::operator==(const Rational &ratio)
{
    if (this->getNumerator() == ratio.getNumerator() && this->getDenominator() == ratio.getDenominator()) {
        return true;
    }
    return false;
}*/

bool Rational::operator!=(const Rational &ratio) {
    return !(*this == ratio);
}

/*
template<typename T>
bool Rational<T>::operator!=(const Rational &ratio)
{
    return !(*this == ratio);
}*/


bool Rational::operator>=(const Rational &ratio) {
    int deno1 = ratio.getDenominator();
    int deno2 = this->getDenominator();
    int nume1 = ratio.getNumerator();
    int nume2 = this->getNumerator();
    nume1 = nume1 * deno2;
    nume2 = nume2 * deno1;
    if (nume2 >= nume1) {
        return true;
    }
    return false;
}

/*
template<typename T>
bool Rational<T>::operator>=(const Rational &ratio)
{
    int deno1 = ratio.getDenominator();
    int deno2 = this->getDenominator();
    int nume1 = ratio.getNumerator();
    int nume2 = this->getNumerator();
    nume1 = nume1 * deno2;
    nume2 = nume2 * deno1;
    if (nume2 >= nume1) {
        return true;
    }
    return false;
}*/

bool Rational::operator<(const Rational &ratio) {
    return !(*this >= ratio);
}

/*template<typename T>
bool Rational<T>::operator<(const Rational &ratio)
{
    return !(*this >= ratio);
}*/


bool Rational::operator<=(const Rational &ratio) {
    
    return !(*this<ratio && *this==ratio);
}

/*template<typename T>
bool Rational<T>::operator<=(const Rational &ratio)
{
    return !(*this<ratio && *this==ratio);
}*/


bool Rational::operator>(const Rational &ratio) {
    return !(*this <= ratio);
}

/*template<typename T>
bool Rational<T>::operator>(const Rational &ratio)
{
    return !(*this <= ratio);
}*/


/* ---------------- Methods ---------------- */

/* ----- Arithmetics ----- */

Rational Rational::extProduct(const float &f) {
    Rational ratio(floatToRatio(f, 7));
    return Rational((*this)*ratio);
}

Rational Rational::invRatio(){
	return Rational(this->getDenominator(), this->getNumerator());
}

/*template<typename T>
Rational<T> Rational<T>::invRatio() {
    assert(this->numerateur==0 && "error: Rational::invRatio numerator null");
    
	return Rational(this->getDenominator(), this->getNumerator());
}*/

/*pas fini je reflechis encore dessus... parce que sqrt de 3 ca va etre complique*/


Rational Rational::squareRoot(){
    int a = this->getNumerator();
    int b = this-> getDenominator();
    if (a<0){
        std::cout << "No square root for negative number !" << std::endl;
        return Rational(0,1);
    }

    float e = std::sqrt(a);
    while (e >= 1){
        e = e-1;
    }
    float f = std::sqrt(b);
    while (f >= 1){
        f = f-1;
    }

    if (e==0 && f==0){
        a = std::sqrt(a);
        b=std::sqrt(b);
        return Rational(a,b);
    }

    /*probleme de conversion car sqrt peut renvoyer floattoRatio*/
    std::cout << "The square root is not a rational number !" << std::endl;
    return Rational(0,1);
}

/*template<typename T>
Rational<T> Rational<T>::squareRoot() {
    assert(this->denominator==0 && "error: Rational::squareRoot denomerator null");
    
	int a = this->getNumerator();
    int b = this-> getDenominator();
    if (a<0){
        std::cout << "No square root for negative number !" << std::endl;
        return Rational(0,1);
    }

    float e = std::sqrt(a);
    while (e >= 1){
        e = e-1;
    }
    float f = std::sqrt(b);
    while (f >= 1){
        f = f-1;
    }

    if (e==0 && f==0){
        a = std::sqrt(a);
        b=std::sqrt(b);
        return Rational(a,b);
    }

    //probleme de conversion car sqrt peut renvoyer floattoRatio
    std::cout << "The square root is not a rational number !" << std::endl;
    return Rational(0,1);
}*/

Rational Rational::absolute(){
    return Rational(std::abs(this->numerator), this->denominator);
}

/*template<typename T>
Rational<T> Rational<T>::absolute() {
    assert(this->denominator==0 && "error: Rational::absolute numerator null");
    
	return Rational(std::abs(this->numerator), this->denominator);
}*/

/* ----- Manipulations ----- */

int Rational::integerPart(){
    int res = 0;
    int a = abs(this->getNumerator());
    if (this->getDenominator() > a){
        return 0;
    }
    else if (this->getDenominator() == a){
        return 1;
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

/*template<typename T>
int Rational<T>::integerPart() {
    int res = 0;
    int a = abs(this->getNumerator());
    if (this->getDenominator() > a){
        return 0;
    }
    else if (this->getDenominator() == a){
        return 1;
    }
    else {
        int e = a;
        while(e > this->getDenominator()){
            e = e-this->getDenominator();
            res += 1;
        }
    }
    if(a != this->getNumerator()){
        res = -res;
    }
    return res;
}*/

Rational Rational::makeIrreductible(){
    int numerator = this->getNumerator();
    int denominator = this-> getDenominator();

    if(std::abs(std::gcd(numerator, denominator)) != 1) {
        numerator /= std::abs(std::gcd(numerator, denominator));
        denominator /= std::abs(std::gcd(numerator, denominator));
    }
    return Rational(numerator, denominator);
}

/*template<typename T>
Rational<T> Rational<T>::makeIrreductible() {
    //assert(this->denominator==0 && "error: Rational::makeIrreductible denominator null");
    
	int numerator = this->getNumerator();
    int denominator = this-> getDenominator();

    if(std::abs(std::gcd(numerator, denominator)) != 1) {
        numerator /= std::abs(std::gcd(numerator, denominator));
        denominator /= std::abs(std::gcd(numerator, denominator));
    }
    return Rational(numerator, denominator);
}*/


/* Methods outside Rational class */

Rational power(const Rational &ratio, const int &power) {
    if(power < 0) {
        Rational ratioCopy(ratio);
        int pow_numerator = std::pow(ratioCopy.getDenominator(), -power);
        int pow_denominator = std::pow(ratioCopy.getNumerator(), -power);
        return Rational(pow_numerator, pow_denominator);
    }
    int pow_numerator = std::pow(ratio.getNumerator(), power);
    int pow_denominator = std::pow(ratio.getDenominator(), power);
    return Rational(pow_numerator, pow_denominator);
}

Rational cosTaylor(const Rational &ratio) {
    return (Rational(1,1) - Rational(1,2)*power(ratio, 2) + Rational(1,24)*power(ratio, 4)).makeIrreductible();
}

Rational sinTaylor(const Rational &ratio) {
    Rational ratioCopy(ratio);
    return (ratioCopy - Rational(1,6)*power(ratio, 3) + Rational(1,120)*power(ratio, 5)).makeIrreductible();
}

Rational expTaylor(const Rational &ratio) {
    Rational ratioCopy(ratio);
    return (Rational(1,1) + ratioCopy + Rational(1,2)*power(ratio, 2) + Rational(1,6)*power(ratio, 3) + Rational(1,24)*power(ratio, 4) + Rational(1,120)*power(ratio, 5)).makeIrreductible();
}

Rational cosRatio(const Rational &ratio) {
    Rational result(1,1);
    Rational ratioCopy(ratio);
    // Near 0, use Taylor
    if( Rational(1,1) > ratioCopy ) {
        result = cosTaylor(ratio);
    }
    else {
        Rational int_part = Rational(ratioCopy.integerPart(), 1); // integer part of ratio
        Rational decimal_part = Rational(ratioCopy - int_part); // decimal part of ratio
            // cos(integer_part + decimal_part) ~ cos(a + b) = cos(a)cos(b) - sin(a)sin(b)
        result = cosTaylor(decimal_part).extProduct(std::cos(int_part.getNumerator()))-sinTaylor(decimal_part).extProduct(std::sin(int_part.getNumerator()));
    }

    if(std::abs(((float)result.getNumerator())/((float)result.getDenominator())) > 1) {
        std::cout << "The result is not coherent due to the limitation of memory (integers encoded are too big for this rational)..." << std::endl; 
    }
    return result;
}

Rational sinRatio(const Rational &ratio) {
    Rational result(1,1);
    Rational ratioCopy(ratio);
    // Near 0, use Taylor
    if( Rational(1,1) > ratioCopy ) {
        result = sinTaylor(ratio);
    }
    else {
        Rational int_part = Rational(ratioCopy.integerPart(), 1); // integer part of ratio
        Rational decimal_part = Rational(ratioCopy - int_part); // decimal part of ratio
            // sin(integer_part + decimal_part) ~ sin(a + b) = sin(a)cos(b) - sin(b)cos(a)
        result = cosTaylor(decimal_part).extProduct(std::sin(int_part.getNumerator()))-sinTaylor(decimal_part).extProduct(std::cos(int_part.getNumerator()));
    }

    if(std::abs(((float)result.getNumerator())/((float)result.getDenominator())) > 1) {
        std::cout << "The result is not coherent due to the limitation of memory (integers encoded are too big for this rational)..." << std::endl; 
    }
    return result;
}

Rational expRatio(const Rational &ratio) {
    Rational result(1,1);
    Rational ratioCopy(ratio);
    // Near 0, use Taylor
    if( Rational(1,1) > ratio ) {
        result = expTaylor(ratio);
    }
    else {
        Rational int_part = Rational(ratioCopy.integerPart(), 1); // integer part of ratio
        Rational decimal_part = Rational(ratioCopy - int_part); // decimal part of ratio
            // sin(integer_part + decimal_part) ~ sin(a + b) = sin(a)cos(b) - sin(b)cos(a)
        result = expTaylor(decimal_part).extProduct(std::exp(int_part.getNumerator()));
    }
    return result;
}

Rational floatToRatio(const float &x, unsigned int nbIter) {
    // keep the sign of x
    float sign;
    (x<0) ? sign = -1.0 : sign = 1.0;

    // resume with abs(x) as the sign was kept
    float absX = std::abs(x);

    // majoration of nbIter to keep a coherent result
    (nbIter > 10) ? nbIter = 10 : nbIter ;
    
    // stop conditions
    if(x == 0. || nbIter == 0) {
        return Rational(0,1);
    }

    // decimal part
    else if(absX < 1.0) {
        return floatToRatio(1/absX*sign, nbIter).invRatio();
    }

    // integer part
    else {
        return Rational(std::floor(absX)*sign, 1) + floatToRatio((absX-std::floor(absX))*sign, nbIter-1);
    }
}


std::ostream& operator<< (std::ostream& stream, const Rational &ratio) {
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

/*
template<typename T>
std::ostream& operator<< (std::ostream& stream, const Rational<T>& ratio){
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
}*/

