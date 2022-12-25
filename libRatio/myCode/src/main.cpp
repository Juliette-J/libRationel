#include "Rational.hpp"

#include <iostream>

int main() {

    Rational rat1(1,3);
    Rational rat2(12,4);
    Rational rat3(5,9);
    Rational rat4 = rat3;
 
    std::cout << "Test de d'affichage et constructeur : "<< std::endl;
    std::cout << rat1 << std::endl;
    std::cout << rat2 << std::endl;
    std::cout << rat2.InvRatio() << std::endl;
    std::cout << rat3 << std::endl;
    std::cout << rat4 << std::endl;


    std::cout << "Test d'opération : "<< std::endl;
    std::cout << "rat1+rat2 : " <<  rat1 + rat2 << std::endl;
    std::cout << "rat1-rat2 : " <<  rat1 - rat2 << std::endl;

    std::cout << "rat1*rat2 : " <<  rat1 * rat2 << std::endl;
    std::cout << "rat1/rat2 : " <<  rat1 / rat2 << std::endl;

    Rational rat5 = rat1 / rat2 ;
    std::cout << "rat1/rat2 irreductible : " <<  rat5.irreductible() << std::endl;
    rat5 = rat5.irreductible();
     std::cout << "rat1/rat2 squareroot nul : " <<  rat5.squareroot() << std::endl;
    //std::cout << "rat1/rat2 carre : " <<  rat5.sqrt() << std::endl;

    Rational rat = rat1 - rat2 ;
    rat.irreductible();
    std::cout << rat << std::endl;
    std::cout << "rat1-rat2 test squareroot nul : " << rat.squareroot() << std::endl;
    Rational rat7(6,7);
    std::cout << "squareroot de : "<< rat7 << " = " << rat7.squareroot() << std::endl;
    
    Rational rat8(6,-7);
    std::cout << "absolute de : "<< rat8 << " = " << rat8.absolute() << std::endl;


    Rational rati(1,-3);
    std::cout << rati << std::endl;
    std::cout << "moins unaire : " << -rati << std::endl;

    Rational rati2(7,3);
    std::cout << rati2 << std::endl;
    std::cout << "moins unaire : " << -rati2 << std::endl;

    std::cout << "Entier : " << rati2.entier() << std::endl;


    return 0;
}