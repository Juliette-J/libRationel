#include "Rational.hpp"

#include <random>
#include <chrono>
#include <functional>
#include <gtest/gtest.h>

/* Constructors */

/*
TEST (RatioConstructor, defaultConstructor) { 
	Rational ratio();
	ASSERT_EQ (ratio.getNumerator(), 1);
}
*/

/* Arithmetic */

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

	    ASSERT_EQ(ratio3.getNumerator(), ratio1.getNumerator()*ratio2.getDenominator() + ratio1.getDenominator()*ratio2.getNumerator());
        ASSERT_EQ(ratio3.getDenominator(), ratio1.getDenominator()*ratio2.getDenominator());
	}
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  
}