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
	for(int run=0; run<50; ++run){
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

TEST (RatioConstructor, copyConstructor) {
	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// Generator
	std::mt19937 generator(seed);
	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1);

	    ASSERT_EQ(ratio2.getNumerator(), ratio1.getNumerator());
		ASSERT_EQ(ratio2.getDenominator(), ratio1.getDenominator());
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
	for(int run=0; run<50; ++run){
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen()), ratio2(gen(), gen());
		Rational ratio3(ratio1 + ratio2);
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen()), ratio2(gen(), gen());
		Rational ratio3(ratio1 - ratio2);
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(-ratio1);
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen()), ratio2(gen(), gen());
		Rational ratio3(ratio1*ratio2);
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
	std::uniform_real_distribution<float> uniformRealDistribution(-10,10);
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto genReal = std::bind(uniformRealDistribution, generator);
	auto genInt = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<50; ++run){
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
	for(int run=0; run<50; ++run){
		// generate random data
		float real = genReal();
		Rational ratio1(genInt(), genInt());
		Rational ratio2(extProductReal(real,ratio1));

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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen()), ratio2(gen(), gen());
		Rational ratio3(ratio1/ratio2);
		Rational ratio4(ratio1*(ratio2.invRatio()));

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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1);

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
	for(int run=0; run<50; ++run){
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
	for(int run=0; run<50; ++run){
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
	for(int run=0; run<50; ++run){
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(60,1);

		ASSERT_TRUE(ratio1 <= ratio2);
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
	for(int run=0; run<50; ++run){
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
	for(int run=0; run<50; ++run){
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.squareRoot());
		float squareRootNum = std::sqrt(ratio1.getNumerator());
    	float squareRootDen = std::sqrt(ratio1.getDenominator());

		ASSERT_TRUE(std::abs(ratio2.getNumerator()/ratio2.getDenominator()-squareRootNum/squareRootDen) < 0.01);
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.squareRoot2());
		float squareRoot = std::sqrt(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));

	    ASSERT_TRUE(std::abs(ratio2.getNumerator()/ratio2.getDenominator()-squareRoot) < 0.01);
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.log());
		float logNum = std::log(ratio1.getNumerator());
    	float logDen = std::log(ratio1.getDenominator());

		ASSERT_TRUE(std::abs(ratio2.getNumerator()/ratio2.getDenominator()-logNum/logDen) < 0.01);
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.log2());
		float log = std::log(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));

	    ASSERT_TRUE(std::abs(ratio2.getNumerator()/ratio2.getDenominator()-log) < 0.01);

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
	for(int run=0; run<50; ++run){
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen());
		int part1 =(ratio1.integerPart());
		int part2;
		if(ratio1 == Rational(1,0)) {
			part2 = 0;
		}
		else {
			part2 = (int)(ratio1.getNumerator()/ratio1.getDenominator());
		}

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
	for(int run=0; run<50; ++run){
		// generate random data
		int factor = gen();
		Rational ratio1(gen(), gen());
		Rational ratio2 = ratio1.power(factor);
		int powNum;
		int powDen;
		if(factor < 0) {
			powNum = std::pow(ratio1.getDenominator(), -factor);
			powDen = std::pow(ratio1.getNumerator(), -factor);
		}
		else {
			powNum = std::pow(ratio1.getNumerator(), factor);
			powDen = std::pow(ratio1.getDenominator(), factor);
		}
		Rational ratio3(powNum, powDen);

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
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen()); 
		Rational ratio2 = ratio1.cosRatio();

		// keep the integer part + the three first decimals of the exact solution
		float exactResult = std::cos(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));
		exactResult *= 1000;
		exactResult = std::floor(exactResult);

		// keep the integer part + the three first decimals of the found solution
		float result = ((float)ratio2.getNumerator())/((float)ratio2.getDenominator());
		result *= 1000;
		result = std::floor(result);

	    ASSERT_EQ(result, exactResult);
	}
}

TEST (RatioArithmetic, sinRatio) {
	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// Generator
	std::mt19937 generator(seed);
	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen()); 
		Rational ratio2 = ratio1.sinRatio();

		// keep the integer part + the three first decimals of the exact solution
		float exactResult = std::sin(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));
		exactResult *= 1000;
		exactResult = std::floor(exactResult);

		// keep the integer part + the three first decimals of the found solution
		float result = ((float)ratio2.getNumerator())/((float)ratio2.getDenominator());
		result *= 1000;
		result = std::floor(result);

	    ASSERT_EQ(result, exactResult);
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
	for(int run=0; run<50; ++run){
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
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen()); 
		Rational ratio2 = ratio1.expRatio();

		// keep the integer part + the three first decimals of the exact solution
		float exactResult = std::exp(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));
		exactResult *= 1000;
		exactResult = std::floor(exactResult);

		// keep the integer part + the three first decimals of the found solution
		float result = ((float)ratio2.getNumerator())/((float)ratio2.getDenominator());
		result *= 1000;
		result = std::floor(result);

	    ASSERT_EQ(result,exactResult);
	}
}

TEST (RatioArithmetic, cosRatio2) {
	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// Generator
	std::mt19937 generator(seed);
	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen()); 
		Rational ratio2 = ratio1.cosRatio2();
		float cos = std::cos(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));

	    ASSERT_EQ(ratio2.getNumerator(), floatToRatio<int>(cos).getNumerator());
		ASSERT_EQ(ratio2.getDenominator(), floatToRatio<int>(cos).getDenominator());
	}
}

TEST (RatioArithmetic, sinRatio2) {
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
		Rational ratio2 = ratio1.sinRatio2();
		float sin = std::sin(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));

	    ASSERT_EQ(ratio2.getNumerator(), floatToRatio<int>(sin).getNumerator());
		ASSERT_EQ(ratio2.getDenominator(), floatToRatio<int>(sin).getDenominator());
	}
}

TEST (RatioArithmetic, tanRatio2) {
	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// Generator
	std::mt19937 generator(seed);
	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-50,50);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen());
		Rational ratio2(ratio1.tanRatio());
		Rational ratio3(ratio1.sinRatio()/ratio1.cosRatio());

	    ASSERT_EQ(ratio2.getNumerator(), ratio3.getNumerator());
        ASSERT_EQ(ratio2.getDenominator(),ratio3.getDenominator());
	}
}


TEST (RatioArithmetic, expRatio2) {
	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// Generator
	std::mt19937 generator(seed);
	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-5,5);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<50; ++run){
		// generate random data
		Rational ratio1(gen(), gen()); 
		Rational ratio2 = ratio1.expRatio();
		float exp = std::exp(((float)ratio1.getNumerator())/((float)ratio1.getDenominator()));

	    ASSERT_EQ(ratio2.getNumerator(), floatToRatio<int>(exp).getNumerator());
		ASSERT_EQ(ratio2.getDenominator(), floatToRatio<int>(exp).getDenominator());
	}
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  
}