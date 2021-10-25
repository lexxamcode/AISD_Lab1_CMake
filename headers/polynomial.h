#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <ctime>
#include <random>
#include "monomial.h"

//Класс многочлен в виде односвязного списка полями "начало списка" и степень многочлена
//Определен конструктор по умолчанию, конструктор с параметрами, конструктор копирования и деструктор
//Метод add для добавления в начало списка, remove для удаления элемента заданной степени, геттеры по заданной степени
//set для установки коэффициента по заданной степени
//Перегружен оператор [], +, -, =, *
//Метод calculate() для подсчета выражения при заданном X

class polynomial
{
private:
	monomial* _head;
	size_t _N;
public:
	polynomial();
	polynomial(const size_t& power);
	polynomial(const polynomial& copied);
	~polynomial();
	void add(monomial* part);
	void add(const monomial& part);
	void remove(const size_t& power);
	void set(double facor, const size_t& power);
	size_t size() const;
	monomial& get(const size_t& power);
	monomial get(const size_t& power) const;
	double operator [](const size_t& power) const;
	double& operator [](const size_t& power);
	polynomial& randomize();
	polynomial operator + (const polynomial& second) const;
	polynomial& operator + (const polynomial& second);
	polynomial const operator - (const polynomial& second) const;
	polynomial& operator - (const polynomial& second);
	polynomial& operator = (const polynomial& second);
	polynomial operator * (const double& p_factor)const;
	polynomial& operator * (const double& p_factor);
	friend polynomial& operator *(const double& p_factor,const polynomial& pol);
	double calculate(const double& x);
};


inline polynomial::polynomial() : _head(NULL), _N(0) { }
inline polynomial::polynomial(const size_t& power)
{
	_N = power;
	_head = new monomial(1, 0);

	for (size_t i = 1; i <= power; i++)
	{
		monomial* temp = new monomial(1, i);
		add(temp);
	}
}
inline polynomial::polynomial(const polynomial& copied)
{
	_N = copied._N;
	_head = nullptr;

	monomial* cur = copied._head;

	while (cur)
	{
		monomial* adding = new monomial(cur->_factor, cur->_power);
		adding->_next = _head;
		_head = adding;

		cur = cur->_next;
	}
}
inline polynomial::~polynomial()
{
	_N = 0;

	monomial* temp;

	while (_head)
	{
		temp = _head;
		_head = _head->_next;
		delete temp;
	}
}

inline void polynomial::add(monomial* part)
{
	part->_next = _head;
	_head = part;

	if (part->_power > _N)
		_N = part->_power;

}
inline void polynomial::add(const monomial& part)
{
	monomial* temp = new monomial(part._factor, part._power);

	temp->_next = _head;
	_head = temp;

	if (part._power > _N)
		_N = part._power;
}

inline void polynomial::remove(const size_t& power)
{
	if (&get(power) == _head)
	{
		monomial* temp = _head;
		_head = _head->_next;
		delete temp;
		if (power == _N)
			_N--;
	}
	else
	{
		monomial* temp = _head;
		monomial* next = temp->_next;
		while (next)
		{
			if (next->_power == power)
			{
				temp->_next = next->_next;
				delete next;
				if (power == _N)
					_N--;
				break;
			}
			temp = temp->_next;
			next = next->_next;
		}
	}
}

inline void polynomial::set(double factor, const size_t& power)
{
	if (factor)
	{
		try
		{
			(*this)[power] = factor;
		}
		catch (int err)
		{
			if (err == -1)
			{
				monomial* temp = new monomial(factor, power);
				add(temp);
			}
		}
		catch (const char* msg)
		{
			if (!strcmp(msg, "List is empty"))
			{
				monomial* temp = new monomial(factor, power);
				add(temp);
			}
		}
	}
}

inline monomial& polynomial::get(const size_t& power)
{
	if (!_head) throw "List is empty";

	monomial* temp = _head;
	if (!(power > _N))
	{
		while (temp)
		{
			if (temp->_power == power)
			{
				return *temp;
				break;
			}
			temp = temp->_next;
		}
		throw -1;
	}
	else
		throw - 1;
}
inline monomial polynomial::get(const size_t& power) const
{
	if (!_head) throw "List is empty";

	if (!(power > _N))
	{
		monomial* temp = _head;
		while (temp)
		{
			if (temp->_power == power)
			{
				return *temp;
				break;
			}
			temp = temp->_next;
		}
		return monomial(0, power);
	}
	else
		return monomial(0, power);
}

inline size_t polynomial::size() const
{
	return _N;
}

inline double polynomial::operator [] (const size_t& power) const
{
	if (!_head) throw "List is empty";

	if (power > _N)
		return 0;
	else
	{
		monomial* temp = _head;
		while (temp)
		{
			if (temp->_power == power)
			{
				return temp->_factor;
				break;
			}
			temp = temp->_next;
		}
	}

	return 0;
}
inline double& polynomial::operator[](const size_t& power)
{
	if (!_head) throw "List is empty";

	if (power <= _N)
	{
		monomial* temp = _head;
		while (temp)
		{
			if (temp->_power == power)
			{
				return temp->_factor;
				break;
			}
			temp = temp->_next;
		}
	}

	throw - 1;
}

inline polynomial& polynomial::randomize()
{
	srand((unsigned)time((0)));

	polynomial* generated = new polynomial;
	size_t N = static_cast<size_t>(1) + rand() % 10;
	for (int i = 0; i < N; i++)
	{
		double factor = static_cast<double>(-100) + rand() % 100;
		unsigned degree = 1 + rand() % 10;
		int sign = 1 + rand() % 2;
		if (sign == 1)
			generated->set(factor, degree);
		else
			generated->set(-1 * factor, degree);
	}

	return *generated;

}

inline polynomial polynomial::operator+(const polynomial& second) const
{
	polynomial result;

	if (_N >= second._N)
	{
		for (size_t i = 0; i <= _N; i++)
		{
			double ai, bi;
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = 0;
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = 0;
			}
			if ((ai + bi) != 0)
			{
				monomial temp(ai + bi, i);
				result.add(temp);
			}
		}

		return result;
	}
	else
	{
		for (size_t i = 0; i <= second._N; i++)
		{
			double ai, bi;
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = 0;
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = 0;
			}
			if ((ai + bi) != 0)
			{
				monomial temp(ai + bi, i);
				result.add(temp);
			}
		}
		return result;
	}
}
inline polynomial& polynomial::operator + (const polynomial& second)
{
	polynomial* result = new polynomial;

	if (_N >= second._N)
	{
		for (size_t i = 0; i <= _N; i++)
		{
			double ai = 0;
			double bi = 0;
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = 0;
			}
			catch (const char*)
			{
				bi = 0;
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = 0;
			}
			catch (const char*)
			{
				bi = 0;
			}
			if ((ai + bi) != 0)
			{
				monomial temp(ai + bi, i);
				(*result).add(temp);
			}
		}

		return *result;
	}
	else
	{
		for (size_t i = 0; i <= second._N; i++)
		{
			double ai = 0;
			double bi = 0;
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = 0;
			}
			catch (const char*)
			{
				ai = 0;
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = 0;
			}
			catch (const char*)
			{
				bi = 0;
			}
			if ((ai + bi) != 0)
			{
				monomial temp(ai + bi, i);
				(*result).add(temp);
			}
		}
		return (*result);
	}
}
inline polynomial const polynomial::operator - (const polynomial& second) const
{
	polynomial result;

	if (_N >= second._N)
	{
		for (size_t i = 0; i <= _N; i++)
		{
			double ai = 0;
			double bi = 0;
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = 0;
			}
			catch (const char*)
			{
				ai = 0;
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = 0;
			}
			catch (const char*)
			{
				bi = 0;
			}
			if ((ai - bi) != 0)
			{
				monomial temp(ai - bi, i);
				result.add(temp);
			}
		}

		return result;
	}
	else
	{
		for (size_t i = 0; i <= second._N; i++)
		{
			double ai = 0;
			double bi = 0;
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = 0;
			}
			catch (const char*)
			{
				ai = 0;
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = 0;
			}
			catch (const char*)
			{
				bi = 0;
			}
			if ((ai - bi) != 0)
			{
				monomial temp(ai - bi, i);
				result.add(temp);
			}
		}
		return result;
	}
}
inline polynomial& polynomial::operator - (const polynomial& second)
{
	polynomial* result = new polynomial;

	if (_N >= second._N)
	{
		for (size_t i = 0; i <= _N; i++)
		{
			double ai = 0;
			double bi = 0;
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = 0;
			}
			catch (const char*)
			{
				ai = 0;
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = 0;
			}
			catch (const char*)
			{
				bi = 0;
			}
			if ((ai - bi) != 0)
			{
				monomial temp(ai - bi, i);
				(*result).add(temp);
			}
		}

		return *result;
	}
	else
	{
		for (size_t i = 0; i <= second._N; i++)
		{
			double ai = 0;
			double bi = 0;
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = 0;
			}
			catch (const char*)
			{
				ai = 0;
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = 0;
			}
			catch (const char*)
			{
				bi = 0;
			}
			if ((ai - bi) != 0)
			{
				monomial temp(ai - bi, i);
				(*result).add(temp);
			}
		}
		return *result;
	}
}
inline polynomial& polynomial::operator = (const polynomial& second)
{
	if (this == &second)
		return *this;

	while (_head)
	{
		monomial* temp = _head;
		_head = _head->_next;
		delete temp;
	}


	_N = second._N;

	monomial* cur = second._head;

	while (cur)
	{
		monomial* adding = new monomial(cur->_factor, cur->_power);
		adding->_next = _head;
		_head = adding;

		cur = cur->_next;
	}

	return *this;
}

inline polynomial polynomial::operator *(const double& p_factor) const
{
	polynomial result(*this);

	monomial* temp = result._head;

	while (temp)
	{
		temp->_factor *= p_factor;
		temp = temp->_next;
	}

	return result;
}

inline polynomial& polynomial::operator*(const double& p_factor)
{
	polynomial* result = new polynomial;

	monomial* temp = _head;

	while (temp)
	{

		result->set(temp->_factor * p_factor, temp->_power);
		//temp->_factor *= p_factor;
		temp = temp->_next;
	}

	return *result;
}

inline polynomial& operator*(const double& p_factor, const polynomial& pol)
{
	polynomial* result = new polynomial(pol);

	monomial* temp = result->_head;

	while (temp)
	{
		temp->getFactor() *= p_factor;
		temp = temp->next();
	}

	return *result;
}

inline double polynomial::calculate(const double& x)
{
	double result = 0;
	monomial* temp = _head;

	while (temp)
	{
		result += temp->_factor * pow(x, (double)temp->_power);
		temp = temp->_next;
	}

	return result;
}