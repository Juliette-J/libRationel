#include "Rational.hpp"

#include <random>
#include <chrono>
#include <cmath>
#include <numeric>
#include <functional>
#include <gtest/gtest.h>

/* Operators */

TEST (RatioArithmetic, plus) {

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
		Rational ratio3(ratio1 + ratio2);
		Rational ratio4(ratio1.getNumerator()*ratio2.getDenominator() + ratio1.getDenominator()*ratio2.getNumerator(), ratio1.getDenominator()*ratio2.getDenominator());

	    ASSERT_EQ(ratio3.getNumerator(), ratio4.getNumerator());
		ASSERT_EQ(ratio3.getDenominator(), ratio4.getDenominator());
	}
}

TEST (RatioArithmetic, minus) {

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
		Rational ratio3(ratio1 - ratio2);
		Rational ratio4(ratio1.getNumerator()*ratio2.getDenominator() - ratio1.getDenominator()*ratio2.getNumerator(), ratio1.getDenominator()*ratio2.getDenominator());

	    ASSERT_EQ(ratio3.getNumerator(), ratio4.getNumerator());
		ASSERT_EQ(ratio3.getDenominator(), ratio4.getDenominator());
	}
}


TEST (RatioArithmetic, product) {

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
		Rational ratio3(ratio1*ratio2);
		Rational ratio4(ratio1.getNumerator()*ratio2.getNumerator(), ratio1.getDenominator()*ratio2.getDenominator());

	    ASSERT_EQ(ratio3.getNumerator(), ratio4.getNumerator());
		ASSERT_EQ(ratio3.getDenominator(), ratio4.getDenominator());
	}
}

TEST (RatioArithmetic, division) {

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
		Rational ratio3(ratio1/ratio2);
		Rational ratio4(ratio1.getNumerator()*ratio2.getDenominator(), ratio1.getDenominator()*ratio2.getNumerator());

	    ASSERT_EQ(ratio3.getNumerator(), ratio4.getNumerator());
		ASSERT_EQ(ratio3.getDenominator(), ratio4.getDenominator());
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
		Rational ratio2(ratio1);

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
		Rational ratio1(gen(), gen());
		Rational ratio2(gen(), gen());

	    ASSERT_TRUE(ratio1 != ratio2);
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

/* ------- Methods outside Rational class ------- */

TEST (RatioArithmetic, power) {

	// Seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	// Generator
	std::mt19937 generator(seed);

	// Distribution
	std::uniform_int_distribution<int> uniformIntDistribution(-10,10);
	auto gen = std::bind(uniformIntDistribution, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// generate random data
		int factor = gen();
		Rational ratio1(gen(), gen());
		Rational ratio2(power(ratio1, factor));
		Rational powered((int) std::pow(ratio1.getNumerator(), factor), (int) std::pow(ratio1.getDenominator(), factor));

	    ASSERT_EQ(ratio2.getNumerator(), powered.getNumerator());
        ASSERT_EQ(ratio2.getDenominator(), powered.getDenominator());
	}
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  
}