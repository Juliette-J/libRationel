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



    return 0;
}