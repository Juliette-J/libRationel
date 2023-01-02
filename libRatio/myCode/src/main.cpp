#include "Rational.hpp"

#include <iostream>

int main() {

    //Rational ratio(1.1, 2.2);
    Rational rat1(1,3);
    Rational rat2(12,4);
    Rational rat3(5,9);
    Rational rat4 = rat3;
    Rational rat0(rat2);


    // Display and constructors
 
    std::cout << "Display and constructors : "<< std::endl;
    //std::cout << ratio << std::endl;
    std::cout << rat1 << std::endl;
    std::cout << rat2 << std::endl;
    std::cout << rat2.invRatio() << std::endl;
    std::cout << rat3 << std::endl;
    std::cout << rat4 << std::endl;
    std::cout << rat0 << std::endl;

    std::cout << std::endl;

    // Operators

    std::cout << "Operators tests : "<< std::endl;
    std::cout << "rat1+rat2 : " <<  rat1 + rat2 << std::endl;
    std::cout << "rat1-rat2 : " <<  rat1 - rat2 << std::endl;
    std::cout << "rat1*rat2 : " <<  rat1 * rat2 << std::endl;
    std::cout << "rat1/rat2 : " <<  rat1 / rat2 << std::endl;

    // minus
    Rational rati(1,-3);
    std::cout << rati << std::endl;
    std::cout << "moins unaire : " << -rati << std::endl;
    Rational rati2(7,3);
    std::cout << rati2 << std::endl;
    std::cout << "moins unaire : " << -rati2 << std::endl;

    std::cout << std::endl;

    // METHODS

    // makeIrreductible and squareRoot
    Rational rat5 = rat1 / rat2 ;
    std::cout << "rat1/rat2 irreductible : " <<  rat5.makeIrreductible() << std::endl;
    rat5 = rat5.makeIrreductible();
    std::cout << "rat1/rat2 squareroot nul : " <<  rat5.squareRoot() << std::endl;
    //std::cout << "rat1/rat2 carre : " <<  rat5.sqrt() << std::endl;

    Rational rat = rat1 - rat2 ;
    rat.makeIrreductible();
    std::cout << rat << std::endl;
    std::cout << "rat1-rat2 test squareroot nul : " << rat.squareRoot() << std::endl;
    Rational rat7(6,7);
    std::cout << "squareroot of : "<< rat7 << " = " << rat7.squareRoot() << std::endl;
    
    std::cout << std::endl;

    // absolute
    Rational rat8(6,-7);
    std::cout << "absolute of : "<< rat8 << " = " << rat8.absolute() << std::endl;

    // integerPart
    std::cout << "Integer : " << rati2.integerPart() << std::endl;

    // power
    std::cout << "power(rati, 3) : " << power(rati, 3) << std::endl;
    std::cout << "power(rati2, -2) : " << power(rati2, -2) << std::endl;

    // extern product
    std::cout << "rati2 x -3 : " << rati2*(-3.0) << std::endl;
    std::cout << "rati2 x -0.2 : " << rati2*(-0.2) << std::endl;

    // cos and sin
    std::cout << "cos(2) : " << cosRatio(Rational(2,1)) << std::endl;
    std::cout << "sin(0.5) : " << sinRatio(Rational(1,2)) << std::endl;
    std::cout << "cos(rati) : " << cosRatio(rati) << std::endl;
    std::cout << "sin(rati2) : " << sinRatio(rati2) << std::endl;

    // exponential
    std::cout << "exp(1) : " << expRatio(Rational(1,1)) << std::endl;
    std::cout << "exp(2) : " << expRatio(Rational(2,1)) << std::endl;
    std::cout << "exp(rati) : " << expRatio(rati) << std::endl;

    std::cout << std::endl;

    // Comparaisons

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

    std::cout << "rati == rati2 : " << (rati == rati2) << std::endl;
    std::cout << "rati == rati : " << (rati == rati) << std::endl;
    std::cout << "rati != rati2 : " << (rati != rati2) << std::endl;
    std::cout << "rati != rati : " << (rati != rati) << std::endl;

    // Conversion
    std::cout << "-2.5 to ratio : " << floatToRatio(-2.5 , 5) << std::endl;
    std::cout << "0.3 to ratio : " << floatToRatio(0.3, 10) << std::endl; // incoherent up to 10 epochs
    std::cout << "0.75 to ratio : " << floatToRatio(0.75, 5) << std::endl; // should be 3/4 ...

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

    return 0;
}