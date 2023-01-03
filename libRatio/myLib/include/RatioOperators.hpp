#include "Rational.hpp"

#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <cassert>

#ifndef RATIOOPERATORS_HPP
#define RATIOOPERATORS_HPP

/* ---------------- Operators ---------------- */

/* ----------- Aritmetic ----------- */

template<typename T>
constexpr Rational<T> Rational<T>::operator+(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator+ denominator null");
    assert(this->denominator ==0 && "error: Rational::operator+ denominator null");
    
	T numerator = this->numerator*ratio.getDenominator() + this->denominator*ratio.getNumerator();
    T denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator-(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator- denominator null");
    assert(this->denominator ==0 && "error: Rational::operator- denominator null");

	T numerator = this->numerator*ratio.getDenominator() - this->denominator*ratio.getNumerator();
    T denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator-() {
    assert(this->denominator ==0 && "error: Rational::operator+ denominator null");

	return Rational(-this->numerator, this->denominator);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator*(const Rational &ratio) {
    assert(ratio.getDenominator() == static_cast<T>(0) && "error: Rational::operator* denominator null");
    assert(this->denominator == static_cast<T>(0) && "error: Rational::operator* denominator null");
	return Rational(this->numerator*ratio.getNumerator(), this->denominator*ratio.getDenominator());
}

template<typename T>
constexpr Rational<T> Rational<T>::operator*(const float &f) {
    assert(this->denominator == static_cast<T>(0) && "error: Rational::operator* denominator null");
	Rational fToRatio(floatToRatio<T>(f));
    return Rational((*this)*fToRatio);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator/(const Rational &ratio) {
    assert(ratio.getDenominator() == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    assert(this->denominator == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    Rational ratioCopy(ratio);
    return (*this)*ratioCopy.invRatio();
}

/* ----------- Comparison ----------- */

template<typename T>
constexpr bool Rational<T>::operator==(const Rational &ratio) {
    assert(ratio.getDenominator() == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    assert(this->denominator == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    if(this->getNumerator() == ratio.getNumerator() && this->getDenominator() == ratio.getDenominator()) {
        return true;
    }
    return false;
}

template<typename T>
constexpr bool Rational<T>::operator!=(const Rational &ratio) {
    assert(ratio.getDenominator() == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    assert(this->denominator == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    return !(*this == ratio);
}

template<typename T>
constexpr bool Rational<T>::operator>=(const Rational &ratio) {
    assert(ratio.getDenominator() == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    assert(this->denominator == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    T deno1 = ratio.getDenominator();
    T deno2 = this->getDenominator();
    T nume1 = ratio.getNumerator();
    T nume2 = this->getNumerator();
    nume1 = nume1 * deno2;
    nume2 = nume2 * deno1;
    if (nume2 >= nume1) {
        return true;
    }
    return false;
}

template<typename T>
constexpr bool Rational<T>::operator<(const Rational &ratio) {
    assert(ratio.getDenominator() == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    assert(this->denominator == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    return !(*this >= ratio);
}

template<typename T>
constexpr bool Rational<T>::operator<=(const Rational &ratio) {
    assert(ratio.getDenominator() == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    assert(this->denominator == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    return (*this<ratio || *this==ratio);
}

template<typename T>
constexpr bool Rational<T>::operator>(const Rational &ratio) {
    assert(ratio.getDenominator() == static_cast<T>(0) && "error: Rational::operator/ denominator null");
    assert(this->denominator == 0 && "error: Rational::operator/ denominator null"); 
    return !(*this <= ratio);
}

#endif