#include "../headers/monomial.h"
#include "../headers/polynomial.h"

#include <gtest/gtest.h>

TEST(Monomial, IntConstructor)
{
	monomial<int> testing_monomial(1, 1);

	EXPECT_TRUE(testing_monomial.getFactor() == 1);
	EXPECT_TRUE(testing_monomial.getPower() == 1);
	EXPECT_TRUE(testing_monomial.next() == nullptr);
}

TEST(Monomial, DoubleConstructor)
{
	monomial<double> testing_monomial(3.14, 1);

	EXPECT_TRUE(testing_monomial.getFactor() == 3.14 && testing_monomial.getPower() == 1 && testing_monomial.next() == nullptr);
}

TEST(Monomial, FloatConstructor)
{
	monomial<float> testing_monomial(3.14f, 1);

	EXPECT_TRUE(testing_monomial.getFactor() == 3.14f && testing_monomial.getPower() == 1 && testing_monomial.next() == nullptr);
}

TEST(Monomial, ComplexDoubleConstructor)
{
	std::complex<double> test(3.14, 2);
	monomial<std::complex<double>> testing_monomial(test, 1);

	EXPECT_TRUE(testing_monomial.getFactor().real() == 3.14 && testing_monomial.getFactor().imag() == 2 && testing_monomial.getPower() == 1 && testing_monomial.next() == nullptr);
}

TEST(Monomial, ComplexFloatConstuctor)
{
	std::complex<float> test(3.14f, 2);
	monomial<std::complex<float>> testing_monomial(test, 1);

	EXPECT_TRUE(testing_monomial.getFactor().real() == 3.14f && testing_monomial.getFactor().imag() == 2 && testing_monomial.getPower() == 1 && testing_monomial.next() == nullptr);
}

TEST(Polynomial, Constructor)
{
	polynomial<int> testing_polynomial;

	EXPECT_TRUE(testing_polynomial.size() == 0);
}

TEST(Polynomial, IntConstructorWithParam)
{
	polynomial<int> testing_polynomial(10);

	EXPECT_TRUE(testing_polynomial.size() == 10 && testing_polynomial[2] == 1);
}

TEST(Polynomial, FloatConstructorWithParam)
{
	polynomial<float> testing_polynomial(10);

	EXPECT_TRUE(testing_polynomial.size() == 10 && testing_polynomial[2] == 1.0f);
}

TEST(Polynomial, DoubleConstructorWithParam)
{
	polynomial<double> testing_polynomial(10);

	EXPECT_TRUE(testing_polynomial.size() == 10 && testing_polynomial[2] == 1.0);
}

TEST(Polynomial, ComplexFloatConstructorWithParam)
{
	polynomial<std::complex<float>> testing_polynomial(10);

	EXPECT_TRUE(testing_polynomial.size() == 10);
	EXPECT_TRUE(testing_polynomial[2].real() == 1.0f);
	EXPECT_TRUE(testing_polynomial[2].imag() == 0.0f);
}

TEST(Polynomial, ComplexDoubleConstructorWithParam)
{
	polynomial<std::complex<float>> testing_polynomial(10);

	EXPECT_TRUE(testing_polynomial.size() == 10);
	EXPECT_TRUE(testing_polynomial[2].real() == 1.0);
	EXPECT_TRUE(testing_polynomial[2].imag() == 0.0);
}
