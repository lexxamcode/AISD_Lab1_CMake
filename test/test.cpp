#include "../headers/monomial.h"
#include "../headers/polynomial.h"

#include <gtest/gtest.h>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Monomial, Constructor)
{
	monomial testing_monomial(1, 1);

	EXPECT_TRUE(testing_monomial.getFactor() == 1 && testing_monomial.getPower() == 1 && testing_monomial.next() == nullptr);
}
TEST(Monomial, Setter)
{
	double x = 3;
	size_t n = 4;
	monomial testing_monomial(1, 1);

	testing_monomial.set(x, n);

	EXPECT_TRUE(testing_monomial.getFactor() == x && testing_monomial.getPower() == n);
}

TEST(Polynomial, StandartConstructor)
{
	polynomial testing_polynomial;

	EXPECT_EQ(testing_polynomial.size(), 0);
}

//Тест перегрузки оператора доступа по индексу(степени элемента) к элементу
//В случае, если элемент по индексу найден, вернется его значение, если нет,
//Значит коэффициент при этой степени равен нулю, кидаем исключение -1;
TEST(Polynomial, IndexOperatorTest)
{
	polynomial testing_polynomial;
	monomial testing_monomial(1, 4);
	double x;
	
	testing_polynomial.add(testing_monomial);
	try
	{
		x = testing_polynomial[2];
	}
	catch (int err)
	{
		if (err == -1)
			x = 0;
	}

	EXPECT_EQ(testing_polynomial[4], 1);
	EXPECT_EQ(x, 0);
}

TEST(Polynomial, ConstructorWithParameters)
{
	polynomial testing_polynomial(10);

	for (size_t i = 0; i <= 10; i++)
	{
		EXPECT_EQ(testing_polynomial[i], 1);
	}
}


//Тесты на установку коэффициента при заданной степени: 
//В случае попытки установки нулевого коэффициента при какой-либо степени
//установки не происходит, т.к многочлен хранит только ненулевые коэффициенты.
//При попытке получения нулевого коэффициента происходит следующее:
//В случае, если список был пуст, вызывается исключение "List is empty".
//В случае, когда элемент данной степени удален из-за установки нулевого 
//коэффициента, вызвается исключение -1 - объект не найден
TEST(Polynomial, SetMethod)
{
	polynomial testing_polynomial;

	testing_polynomial.set(3.14, 2);

	EXPECT_EQ(testing_polynomial[2], 3.14);
}

TEST(Polynomial, SetZeroFactorMethod)
{
	polynomial testing_polynomial;
	bool correct = 1;

	testing_polynomial.set(0, 1);	
	try
	{
		testing_polynomial.get(1);
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

	EXPECT_EQ(correct, 0);
}


//Сложение:
//tp1 = 1 + 1x + 1x^2 + ... + 1x^10
//tp2 = 1 + 1x + 1x^2 + ... + 1x^5
//tp1 = tp1 + tp2 = 2 + 2x + 2x^2 + ... + 2x^5 + 1x^6 + ... + 1x^10
//tp3 = tp1 + tp2 = 3 + 3x + 3x^2 + ... + 3x^5 + 1x^6 + ... + 1x^10

TEST(Polynomial, OperatorPlus)
{
	polynomial testing_polynomial1(10);
	polynomial testing_polynomial2(5);
	polynomial testing_polynomial3;

	testing_polynomial1 = testing_polynomial1 + testing_polynomial2;
	testing_polynomial3 = testing_polynomial1 + testing_polynomial2;


	EXPECT_EQ(testing_polynomial1[0], 2);
	EXPECT_EQ(testing_polynomial2[2], 1);
	EXPECT_EQ(testing_polynomial3[1], 3);
	EXPECT_EQ(testing_polynomial3[10], 1);
	EXPECT_EQ(testing_polynomial1[1], 2);
}

//Вычитание:
//tp1 = 1 + 1x + 1x^2 + ... + 1x^10
//tp2 = 1 + 1x + 1x^2 + ... + 1x^5
//tp1 = tp1 - tp2 = 1x^6 + ... + 1x^10
//tp3 = tp1 + tp2 = 1 + 1x + 1x^2 + ... + 1x^5 + 1x^6 + ... + 1x^10

TEST(Polynomial, OperatorMinus)
{
	polynomial testing_polynomial1(10);
	polynomial testing_polynomial2(5);
	polynomial testing_polynomial3; double x;

	testing_polynomial1 = testing_polynomial1 - testing_polynomial2;
	testing_polynomial3 = testing_polynomial1 + testing_polynomial2;


	try
	{
		x = testing_polynomial1[0];
	}
	catch (int err)
	{
		if (err == -1)
			x = 0;
	}
	EXPECT_EQ(x, 0);
	EXPECT_EQ(testing_polynomial2[2], 1);
	EXPECT_EQ(testing_polynomial3[1], 1);
	EXPECT_EQ(testing_polynomial3[10], 1);
}

//Умножение:
// tp = 1 + 1x + 1x^2 + ... + 1x^10
// mp = tp * 4 = 4 + 4x + 4x^2 + ... + 4x^10
// tp = tp * 5 = 5 + 5x + 5x^2 + ... + 5x^10
TEST(Polynomial, OperatorMultiply)
{
	polynomial testing_polynomial(10);

	polynomial multiplying_polynomial;
	multiplying_polynomial = testing_polynomial * 4;
	testing_polynomial = testing_polynomial * 5;

	EXPECT_EQ(multiplying_polynomial[5], 4);
	EXPECT_EQ(testing_polynomial[5], 5);
}

//Подсчет значения многочлена при заданном x:
// tp = 1 + x^3 + x^4
// tp(2) = 1 + 8 + 16 = 25
TEST(Polynomial, CalculateFunction)
{
	polynomial testing_polynomial;
	testing_polynomial.set(1, 0);
	testing_polynomial.set(1, 3);
	testing_polynomial.set(1, 4);

	double result = testing_polynomial.calculate(2);

	EXPECT_EQ(result, 25);
}