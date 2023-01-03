#include "Rational.hpp"
#include "RatioOperators.hpp"
#include "RatioMethods.hpp"

#include <random>
#include <chrono>
#include <cmath>
#include <numeric>
#include <functional>
#include <gtest/gtest.h>

/* Constructor */
TEST (RatioConstructor, constructor) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		int num = gen();
		int den = gen();
		Rational ratio(num, den);

		if(den < 0) {
			num = -num;
			den = -den;
		}

	    ASSERT_EQ(ratio.getNumerator()*std::gcd(num, den), num);
		ASSERT_EQ(ratio.getDenominator()*std::gcd(num, den), den);
	}
}

/* Conversion -> float to rational */

TEST (RatioConversion, floatToRatio) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_real_distribution<float> uniformFloatDistribution(-20,20);
	auto gen = std::bind(uniformFloatDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		const float real = gen();
		Rational<int> ratio(floatToRatio<int>(real, 5));

		// keep the integer part + the three first decimals of the exact solution
		float exactResult = real*1000;
		exactResult = std::floor(exactResult+0.5); // +0.5 to have the rounded value

		// keep the integer part + the three first decimals of the found solution
		float result = ((float)ratio.getNumerator())/((float)ratio.getDenominator());
		result *= 1000;
		result = std::floor(result+0.5); // +0.5 to have the rounded value

	    ASSERT_EQ(result, exactResult);
	}
}

/* Operators */

TEST (RatioOperators, plus) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen()), ratio2(gen(), gen());
		Rational ratio3 = ratio1 + ratio2;
		Rational ratio4(ratio1.getNumerator()*ratio2.getDenominator() + ratio1.getDenominator()*ratio2.getNumerator(), ratio1.getDenominator()*ratio2.getDenominator());

	    ASSERT_EQ(ratio3.getNumerator(), ratio4.getNumerator());
		ASSERT_EQ(ratio3.getDenominator(), ratio4.getDenominator());
	}
}

TEST (RatioOperators, minus) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen()), ratio2(gen(), gen());
		Rational ratio3 = ratio1 - ratio2;
		Rational ratio4(ratio1.getNumerator()*ratio2.getDenominator() - ratio1.getDenominator()*ratio2.getNumerator(), ratio1.getDenominator()*ratio2.getDenominator());

	    ASSERT_EQ(ratio3.getNumerator(), ratio4.getNumerator());
		ASSERT_EQ(ratio3.getDenominator(), ratio4.getDenominator());
	}
}

TEST (RatioOperators, minusUnity) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2 = -ratio1;
		Rational ratio3(-ratio1.getNumerator(), ratio1.getDenominator());

	    ASSERT_EQ(ratio2.getNumerator(), ratio3.getNumerator());
		ASSERT_EQ(ratio2.getDenominator(), ratio3.getDenominator());
	}
}


TEST (RatioOperators, product) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-20,20);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen()), ratio2(gen(), gen());
		Rational ratio3 = ratio1*ratio2;
		Rational ratio4(ratio1.getNumerator()*ratio2.getNumerator(), ratio1.getDenominator()*ratio2.getDenominator());

	    ASSERT_EQ(ratio3.getNumerator(), ratio4.getNumerator());
		ASSERT_EQ(ratio3.getDenominator(), ratio4.getDenominator());
	}
}

TEST (RatioOperators, externProductRatio) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_real_distribution<float> uniformRealDistribution(-20,20);
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto genReal = std::bind(uniformRealDistribution, generator);
	auto genInt = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		float real = genReal();
		Rational ratio1(genInt(), genInt());
		Rational ratio2(ratio1*real);

		// keep the integer part + the three first decimals of the exact solution
		float exactResult = real*(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()))*1000;
		exactResult = std::floor(exactResult+0.5); // +0.5 to have the rounded value

		// keep the integer part + the three first decimals of the found solution
		float result = ((float)ratio2.getNumerator())/((float)ratio2.getDenominator());
		result *= 1000;
		result = std::floor(result+0.5); // +0.5 to have the rounded value

	    ASSERT_EQ(result, exactResult);
	}
}

TEST (RatioOperators, externProductReal) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_real_distribution<float> uniformRealDistribution(-20,20);
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto genReal = std::bind(uniformRealDistribution, generator);
	auto genInt = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		float real = genReal();
		Rational ratio1(genInt(), genInt());
		Rational ratio2 = extProductReal(real,ratio1);

		// keep the integer part + the three first decimals of the exact solution
		float exactResult = real*(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()))*1000;
		exactResult = std::floor(exactResult+0.5); // +0.5 to have the rounded value

		// keep the integer part + the three first decimals of the found solution
		float result = ((float)ratio2.getNumerator())/((float)ratio2.getDenominator());
		result *= 1000;
		result = std::floor(result+0.5); // +0.5 to have the rounded value

	    ASSERT_EQ(result, exactResult);
	}
}

TEST (RatioOperators, division) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-20,20);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen()), ratio2(gen(), gen());
		Rational ratio3(ratio1/ratio2);
		Rational ratio4(ratio1*ratio2.invRatio());

		ASSERT_EQ(ratio3.getDenominator(), ratio4.getDenominator());
		ASSERT_EQ(ratio3.getNumerator(), ratio4.getNumerator());
	}
}

/* Comparisons */

TEST (RatioComparisons, similarity) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2 = ratio1;

		ASSERT_EQ(ratio1.getNumerator(), ratio2.getNumerator());
		ASSERT_EQ(ratio1.getDenominator(), ratio2.getDenominator());
	    ASSERT_TRUE( ratio1 == ratio2);
	}
}

TEST (RatioComparisons, difference) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(60, 1);
		Rational ratio2(gen(), gen());

		ASSERT_TRUE(ratio1 != ratio2);
	}
}

TEST (RatioComparisons, superiorOrEqual) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(50, 1);
		Rational ratio2(gen(), gen());

		ASSERT_TRUE(ratio1 >= ratio2);
	}
}

TEST (RatioComparisons, inferior) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(),gen());
		Rational ratio2(60,1);

		ASSERT_TRUE(ratio1 < ratio2);
	}
}

TEST (RatioComparisons, inferiorOrEqual) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(60,1);

		ASSERT_TRUE(ratio1 < ratio2);
	}
}

TEST (RatioComparisons,  superior) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(60, 1);
		Rational ratio2(gen(), gen());

		ASSERT_TRUE(ratio1 > ratio2);
	}
}

/* ---------------- Methods ---------------- */

/* ----- Arithmetics ----- */

TEST (RatioArithmetic, inverse) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.invRatio());

	    ASSERT_EQ(std::abs(ratio2.getNumerator()), ratio1.getDenominator());
        ASSERT_EQ(ratio2.getDenominator(), std::abs(ratio1.getNumerator()));
	}
}

TEST (RatioArithmetic, squareRoot) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(0,100);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.squareRoot());

		float squareRootNum = std::sqrt(ratio1.getNumerator());
    	float squareRootDen = std::sqrt(ratio1.getDenominator());

    	Rational ratio3(floatToRatio<int>(squareRootNum , 7)/floatToRatio<int>(squareRootDen, 7));
    
	    ASSERT_EQ(ratio2.getNumerator(), ratio3.getNumerator());
        ASSERT_EQ(ratio2.getDenominator(),ratio3.getDenominator());

		/*ASSERT_TRUE(std::abs(ratio2-ratio3)/std::abs(ratio2) < Rational(1/1000));*/
	}
}

TEST (RatioArithmetic, squareRoot2) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(0,100);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.squareRoot2());

		float squareRoot = std::sqrt(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));
    	Rational ratio3(floatToRatio<int>(squareRoot , 7));

	    ASSERT_EQ(ratio2.getNumerator(), ratio3.getNumerator());
        ASSERT_EQ(ratio2.getDenominator(),ratio3.getDenominator());
	}
}

TEST (RatioArithmetic, logarithm) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(1,100);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.log());

		float logNum = std::log(ratio1.getNumerator());
    	float logDen = std::log(ratio1.getDenominator());

    	Rational ratio3(floatToRatio<int>(logNum , 7) - floatToRatio<int>(logDen, 7));

	    ASSERT_EQ(ratio2.getNumerator(), ratio3.getNumerator());
        ASSERT_EQ(ratio2.getDenominator(),ratio3.getDenominator());
	}
}

TEST (RatioArithmetic, logarithm2) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(1,100);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.log2());

		float log = std::log(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));
    	Rational ratio3(floatToRatio<int>(log, 7));

	    ASSERT_EQ(ratio2.getNumerator(), ratio3.getNumerator());
        ASSERT_EQ(ratio2.getDenominator(),ratio3.getDenominator());
	}
}

TEST (RatioArithmetic, absolute) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.absolute());
		Rational ratio3(std::abs(ratio1.getNumerator()), ratio1.getDenominator());

	    ASSERT_EQ(ratio2.getNumerator(), ratio3.getNumerator());
        ASSERT_EQ(ratio2.getDenominator(),ratio3.getDenominator());
	}
}

TEST (RatioArithmetic, integerPart) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		int part1 =(ratio1.integerPart());
		int part2 = (int)ratio1.getNumerator()/ratio1.getDenominator();

	    ASSERT_EQ(part1, part2);
	}
}

TEST (RatioArithmetic, power) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-5,5);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		int factor = gen();
		Rational ratio1(gen(), gen());
		Rational ratio2 = ratio1.power(factor);

		int powered_num;
		int powered_den;

		if(factor < 0) {
			powered_num = std::pow(ratio1.getDenominator(), -factor);
			powered_den = std::pow(ratio1.getNumerator(), -factor);
		}
		else {
			powered_num = std::pow(ratio1.getNumerator(), factor);
			powered_den = std::pow(ratio1.getDenominator(), factor);
		}

		Rational ratio3(powered_num, powered_den);

	    ASSERT_EQ(ratio2.getNumerator(), ratio3.getNumerator());
        ASSERT_EQ(ratio2.getDenominator(), ratio3.getDenominator());
	}
}

TEST (RatioArithmetic, cosRatio) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-5,5);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen()); 
		Rational ratio2 = ratio1.cosRatio();

		// keep the integer part + the three first decimals of the exact solution
		float cos_exact_result = std::cos(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));
		cos_exact_result *= 1000;
		cos_exact_result = std::floor(cos_exact_result);

		// keep the integer part + the three first decimals of the found solution
		float cos_result = ((float)ratio2.getNumerator())/((float)ratio2.getDenominator());
		cos_result *= 1000;
		cos_result = std::floor(cos_result);

	    ASSERT_EQ(cos_result, cos_exact_result);
	}
}

TEST (RatioArithmetic, sinRatio) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-5,5);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen()); 
		Rational ratio2 = ratio1.sinRatio();

		// keep the integer part + the three first decimals of the exact solution
		float sin_exact_result = std::sin(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));
		sin_exact_result *= 1000;
		sin_exact_result = std::floor(sin_exact_result);

		// keep the integer part + the three first decimals of the found solution
		float sin_result = ((float)ratio2.getNumerator())/((float)ratio2.getDenominator());
		sin_result *= 1000;
		sin_result = std::floor(sin_result);

	    ASSERT_EQ(sin_result, sin_exact_result);
	}
}

TEST (RatioArithmetic, tanRatio) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.tanRatio());
		Rational ratio3(ratio1.sinRatio()/ratio1.cosRatio());

	    ASSERT_EQ(ratio2.getNumerator(), ratio3.getNumerator());
        ASSERT_EQ(ratio2.getDenominator(),ratio3.getDenominator());
	}
}


TEST (RatioArithmetic, expRatio) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-5,5);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		Rational ratio1(gen(), gen()); 
		Rational ratio2 = ratio1.expRatio();

		// keep the integer part + the three first decimals of the exact solution
		float exp_exact_result = std::exp(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));
		exp_exact_result *= 1000;
		exp_exact_result = std::floor(exp_exact_result);

		// keep the integer part + the three first decimals of the found solution
		float exp_result = ((float)ratio2.getNumerator())/((float)ratio2.getDenominator());
		exp_result *= 1000;
		exp_result = std::floor(exp_result);

	    ASSERT_EQ(exp_result, exp_exact_result);
	}
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  
}