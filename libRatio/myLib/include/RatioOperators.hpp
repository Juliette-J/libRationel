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

/// \brief Operation+ to add two rational numbers together
/// \param ratio a constant rational number
/// \return a rational 

template<typename T>
constexpr Rational<T> Rational<T>::operator+(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator+ denominator null");
    assert(this->denominator ==0 && "error: Rational::operator+ denominator null");
    
	T numerator = this->numerator*ratio.getDenominator() + this->denominator*ratio.getNumerator();
    T denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

/// \brief Operation- to subtract a rational number to a rational number
/// \param ratio a constant rational number
/// \return a rational 

template<typename T>
constexpr Rational<T> Rational<T>::operator-(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator- denominator null");
    assert(this->denominator ==0 && "error: Rational::operator- denominator null");

	T numerator = this->numerator*ratio.getDenominator() - this->denominator*ratio.getNumerator();
    T denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

/// \brief Operation- to make the negation of a rational number
/// \return a rational 

template<typename T>
constexpr Rational<T> Rational<T>::operator-() {
    assert(this->denominator ==0 && "error: Rational::operator+ denominator null");

	return Rational(-this->numerator, this->denominator);
}

/// \brief Operation* to multiply two rational numbers
/// \param ratio a constant rational number
/// \return a rational 

template<typename T>
constexpr Rational<T> Rational<T>::operator*(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator* denominator null");
    assert(this->denominator ==0 && "error: Rational::operator* denominator null");
	return Rational(this->numerator*ratio.getNumerator(), this->denominator*ratio.getDenominator());
}

/// \brief Operation* to multiply a rational number by a float
/// \param f a constant float
/// \return a rational 

template<typename T>
constexpr Rational<T> Rational<T>::operator*(const float &f) {
    assert(this->denominator ==0 && "error: Rational::operator* denominator null");
	Rational fToRatio(floatToRatio<T>(f));
    return Rational((*this)*fToRatio);
}

/// \brief Operation/ to subtract a rational number to a rational number
/// \param ratio a constant rational number
/// \return a rational 

template<typename T>
constexpr Rational<T> Rational<T>::operator/(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator/ denominator null");
    assert(this->denominator ==0 && "error: Rational::operator/ denominator null");
    Rational ratioCopy(ratio);
    return (*this)*ratioCopy.invRatio();
}

/* ----------- Comparison ----------- */

/// \brief Operation== to check the equality between 2 rationals
/// \param ratio a constant rational number
/// \return a boolean (true or false)


template<typename T>
constexpr bool Rational<T>::operator==(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator/ denominator null");
    assert(this->denominator ==0 && "error: Rational::operator/ denominator null");
    if(this->getNumerator() == ratio.getNumerator() && this->getDenominator() == ratio.getDenominator()) {
        return true;
    }
    return false;
}

/// \brief Operation!= to check the inequality between 2 rationals
/// \param ratio a constant rational number
/// \return a boolean (true or false)

template<typename T>
constexpr bool Rational<T>::operator!=(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator/ denominator null");
    assert(this->denominator ==0 && "error: Rational::operator/ denominator null");
    return !(*this == ratio);
}

/// \brief Operation>= to check the equality or the superiority between 2 rationals
/// \param ratio a constant rational number
/// \return a boolean (true or false)

template<typename T>
constexpr bool Rational<T>::operator>=(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator/ denominator null");
    assert(this->denominator ==0 && "error: Rational::operator/ denominator null");
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

/// \brief Operation< to check the inferiority between 2 rationals
/// \param ratio a constant rational number
/// \return a boolean (true or false)

template<typename T>
constexpr bool Rational<T>::operator<(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator/ denominator null");
    assert(this->denominator ==0 && "error: Rational::operator/ denominator null");
    return !(*this >= ratio);
}

/// \brief Operation<= to check the equality or inferiority between 2 rationals
/// \param ratio a constant rational number
/// \return a boolean (true or false)

template<typename T>
constexpr bool Rational<T>::operator<=(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator/ denominator null");
    assert(this->denominator ==0 && "error: Rational::operator/ denominator null");
    return (*this<ratio || *this==ratio);
}

/// \brief Operation> to check the equality or inferiority between 2 rationals
/// \param ratio a constant rational number
/// \return a boolean (true or false)


template<typename T>
constexpr bool Rational<T>::operator>(const Rational &ratio) {
    assert(ratio.getDenominator() == 0 && "error: Rational::operator/ denominator null");
    assert(this->denominator ==0 && "error: Rational::operator/ denominator null"); 
    return !(*this <= ratio);
}

#endif