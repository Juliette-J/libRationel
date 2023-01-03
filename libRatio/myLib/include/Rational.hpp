#include <iostream>
#include <numeric>
#include <cmath>

#ifndef RATIONNELS_HPP
#define RATIONNELS_HPP

// Doxygen menu
/// \mainpage
/// \tableofcontents
/// \section instroduction_sec libRational
/// By Charline Le Pape and Juliette Jeannin.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li Gtest
/// \li Cmake
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux / Mac)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li if Doxygen installed: make html
/// \li The documentation is located in :
/// 	- [path to build]/doc/doc-doxygen/html/index.html or 
/// 	- or [path to build]/INTERFACE/doc/doc-doxygen/html/index.html


/// \class Rational
/// \brief Class defining a rational number for linear algebra operations.
template<typename T = int>
class Rational {
    private :
        T numerator;
        T denominator;

    public :
        /* ---------------- Constructors ---------------- */
        
        /// \brief Constructor from two types of int
	    /// \param num : the numerator of the rational
	    /// \param den : the denominator of the rational
        constexpr Rational(const T &num = static_cast<T>(1), const T &den = static_cast<T>(1));
        
        /// \brief Copy-constructor
	    /// \param ratio : the source rational to be copied
	    constexpr Rational(const Rational &ratio) = default; // by copy

        /* ---------------- Destructor ---------------- */

        /// \brief Destructor
        ~Rational() = default;

        /* ---------------- Operators ---------------- */

        /// \brief Add two rational numbers
        /// \param ratio : constant rational number
        /// \return a rational number which is the sum of the two rational numbers
        constexpr Rational operator+(const Rational &ratio);

        /// \brief Subtract a rational number to a rational number
         /// \param ratio : constant rational number
        /// \return a rational number which is the substraction between the two rational numbers
        constexpr Rational operator-(const Rational &ratio);

        /// \brief Make the negation of a rational number
        /// \return the opposite of the rational number
        constexpr Rational operator-();

        
        /// \brief Multiply two rational numbers
        /// \param ratio : constant rational number
        /// \return a rational which is the product of the two rational numbers
        constexpr Rational operator*(const Rational &ratio);

        /// \brief Multiply a rational number by a float
        /// \param f : constant float
        /// \return a rational which is the product of the rational and the float
        constexpr Rational operator*(const float &f); // extern product

        /// \brief Divide a rational number by another rational number
        /// \param ratio : constant rational number
        /// \return a rational number which is the result of the division
        constexpr Rational operator/(const Rational &ratio);


        /// \brief Check the equality between 2 rational numbers
        /// \param ratio : constant rational number
        /// \return a boolean (true or false)
        constexpr bool operator==(const Rational &ratio);

        /// \brief Check the inequality between 2 rational numbers
        /// \param ratio : constant rational number
        /// \return a boolean (true or false)
        constexpr bool operator!=(const Rational &ratio);

        /// \brief Check the equality or the superiority between 2 rational numbers
        /// \param ratio : constant rational number
        /// \return a boolean (true or false)
        constexpr bool operator>=(const Rational &ratio);

        /// \brief Check the equality or inferiority between 2 rational numbers
        /// \param ratio : constant rational number
        /// \return a boolean (true or false)
        constexpr bool operator<=(const Rational &ratio);

        /// \brief Check the inferiority between 2 rational numbers
        /// \param ratio : constant rational number
        /// \return a boolean (true or false)
        constexpr bool operator<(const Rational &ratio);

        /// \brief Check the superiority between 2 rational numbers
        /// \param ratio : constant rational number
        /// \return a boolean (true or false)
        constexpr bool operator>(const Rational &ratio);
        

        /* ---------------- Methods ---------------- */

        /* ----- Getter ----- */

        /// \brief Getter to access to rational's numerator
        /// \return rational's numerator (int, long int, ...)
        constexpr int getNumerator() const {return numerator; }; // get the numerator of the rational

        /// \brief Getter to access to rational's denominator
        /// \return rational's denominator  (int, long int, ...)
        constexpr int getDenominator() const {return denominator; }; // get the denominator of the rational

        /* ----- Arithmetics ----- */

        /// \brief Invert a rational number
        /// \return a rational with the numerator and denominator exchanged or an error if the numerator equals 0
        constexpr Rational invRatio(); // invert the rational

        /// \brief Calculate the square root of a rational number a/b by making sqrt(a.)/sqrt(b.)
        /// \return a rational or an error if the numerator is negative
        constexpr Rational squareRoot(); // square root

        /// \brief Calculate square root of a rational number by making the square root of the rational converted into a float
        /// \return a rational or an error if the numerator is negative
        constexpr Rational squareRoot2();

        /// \brief Calculate the power of a rational number 
        /// \param factor : integer number corresponding to the exponent
        /// \return the powered rational
        constexpr Rational power(const int &factor); // power

        /// \brief Calculate the logarithm of a rational number by making log(a.)-log(b.)
        /// \return a rational or an error if the numerator is negative
        constexpr Rational log(); // logarithm

        /// \brief Calculate the logarithm of a rational number by making the logarithm of the rational converted into a float 
        /// \return a rational or an error if the numerator is negative
        constexpr Rational log2(); // logarithm

        /// \brief Calculate the absolute value of a rational number 
        /// \return a rational with a positive numerator
        constexpr Rational absolute(); // absolute value

        /// \brief Calculate the integer part of a rational number 
        /// \return an integer 
        constexpr int integerPart(); // integer part

        /// \brief Calculate the cosinus of a rational number near 0
        /// \return the cosinus of the rational number under Rational type   
        constexpr Rational cosTaylor();

        /// \brief Calculate the sinus of a rational number near 0
        /// \return the sinus of the rational number under Rational type
        constexpr Rational sinTaylor();

        /// \brief Calculate the exponential of a rational number near 0
        /// \return the exponential of the rational number under Rational type
        constexpr Rational expTaylor();

        /// \brief Calculate the cosinus of a rational number using cosTaylor()
        /// \return the cosinus of the rational number under Rational type
        constexpr Rational cosRatio();

        /// \brief Calculate the sinus of a rational number using sinTaylor()
        /// \return the sinus of the rational number under Rational type
        constexpr Rational sinRatio();

        /// \brief Calculate the tangent of a rational number by making sinRatio()/cosRatio()
        /// \return tan of the rational number under Rational type
        constexpr Rational tanRatio();

        /// \brief Calculate the exponential of a rational number using expTaylor()
        /// \return the exponential of the rational number under Rational type
        constexpr Rational expRatio();

        /// \brief Calculate the cosinus of a rational number only using std::cos
        /// \return the cosinus of the rational number under Rational type
        constexpr Rational cosRatio2();

        /// \brief Calculate the sinus of a rational number only using std::sin
        /// \return the sinus of the rational number under Rational type
        constexpr Rational sinRatio2();

        /// \brief Calculate the tangent of a rational number by making sinRatio2()/cosRatio2()
        /// \return tan of the rational number under Rational type
        constexpr Rational tanRatio2();

        /// \brief Calculate the exponential of a rational number only using std::exp
        /// \return the exponential of the rational number under Rational type
        constexpr Rational expRatio2();

        /* ----- Manipulations ----- */

        /// \brief Transform a rational number into an irreducible rational number
        /// \return an irreductible rational 
        constexpr Rational makeIrreductible(); // make a rational irreductible

};

/* ------- Methods outside Rational class ------- */

/// \brief Convert a real number to a rational number in some iterations
/// \param x : constant float (to convert)
/// \param nbIter : unisgned integer (number of iterations that will be made)
/// \return a rational number

template<typename T>
constexpr Rational<T> floatToRatio(const float &x, unsigned int nbIter = 5); // conversion float to rational


/// \brief Display a rational number
/// \return return a rational in the form a/b or just a if b equals 1 or an error if a=b=0

template<typename T>
constexpr std::ostream& operator<< (std::ostream& stream, const Rational<T> &ratio);


/// \brief Make th product of a float by a rational number
/// \param f : constant float
/// \param ratio : constant rational number
/// \return a rational number

template<typename T>
constexpr Rational<T> extProductReal(const float &f, const Rational<T> &ratio); // extern product for float


/* ---------------- Constructors ---------------- */

template<typename T>
constexpr Rational<T>::Rational(const T &num, const T &den) {
    // 0 exception
    if(den == static_cast<T>(0)) {
        // infinite
        if(num == static_cast<T>(1)) {
            std::cout << "You reached the infinite !" << std::endl;
            numerator = static_cast<T>(1);
            denominator = static_cast<T>(0);
        }
        // zero
        else {
            std::cout << "It's impossible to divide by 0 ! We let you to 0." << std::endl;
            numerator = static_cast<T>(0);
            denominator = static_cast<T>(1);
        }
    }
    // case b < 0 (negative denominator)
    if(den < 0) {
        numerator = -num;
        denominator = -den;
    } 
    else {
        numerator = num;
        denominator = den;
    }
    // make it irreductible
    int GCD = std::gcd(numerator, denominator);
    if(std::abs(GCD) != 1) {
        numerator = numerator/std::abs(GCD);
        denominator = denominator/std::abs(GCD);
    }
}

#endif