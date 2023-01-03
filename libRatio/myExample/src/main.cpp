#include "Rational.hpp"
#include "RatioOperators.hpp"
#include "RatioMethods.hpp"

#include <iostream>

int main() {

    Rational rat1(1,3);
    Rational rat2(12,4);
    Rational rat3(5,9);
    Rational rat4(rat3);
    Rational rati(1,-3);


    // Display and constructors
 
    std::cout << "Display and constructors : "<< std::endl;
    std::cout << rat1 << std::endl;
    std::cout << rat2 << std::endl;
    std::cout << rat2.invRatio() << std::endl;
    std::cout << rat3 << std::endl;
    std::cout << rat4 << std::endl;

    std::cout << std::endl;

    // Operators

    std::cout << "Operators : "<< std::endl;
    std::cout << "rat1+rat2 : " <<  rat1 + rat2 << std::endl;
    std::cout << "rat1-rat2 : " <<  rat1 - rat2 << std::endl;
    std::cout << "rat1*rat2 : " <<  rat1 * rat2 << std::endl;
    std::cout << "rat1/rat2 : " <<  rat1 / rat2 << std::endl;
    std::cout << "rat1/rati : " <<  rat1 / rati<< std::endl;
    std::cout << "rati/rat2 : " <<  rati / rat2 << std::endl;

    Rational rati2(7,3);
    std::cout << rati2 << std::endl;
    std::cout << "unity minus : " << -rati2 << std::endl;

    std::cout << std::endl;

    // Comparaisons

    std::cout << "rati == rati2 : " << (rati == rati2) << std::endl;
    std::cout << "rati == rati : " << (rati == rati) << std::endl;
    std::cout << "rati != rati2 : " << (rati != rati2) << std::endl;
    std::cout << "rati != rati : " << (rati != rati) << std::endl;

    Rational rati3(2,3);
    Rational rati4(-4,5);
    if (rati4>=rati3){
        std::cout << rati4 << " superieur a " << rati3 << std::endl;
    }
    else {
        std::cout << rati4 << " inferieur a " << rati3 << std::endl;
    }

    if (rati4<rati3){
        std::cout << rati4 << " inferieur a " << rati3 << std::endl;
    }
    else {
        std::cout << rati4 << " superieur a " << rati3 << std::endl;
    }
  
    if (rati4>rati3){
        std::cout << rati4 << " sup a " << rati3 << std::endl;
    }
    else {
        std::cout << rati4 << " inf a " << rati3 << std::endl;
    }


    if (rati4<=rati3){
        std::cout << rati4 << " inf a " << rati3 << std::endl;
    }
    else {
        std::cout << rati4 << " sup a " << rati3 << std::endl;
    }

    std::cout << std::endl;

    // METHODS

    // makeIrreductible and squareRoot
    Rational rat5 = rat1 / rat2 ;
    std::cout << "rat1/rat2 irreductible : " <<  rat5.makeIrreductible() << std::endl;
    rat5 = rat5.makeIrreductible();
    std::cout << "rat1/rat2 squareroot nul : " <<  rat5.squareRoot() << std::endl;

    Rational rat = rat1 - rat2 ;
    rat.makeIrreductible();
    std::cout << rat << std::endl;
    std::cout << "rat1-rat2 test squareroot nul : " << rat.squareRoot() << std::endl;
    Rational rat7(6,7);
    std::cout << "squareroot of : "<< rat7 << " = " << rat7.squareRoot() << std::endl;

    // absolute
    Rational rat8(6,-7);
    std::cout << "absolute of : "<< rat8 << " = " << rat8.absolute() << std::endl;

    // integerPart
    std::cout << "Integer : " << rati2.integerPart() << std::endl;

    // extern product
    std::cout << "rati2 x -3 : " << rati2*(-3.0) << std::endl;
    std::cout << "rati2 x -0.2 : " << rati2*(-0.2) << std::endl;

    // power
    std::cout << "power(rati, 3) : " << rati.power(3) << std::endl;
    std::cout << "power(rati2, -2) : " << rati2.power(-2) << std::endl;

    // Square root sqrt(r1)/sqrt(r2)
    std::cout << "sqrt(2/3) to ratio : " << rati3.squareRoot() << std::endl;
    std::cout << "sqrt(-2/3) to ratio : " << (-rati3).squareRoot() << std::endl;
    std::cout << "sqrt(4/9) to ratio : " << Rational(4,9).squareRoot() << std::endl;

    // Square root sqrt(r)
    std::cout << "sqrt2(2/3) to ratio : " << rati3.squareRoot2() << std::endl;
    std::cout << "sqrt2(-2/3) to ratio : " << (-rati3).squareRoot2() << std::endl;
    std::cout << "sqrt2(4/9) to ratio : " << Rational(4,9).squareRoot2() << std::endl;

    // Logarithm log(num)-log(den)
    std::cout << "log(2/3) to ratio : " << rati3.log() << std::endl;
    std::cout << "log(-2/3) to ratio : " << (-rati3).log() << std::endl;
    std::cout << "log(4/9) to ratio : " << Rational(4,9).log() << std::endl;

    // Logarithm log(r)
    std::cout << "log2(2/3) to ratio : " << rati3.log2() << std::endl;
    std::cout << "log2(-2/3) to ratio : " << (-rati3).log2() << std::endl;
    std::cout << "log2(4/9) to ratio : " << Rational(4,9).log2() << std::endl;

     // cos
    std::cout << "cosRatio(2) : " << Rational(2,1).cosRatio() << std::endl;
    std::cout << "cosRatio2(2) : " << Rational(2,1).cosRatio2() << std::endl;
    std::cout << "cosRatio(rati) : " << rati.cosRatio() << std::endl;

    // sin
    std::cout << "sinRatio(0.5) : " << Rational(1,2).sinRatio() << std::endl;
    std::cout << "sinRatio(rati2) : " << rati2.sinRatio() << std::endl;
    std::cout << "sinRatio2(rati2) : " << rati2.sinRatio2() << std::endl;
    std::cout << "sinRatio(rati) : " << rati.sinRatio() << std::endl;
    std::cout << "sinRatio(rati)/cosRatio(rati) : " << rati.sinRatio()/rati.cosRatio() << std::endl;

    // tan
    std::cout << "tanRatio(rati) : " << rati.tanRatio() << std::endl;
    std::cout << "tanRatio(rati2) : " << rati2.tanRatio() << std::endl;
    std::cout << "tanRatio2(rati2) : " << rati2.tanRatio2() << std::endl;

    // exponential
    std::cout << "expRatio(1) : " << Rational(1,1).expRatio() << std::endl;
    std::cout << "expRatio(2) : " << Rational(2,1).expRatio() << std::endl;
    std::cout << "expRatio(rati) : " << rati.expRatio() << std::endl;
    std::cout << "expRatio2(rati) : " << rati.expRatio2() << std::endl;

    std::cout << std::endl;
    
    // Conversion
    std::cout << "-2.5 to ratio : " << floatToRatio<int>(-2.5 , 5) << std::endl;
    std::cout << "0.3 to ratio : " << floatToRatio<int>(0.3, 10) << std::endl; // incoherent up to 10 epochs
    std::cout << "0.75 to ratio : " << floatToRatio<int>(0.75, 5) << std::endl; // should be 3/4 ...

    return 0;
}