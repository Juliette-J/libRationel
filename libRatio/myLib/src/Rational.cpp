#include "Rational.hpp"

#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <cassert>



/* Constructors */

Rational::Rational(const int &a, const int &b) {
    // 0 exception
    if(b == 0) {
        if(a==1) {
            std::cout << "You reached the infinite !" << std::endl;
            numerator = 1;
            denominator = 0;
        }
        else {
            std::cout << "It's impossible to divide by 0 ! We let you to 0." << std::endl;
            numerator = 0;
            denominator = 1;
        }
    }

    // make it irreductible
    if(std::abs(std::gcd(a,b)) != 1) {
        numerator /= std::abs(std::gcd(a,b));
        denominator /= std::abs(std::gcd(a,b));
    }

    // case b < 0
    if(b < 0) {
        numerator = -a;
        denominator = -b;
    } 
    else {
        numerator = a;
        denominator = b;
    }
}


/* Operators */ 

Rational Rational::operator+(const Rational &ratio) {
	int numerator = this->numerator*ratio.getDenominator() + this->denominator*ratio.getNumerator();
    int denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

Rational Rational::operator-(const Rational &ratio) {
	int numerator = this->numerator*ratio.getDenominator() - this->denominator*ratio.getNumerator();
    int denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

Rational Rational::operator-() {
	return Rational(-this->numerator, this->denominator);
}


Rational Rational::operator*(const Rational &ratio) {
	int numerator = this->numerator*ratio.getNumerator();
    int denominator = this->denominator*ratio.getDenominator();
	return Rational(numerator, denominator);
}

Rational Rational::operator/(const Rational &ratio) {
   return Rational(this->numerator*ratio.getDenominator(), this->denominator*ratio.getNumerator());
}

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

Rational Rational::InvRatio(){
	return Rational(this->getDenominator(), this->getNumerator());
}

int Rational::entier(){
    int res =0;
    int a = abs(this->getNumerator());
    if (this->getDenominator() > a){
        return 0;
    }
    else if (this->getDenominator() == a){
        return 1;
    }
    else {
        int e = a;
        while(e>this->getDenominator()){
            e=e-this->getDenominator();
            res +=1;
        }
    }
    if(a!=this->getNumerator()){
        res =-res;
    }
    return res;
}


Rational Rational::irreductible(){

    int a = this->getNumerator();
    int b = this-> getDenominator();

    if(std::abs(std::gcd(a,b)) != 1) {
        numerator /= std::abs(std::gcd(a,b));
        denominator /= std::abs(std::gcd(a,b));
        return Rational(numerator, denominator);
    }
    return Rational(a,b);
}

/*pas fini je reflechis encore dessus... parce que sqrt de 3 ca va etre complique*/
Rational Rational::squareroot(){
    int a = this->getNumerator();
    int b = this-> getDenominator();
    if (a<0){
        std::cout << "No square root for negative number !" << std::endl;
        return 0;
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
    return 0;
}

Rational Rational::absolute(){
    return Rational(std::abs(this->numerator), this->denominator);
}

/* Methods*/

Rational floatToRatio(const float &x, unsigned int nbIter) {
    // keep the sign of x
    int sign;
    (x<0) ? sign = -1 : sign = 1;

    // stop conditions
    if(x==0 || nbIter == 0) {
        return Rational(0,1);
    }
    // decimal part
    else if(x < 1) {
        return power((floatToRatio(1/x, nbIter)), -1);
    }
    // int part
    else {
        int int_part = std::floor(x);
        return Rational(int_part, 1) + floatToRatio(x-int_part, nbIter-1);
    }
}




/* Operations */

Rational power(const Rational &ratio, const int &power) {
    int pow_numerator = std::pow(ratio.getNumerator(), power);
    int pow_denominator = std::pow(ratio.getDenominator(), power);
    return Rational(pow_numerator, pow_denominator);
}



std::ostream& operator<< (std::ostream& stream, const Rational &ratio) {
	if(ratio.getNumerator() == 0 && ratio.getDenominator() ==0){
		stream << "Not initialized yet -> 0/0 IMPOSSIBLE";
		return stream;
	}
    else if(ratio.getDenominator()==1){
        stream << ratio.getNumerator();
    }
			
	else {
        stream << ratio.getNumerator() << "/" << ratio.getDenominator() ;
    }

	return stream;
}

