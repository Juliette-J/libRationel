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
    //assert(ratio.getDenominator() == 0 || *this->denominator && "error: Rational::operator+ denominator null");
	T numerator = this->numerator*ratio.getDenominator() + this->denominator*ratio.getNumerator();
    T denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator-(const Rational &ratio) {
    //assert(ratio.getDenominator() == 0 || *this->denominator && "error: Rational::operator- denominator null");
	T numerator = this->numerator*ratio.getDenominator() - this->denominator*ratio.getNumerator();
    T denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator-() {
    //assert(*this->denominator && "error: Rational::operator- denominator null");
	return Rational(-this->numerator, this->denominator);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator*(const Rational &ratio) {
    //assert(ratio.getDenominator() == 0 || *this->denominator && "error: Rational::operator* denominator null");
	return Rational(this->numerator*ratio.getNumerator(), this->denominator*ratio.getDenominator());
}

template<typename T>
constexpr Rational<T> Rational<T>::operator*(const float &f) {
	Rational fToRatio(floatToRatio<T>(f));
    return Rational((*this)*fToRatio);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator/(const Rational &ratio) {
    //assert(ratio.getDenominator() == 0 || *this->denominator && "error: Rational::operator* denominator null");
    //return Rational(this->numerator*ratio.getDenominator(), this->denominator*ratio.getNumerator());
    Rational ratioCopy(ratio);
    return (*this)*ratioCopy.invRatio();
}

/* ----------- Comparison ----------- */

template<typename T>
constexpr bool Rational<T>::operator==(const Rational &ratio) {
    if(this->getNumerator() == ratio.getNumerator() && this->getDenominator() == ratio.getDenominator()) {
        return true;
    }
    return false;
}

template<typename T>
constexpr bool Rational<T>::operator!=(const Rational &ratio) {
    return !(*this == ratio);
}

template<typename T>
constexpr bool Rational<T>::operator>=(const Rational &ratio) {
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
    return !(*this >= ratio);
}


template<typename T>
constexpr bool Rational<T>::operator<=(const Rational &ratio) {
    return (*this<ratio || *this==ratio);
}


template<typename T>
constexpr bool Rational<T>::operator>(const Rational &ratio) {
    return !(*this <= ratio);
}

#endif