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

TEST(Polynomial, IntConstructorWithParam)
{
	polynomial<int> testing_polynomial(10);

	ASSERT_EQ(testing_polynomial.find_max_power(), 10);
	ASSERT_EQ(testing_polynomial[2], 1);
}

TEST(Polynomial, FloatConstructorWithParam)
{
	polynomial<float> testing_polynomial(10);

	EXPECT_TRUE(testing_polynomial.find_max_power() == 10 && testing_polynomial[2] == 1.0f);
}

TEST(Polynomial, DoubleConstructorWithParam)
{
	polynomial<double> testing_polynomial(10);

	EXPECT_TRUE(testing_polynomial.find_max_power() == 10 && testing_polynomial[2] == 1.0);
}

TEST(Polynomial, ComplexFloatConstructorWithParam)
{
	polynomial<std::complex<float>> testing_polynomial(10);

	EXPECT_TRUE(testing_polynomial.find_max_power() == 10);
	EXPECT_TRUE(testing_polynomial[2].real() == 1.0f);
	EXPECT_TRUE(testing_polynomial[2].imag() == 0.0f);
}

TEST(Polynomial, ComplexDoubleConstructorWithParam)
{
	polynomial<std::complex<float>> testing_polynomial(10);

	EXPECT_TRUE(testing_polynomial.find_max_power() == 10);
	EXPECT_TRUE(testing_polynomial[2].real() == 1.0);
	EXPECT_TRUE(testing_polynomial[2].imag() == 0.0);
}


TEST(Polynomial, DeleteFunction)
{
	polynomial<int> test_poly;
	monomial<int> deletable(3, 4); 
	monomial<int> non_deletable(2, 2);
	bool incorrect = 0;
	test_poly.add(deletable);
	test_poly.add(non_deletable);
	test_poly.remove(4); 

	try
	{
		test_poly.get(4);
	}
	catch (int)
	{
		incorrect = 1;
	}
	size_t max_power = test_poly.find_max_power();

	ASSERT_EQ(incorrect, 1);
	ASSERT_EQ(max_power, 2);
}

TEST(Polynomial, OperatorTest)
{
	polynomial<int> test_poly;
	monomial<int> deletable(3, 4);
	monomial<int> non_deletable(2, 2);
	test_poly.add(deletable);
	test_poly.add(non_deletable);
	double x = 2;

	test_poly.remove(4);
	test_poly[2] = 3;
	try
	{
		x = test_poly[4];
	}
	catch (int)
	{
		x = 0;
	}

	ASSERT_EQ(test_poly[2], 3);
	ASSERT_EQ(x, 0);
}

TEST(Polynomial, IntSetMethod)
{
	polynomial<int> test(2);
	bool correct = 1;
	test.set(3, 2);
	test.set(0, 1);

	try
	{
		test.get(1);
	}
	catch (int err)
	{
		if (err == -1)
			correct = 0;
	}
	catch (const char* msg)
	{
		if (!strcmp(msg, "List is empty"))
			correct = 0;
	}
	EXPECT_TRUE(test[2] == 3 && correct == 0);
}

TEST(Polynomial, FloatSetMethod)
{
	polynomial<float> test(2);
	bool correct = 1;
	test.set(3.14f, 2);
	test.set(0, 1);

	try
	{
		test.get(1);
	}
	catch (int err)
	{
		if (err == -1)
			correct = 0;
	}
	catch (const char* msg)
	{
		if (!strcmp(msg, "List is empty"))
			correct = 0;
	}
	EXPECT_TRUE(test[2] == 3.14f && correct == 0);
}

TEST(Polynomial, DoubleSetMethod)
{
	polynomial<double> test(2);
	bool correct = 1;
	test.set(3.14, 2);
	test.set(0, 1);

	try
	{
		test.get(1);
	}
	catch (int err)
	{
		if (err == -1)
			correct = 0;
	}
	catch (const char* msg)
	{
		if (!strcmp(msg, "List is empty"))
			correct = 0;
	}
	EXPECT_TRUE(test[2] == 3.14 && correct == 0);
}

TEST(Polynomial, ComplexFloatSetMethod)
{
	polynomial<std::complex<float>> test(2);
	bool correct = 1;
	std::complex<float> x(3.14f, 2);
	test.set(x, 2);
	test.set(0, 1);

	try
	{
		test.get(1);
	}
	catch (int err)
	{
		if (err == -1)
			correct = 0;
	}
	catch (const char* msg)
	{
		if (!strcmp(msg, "List is empty"))
			correct = 0;
	}
	EXPECT_TRUE(test[2].real() == 3.14f && test[2].imag() == 2 && correct == 0);
}

TEST(Polynomial, ComplexDoubleSetMethod)
{
	polynomial<std::complex<double>> test(2);
	bool correct = 1;
	std::complex<double> x(3.14, 2);
	test.set(x, 2);
	test.set(0, 1);

	try
	{
		test.get(1);
	}
	catch (int err)
	{
		if (err == -1)
			correct = 0;
	}
	catch (const char* msg)
	{
		if (!strcmp(msg, "List is empty"))
			correct = 0;
	}
	EXPECT_TRUE(test[2].real() == 3.14 && test[2].imag() == 2 && correct == 0);
}
TEST(Polynomial, IntPlusOperator)
{
	polynomial<int> x(10);
	polynomial<int> y(5);
	y.set(0, 2);
	polynomial<int> z = x + y;

	EXPECT_TRUE(z[5] == 2 && z[2] == 1 && z[10] == 1);
}

TEST(Polynomial, FloatPlusOperator)
{
	polynomial<float> x(10);
	polynomial<float> y(5);
	y.set(0.0f, 2);
	polynomial<float> z = x + y;

	EXPECT_TRUE(z[5] == 2 && z[2] == 1 && z[10] == 1);
}

TEST(Polynomial, DoublePlusOperator)
{
	polynomial<float> x(10);
	polynomial<float> y(5);
	y.set(0.0f, 2);
	polynomial<float> z = x + y;

	EXPECT_TRUE(z[5] == 2 && z[2] == 1 && z[10] == 1);
}

TEST(Polynomial, ComplexFloatPlusOperator)
{
	polynomial<std::complex<float>> x(10);
	polynomial<std::complex<float>> y(5);
	std::complex<float> ytest(0.0f, 1);
	y.set(ytest, 2);
	y.set(0, 3);
	polynomial<std::complex<float>> z = x + y;

	EXPECT_TRUE(z[5].real() == 2);
	EXPECT_TRUE(z[5].imag() == 0.0f);
	EXPECT_TRUE(z[2].real() == 1.0f);
	EXPECT_TRUE(z[2].imag() == 1);
	EXPECT_TRUE(z[3].real() == 1);
	EXPECT_TRUE(z[3].imag() == 0);
}

TEST(Polynomial, ComplexDoublePlusOperator)
{
	polynomial<std::complex<double>> x(10);
	polynomial<std::complex<double>> y(5);
	std::complex<double> ytest(0, 1);
	y.set(ytest, 2);
	y.set(0, 3);

	polynomial<std::complex<double>> z = x + y;

	EXPECT_TRUE(z[5].real() == 2);
	EXPECT_TRUE(z[5].imag() == 0);
	EXPECT_TRUE(z[2].real() == 1);
	EXPECT_TRUE(z[2].imag() == 1);
	EXPECT_TRUE(z[3].real() == 1);
	EXPECT_TRUE(z[3].imag() == 0);
}
TEST(Polynomial, IntMinusOperator)
{
	polynomial<int> x(10);
	polynomial<int> y(5);
	y.set(0, 2);
	bool z5_null = 1;

	polynomial<int> z = x - y;
	try
	{
		int temp = z[5];
		x = temp;
	}
	catch (int err)
	{
		if (err == -1)
			z5_null = 0;
	}

	EXPECT_TRUE(z[2] == 1);
	EXPECT_TRUE(z5_null == 0);
	EXPECT_TRUE(z[10] == 1);
}

TEST(Polynomial, FloatMinusOperator)
{
	polynomial<float> x(10);
	polynomial<float> y(5);
	y.set(0.0f, 2);
	bool z5_null = 1;

	polynomial<float> z = x - y;
	try
	{
		float temp = z[5];
		x = temp;
	}
	catch (int err)
	{
		if (err == -1)
			z5_null = 0;
	}

	EXPECT_TRUE(z[2] == 1);
	EXPECT_TRUE(z5_null == 0);
	EXPECT_TRUE(z[10] == 1);
}

TEST(Polynomial, DoubleMinusOperator)
{
	polynomial<double> x(10);
	polynomial<double> y(5);
	y.set(0.0, 2);
	bool z5_null = 1;

	polynomial<double> z = x - y;
	try
	{
		double temp = z[5];
		x = temp;
	}
	catch (int err)
	{
		if (err == -1)
			z5_null = 0;
	}

	EXPECT_TRUE(z[2] == 1);
	EXPECT_TRUE(z5_null == 0);
	EXPECT_TRUE(z[10] == 1);
}

TEST(Polynomial, ComplexFloatMinusOperator)
{
	polynomial<std::complex<float>> x(10);
	polynomial<std::complex<float>> y(5);
	std::complex<float> null(0.0f, 0.0f);
	y.set(null, 2);
	bool z5_null = 1;
	bool z2_null = 1;

	polynomial<std::complex<float>> z = x - y;
	try
	{
		std::complex<float> temp = z[5];
	}
	catch (int err)
	{
		if (err == -1)
			z5_null = 0;
	}

	ASSERT_EQ(z[2].real(), 1.0f);
	ASSERT_EQ(z[2].imag(), 0.0f);
	EXPECT_TRUE(z5_null == 0);
	EXPECT_TRUE(z[10].real() == 1.0f && z[10].imag() == 0.0f);
}

TEST(Polynomial, ComplexDoubleMinusOperator)
{
	polynomial<std::complex<double>> x(10);
	polynomial<std::complex<double>> y(5);
	std::complex<double> null(0, 0);
	y.set(null, 2);
	bool z5_null = 1;
	bool z2_null = 1;

	polynomial<std::complex<double>> z = x - y;
	try
	{
		std::complex<double> temp = z[5];
	}
	catch (int err)
	{
		if (err == -1)
			z5_null = 0;
	}

	ASSERT_EQ(z[2].real(), 1);
	ASSERT_EQ(z[2].imag(), 0);
	EXPECT_TRUE(z5_null == 0);
	EXPECT_TRUE(z[10].real() == 1 && z[10].imag() == 0);
}

TEST(Polynomial, IntMultplyOperator)
{
	polynomial<int> test(10);
	test = test * 2;

	ASSERT_EQ(test[2], 2);
}

TEST(Polynomial, FloatMultplyOperator)
{
	polynomial<float> test(10);
	test = test * 2;

	ASSERT_EQ(test[2], 2.0f);
}

TEST(Polynomial, DoubleMultplyOperator)
{
	polynomial<double> test(10);
	test = 2.00 * test;

	ASSERT_EQ(test[2], 2);
}

TEST(Polynomial, ComplexFloatMultplyOperator)
{
	polynomial<std::complex<float>> test(10);
	std::complex<float> factor(3, 2);
	test.set(factor, 2);

	test = test * factor;

	ASSERT_EQ(test[2].real(), 5.0f);
	ASSERT_EQ(test[2].imag(), 12.0f);
}

TEST(Polynomial, ComplexDoubleMultplyOperator)
{
	polynomial<std::complex<double>> test(10);
	std::complex<double> factor(3, 2);
	test.set(factor, 2);

	test = test * factor;

	ASSERT_EQ(test[2].real(), 5);
	ASSERT_EQ(test[2].imag(), 12);
}
TEST(Polynomial, IntCalculateFunction)
{
	polynomial<int> test(3);
	test.set(0, 0);

	int result = test.calculate(3);

	ASSERT_EQ(result, 39);
}

TEST(Polynomial, FloatCalculateFunction)
{
	polynomial<float> test(3);
	test.set(0.0f, 0);

	float result = test.calculate(3.14f);

	EXPECT_TRUE(result - 43.9587 < 0.001f);
}

TEST(Polynomial, DoubleCalculateFunction)
{
	polynomial<double> test(3);
	test.set(0, 0);

	double result = test.calculate(3.14);

	EXPECT_TRUE(result - 43.958744 < 0.0001);
}

TEST(Polynomial, ComplexFloatCalculateFunction)
{
	polynomial<std::complex<float>> test(3);
	test.set(static_cast<std::complex<float>>(0), 0);
	std::complex<float> x(3, 2);
	std::complex<float> expectable(-1, 60);

	std::complex<float> result = test.calculate(x);

	ASSERT_EQ(result, expectable);
}

TEST(Polynomial, ComplexDoubleCalculateFunction)
{
	polynomial<std::complex<double>> test(3);
	test.set(static_cast<std::complex<double>>(0), 0);
	std::complex<double> x(3, 2);
	std::complex<double> expectable(-1, 60);

	std::complex<double> result = test.calculate(x);

	ASSERT_EQ(result, expectable);
}