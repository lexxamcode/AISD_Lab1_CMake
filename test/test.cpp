#include "../headers/monomial.h"
#include "../headers/polynomial.h"

#include <gtest/gtest.h>

TEST(Monomial, IntConstructor)
{
	monomial<int> testing_monomial(1, 1);

	EXPECT_TRUE(testing_monomial.getFactor() == 1 && testing_monomial.getPower() == 1 && testing_monomial.next() == nullptr);
}

TEST(Monomial, DoubleConstructor)
{
	monomial<double> testing_monomial(3.14, 1);

	EXPECT_TRUE(testing_monomial.getFactor() == 3.14 && testing_monomial.getPower() == 1 && testing_monomial.next() == nullptr);
}

TEST(Monomial, FloatConstructor)
{
	monomial<float> testing_monomial(3.14, 1);

	EXPECT_TRUE(testing_monomial.getFactor() == 3.14 && testing_monomial.getPower() == 1 && testing_monomial.next() == nullptr);
}

TEST(Monomial, ComplexFloatConstuctor)
{
	std::complex<float> test(3.14, 2);
	monomial<std::complex<float>> testing_monomial(test, 1);

	EXPECT_TRUE(testing_monomial.getFactor() == test, testing_monomial.getPower() == 1, testing_monomial.next() == nullptr);
}