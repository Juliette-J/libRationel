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
    try {
        if((this->denominator == static_cast<T>(0) && this->numerator != static_cast<T>(1)) 
        || (ratio.getDenominator() == static_cast<T>(0) && ratio.getNumerator() != static_cast<T>(1))) throw std::invalid_argument("error");
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Invalid argument (Rational with 0 as denominator and not the infinite)." << std::endl;
    }

	T numerator = this->numerator*ratio.getDenominator() + this->denominator*ratio.getNumerator();
    T denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator-(const Rational &ratio) {
    try {
        if((this->denominator == static_cast<T>(0) && this->numerator != static_cast<T>(1)) 
        || (ratio.getDenominator() == static_cast<T>(0) && ratio.getNumerator() != static_cast<T>(1))) throw std::invalid_argument("error");
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Invalid argument (Rational with 0 as denominator and not the infinite)." << std::endl;
    }

	T numerator = this->numerator*ratio.getDenominator() - this->denominator*ratio.getNumerator();
    T denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator-() {
    try {
        if(this->denominator == static_cast<T>(0) && this->numerator != static_cast<T>(1)) throw std::invalid_argument("error");
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Invalid argument (Rational with 0 as denominator and not the infinite)." << std::endl;
    }

	return Rational(-this->numerator, this->denominator);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator*(const Rational &ratio) {
    try {
        if((this->denominator == static_cast<T>(0) || (ratio.getDenominator() == static_cast<T>(0))) && ratio.getNumerator() != static_cast<T>(1)) throw std::invalid_argument("error");
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Invalid argument (Rational with 0 as denominator and not the infinite)." << std::endl;
    }

	return Rational(this->numerator*ratio.getNumerator(), this->denominator*ratio.getDenominator());
}

template<typename T>
constexpr Rational<T> Rational<T>::operator*(const float &f) {
    try {
        if(this->denominator == static_cast<T>(0) && this->numerator != static_cast<T>(1)) throw std::invalid_argument("error");
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Invalid argument (Rational with 0 as denominator and not the infinite)." << std::endl;
    }

	Rational fToRatio(floatToRatio<T>(f));
    return Rational((*this)*fToRatio);
}

template<typename T>
constexpr Rational<T> Rational<T>::operator/(const Rational &ratio) {
    try {
        if((this->denominator == static_cast<T>(0) && this->numerator != static_cast<T>(1)) 
        || (ratio.getDenominator() == static_cast<T>(0) && ratio.getNumerator() != static_cast<T>(1))) throw std::invalid_argument("error");
    }
    catch(const std::invalid_argument& e) {
        std::cerr << "Invalid argument (Rational with 0 as denominator and not the infinite)." << std::endl;
    }

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
    T nume1 = this->getNumerator() * ratio.getDenominator();
    T nume2 = ratio.getNumerator() * this->getDenominator();
    if (nume1 >= nume2) {
        return true;
    }
    return false;
}

template<typename T>
constexpr bool Rational<T>::operator<(const Rational &ratio) {

    return !((*this) >= ratio);
}

template<typename T>
constexpr bool Rational<T>::operator<=(const Rational &ratio) {
    return (((*this)<ratio) || ((*this)==ratio));
}

template<typename T>
constexpr bool Rational<T>::operator>(const Rational &ratio) {

    return !((*this) <= ratio);
}

#endif