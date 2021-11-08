#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <ctime>
#include <random>
#include <complex>
#include "monomial.h"

//Класс многочлен в виде односвязного списка полями "начало списка" и степень многочлена
//Определен конструктор по умолчанию, конструктор с параметрами, конструктор копирования и деструктор
//Метод add для добавления в начало списка, remove для удаления элемента заданной степени, геттеры по заданной степени
//set для установки коэффициента по заданной степени
//Перегружен оператор [], +, -, =, *
//Метод calculate() для подсчета выражения при заданном X

template <typename TYPE>
class polynomial
{
private:
	monomial<TYPE>* _head;
	size_t _N;
public:
	polynomial();
	polynomial(const size_t& power);
	polynomial(const polynomial<TYPE>& copied);
	~polynomial();
	void add(monomial<TYPE>* part);
	void add(const monomial<TYPE>& part);
	void remove(const size_t& power);
	void set(const TYPE& facor, const size_t& power);
	size_t size() const;
	monomial<TYPE>& get(const size_t& power);
	monomial<TYPE> get(const size_t& power) const;
	TYPE operator [](const size_t& power) const;
	TYPE& operator [](const size_t& power);
	polynomial& randomize();
	polynomial operator + (const polynomial<TYPE>& second) const;
	polynomial& operator + (const polynomial<TYPE>& second);
	polynomial const operator - (const polynomial<TYPE>& second) const;
	polynomial& operator - (const polynomial<TYPE>& second);
	polynomial& operator = (const polynomial<TYPE>& second);
	polynomial operator * (const TYPE& p_factor)const;
	polynomial& operator * (const TYPE& p_factor);
	friend polynomial& operator *(const TYPE& p_factor, const polynomial<TYPE>& pol);
	TYPE calculate(const TYPE& x) const;
};

template <typename TYPE>
inline polynomial<TYPE>::polynomial() : _head(NULL), _N(0) { }

template <typename TYPE>
inline polynomial<TYPE>::polynomial(const size_t& power)
{
	_N = power;
	_head = new monomial<TYPE>(1, 0);

	for (size_t i = 1; i <= power; i++)
	{
		monomial<TYPE>* temp = new monomial<TYPE>(static_cast<TYPE>(1), i);
		add(temp);
	}
}

template <typename TYPE>
inline polynomial<TYPE>::polynomial(const polynomial<TYPE>& copied)
{
	_N = copied._N;
	_head = nullptr;

	monomial<TYPE>* cur = copied._head;

	while (cur)
	{
		monomial<TYPE>* adding = new monomial<TYPE>(cur->_factor, cur->_power);
		adding->_next = _head;
		_head = adding;

		cur = cur->_next;
	}
}

template <typename TYPE>
inline polynomial<TYPE>::~polynomial()
{
	_N = 0;

	monomial<TYPE>* temp;

	while (_head)
	{
		temp = _head;
		_head = _head->_next;
		delete temp;
	}
}

template <typename TYPE>
inline void polynomial<TYPE>::add(monomial<TYPE>* part)
{
	part->_next = _head;
	_head = part;

	if (part->_power > _N)
		_N = part->_power;

}

template <typename TYPE>
inline void polynomial<TYPE>::add(const monomial<TYPE>& part)
{
	monomial<TYPE>* temp = new monomial<TYPE>(part._factor, part._power);

	temp->_next = _head;
	_head = temp;

	if (part._power > _N)
		_N = part._power;
}

template <typename TYPE>
inline void polynomial<TYPE>::remove(const size_t& power)
{
	if (this->_head)
	{
		if (&get(power) == _head)
		{
			monomial<TYPE>* temp = _head;
			_head = _head->_next;
			delete temp;
			if (power == _N)
				_N--;
		}
		else
		{
			monomial<TYPE>* temp = _head;
			monomial<TYPE>* next = temp->_next;
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
}

template <typename TYPE>
inline void polynomial<TYPE>::set(const TYPE& factor, const size_t& power)
{
	if (factor != static_cast<TYPE>(0))
	{
		try
		{
			(*this)[power] = factor;
		}
		catch (int err)
		{
			if (err == -1)
			{
				monomial<TYPE>* temp = new monomial<TYPE>(factor, power);
				add(temp);
			}
		}
		catch (const char* msg)
		{
			if (!strcmp(msg, "List is empty"))
			{
				monomial<TYPE>* temp = new monomial<TYPE>(factor, power);
				add(temp);
			}
		}
	}
	else
		remove(power);
}

template <typename TYPE>
inline monomial<TYPE>& polynomial<TYPE>::get(const size_t& power)
{
	if (!_head) throw "List is empty";

	monomial<TYPE>* temp = _head;
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
		throw - 1;
	}
	else
		throw - 1;
}

template <typename TYPE>
inline monomial<TYPE> polynomial<TYPE>::get(const size_t& power) const
{
	if (!_head) throw "List is empty";

	if (!(power > _N))
	{
		monomial<TYPE>* temp = _head;
		while (temp)
		{
			if (temp->_power == power)
			{
				return *temp;
				break;
			}
			temp = temp->_next;
		}
		return monomial(static_cast<TYPE>(0), power);
	}
	else
		return monomial(static_cast<TYPE>(0), power);
}

template <typename TYPE>
inline size_t polynomial<TYPE>::size() const
{
	return _N;
}

template <typename TYPE>
inline TYPE polynomial<TYPE>::operator [] (const size_t& power) const
{
	if (!_head) throw "List is empty";

	if (power > _N)
		return 0;
	else
	{
		monomial<TYPE>* temp = _head;
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

template <typename TYPE>
inline TYPE& polynomial<TYPE>::operator[](const size_t& power)
{
	if (!_head) throw "List is empty";

	if (power <= _N)
	{
		monomial<TYPE>* temp = _head;
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

template <typename TYPE>
inline polynomial<TYPE>& polynomial<TYPE>::randomize()
{
	srand((unsigned)time((0)));

	polynomial<TYPE>* generated = new polynomial<TYPE>;
	size_t N = static_cast<size_t>(1) + rand() % 10;
	for (int i = 0; i < N; i++)
	{
		TYPE factor = -100 + static_cast<TYPE>(rand()) / (static_cast<TYPE>(RAND_MAX / (100 - (-100))));
		unsigned degree = 1 + rand() % 10;
		int sign = 1 + rand() % 2;
		if (sign == 1)
			generated->set(factor, degree);
		else
			generated->set(-1 * factor, degree);
	}

	return *generated;

}
inline polynomial<std::complex<float>>& polynomial<std::complex<float>>::randomize()
{
	srand((unsigned)time((0)));

	polynomial<std::complex<float>>* generated = new polynomial<std::complex<float>>;
	size_t N = static_cast<size_t>(1) + rand() % 10;
	for (int i = 0; i < N; i++)
	{
		float r_factor = -100 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (100 - (-100))));
		float i_factor = -100 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (100 - (-100))));
		unsigned degree = 1 + rand() % 10;
		int sign = 1 + rand() % 2;
		if (sign == 1)
		{
			std::complex<float> factor(r_factor, i_factor);
			generated->set(factor, degree);
		}
		else
		{
			std::complex<float> factor(-1*(r_factor), -1*(i_factor));
			generated->set(factor, degree);
		}
	}

	return *generated;
}

inline polynomial<std::complex<double>>& polynomial<std::complex<double>>::randomize()
{
	srand((unsigned)time((0)));

	polynomial<std::complex<double>>* generated = new polynomial<std::complex<double>>;
	size_t N = static_cast<size_t>(1) + rand() % 10;
	for (int i = 0; i < N; i++)
	{
		double r_factor = -100 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (100 - (-100))));
		double i_factor = -100 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (100 - (-100))));
		unsigned degree = 1 + rand() % 10;
		int sign = 1 + rand() % 2;
		if (sign == 1)
		{
			std::complex<double> factor(r_factor, i_factor);
			generated->set(factor, degree);
		}
		else
		{
			std::complex<double> factor(-1 * (r_factor), -1 * (i_factor));
			generated->set(factor, degree);
		}
	}

	return *generated;
}

template <typename TYPE>
inline polynomial<TYPE> polynomial<TYPE>::operator+(const polynomial<TYPE>& second) const
{
	polynomial<TYPE> result;

	if (_N >= second._N)
	{
		for (size_t i = 0; i <= _N; i++)
		{
			TYPE ai, bi;
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = static_cast<TYPE>(0);
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = static_cast<TYPE>(0);
			}
			if ((ai + bi) != static_cast<TYPE>(0))
			{
				monomial<TYPE> temp(ai + bi, i);
				result.add(temp);
			}
		}

		return result;
	}
	else
	{
		for (size_t i = 0; i <= second._N; i++)
		{
			TYPE ai, bi;
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = static_cast<TYPE>(0);
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = static_cast<TYPE>(0);
			}
			if ((ai + bi) != 0)
			{
				monomial<TYPE> temp(ai + bi, i);
				result.add(temp);
			}
		}
		return result;
	}
}

template <typename TYPE>
inline polynomial<TYPE>& polynomial<TYPE>::operator + (const polynomial<TYPE>& second)
{
	polynomial<TYPE>* result = new polynomial<TYPE>;

	if (_N >= second._N)
	{
		for (size_t i = 0; i <= _N; i++)
		{
			TYPE ai = static_cast<TYPE>(0);
			TYPE bi = static_cast<TYPE>(0);
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				bi = static_cast<TYPE>(0);
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				bi = static_cast<TYPE>(0);
			}
			if ((ai + bi) != static_cast<TYPE>(0))
			{
				monomial<TYPE> temp(ai + bi, i);
				(*result).add(temp);
			}
		}

		return *result;
	}
	else
	{
		for (size_t i = 0; i <= second._N; i++)
		{
			TYPE ai = static_cast<TYPE>(0);
			TYPE bi = static_cast<TYPE>(0);
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				ai = static_cast<TYPE>(0);
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				bi = static_cast<TYPE>(0);
			}
			if ((ai + bi) != static_cast<TYPE>(0))
			{
				monomial<TYPE> temp(ai + bi, i);
				(*result).add(temp);
			}
		}
		return (*result);
	}
}

template <typename TYPE>
inline polynomial<TYPE> const polynomial<TYPE>::operator - (const polynomial<TYPE>& second) const
{
	polynomial<TYPE> result;

	if (_N >= second._N)
	{
		for (size_t i = 0; i <= _N; i++)
		{
			TYPE ai = static_cast<TYPE>(0);
			TYPE bi = static_cast<TYPE>(0);
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				ai = static_cast<TYPE>(0);
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				bi = static_cast<TYPE>(0);
			}
			if ((ai - bi) != static_cast<TYPE>(0))
			{
				monomial<TYPE> temp(ai - bi, i);
				result.add(temp);
			}
		}

		return result;
	}
	else
	{
		for (size_t i = 0; i <= second._N; i++)
		{
			TYPE ai = static_cast<TYPE>(0);
			TYPE bi = static_cast<TYPE>(0);
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				ai = static_cast<TYPE>(0);
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				bi = static_cast<TYPE>(0);
			}
			if ((ai - bi) != static_cast<TYPE>(0))
			{
				monomial<TYPE> temp(ai - bi, i);
				result.add(temp);
			}
		}
		return result;
	}
}

template <typename TYPE>
inline polynomial<TYPE>& polynomial<TYPE>::operator - (const polynomial<TYPE>& second)
{
	polynomial<TYPE>* result = new polynomial<TYPE>;

	if (_N >= second._N)
	{
		for (size_t i = 0; i <= _N; i++)
		{
			TYPE ai = static_cast<TYPE>(0);
			TYPE bi = static_cast<TYPE>(0);
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				ai = static_cast<TYPE>(0);
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				bi = static_cast<TYPE>(0);
			}
			if ((ai - bi) != static_cast<TYPE>(0))
			{
				monomial<TYPE> temp(ai - bi, i);
				(*result).add(temp);
			}
		}

		return *result;
	}
	else
	{
		for (size_t i = 0; i <= second._N; i++)
		{
			TYPE ai = static_cast<TYPE>(0);
			TYPE bi = static_cast<TYPE>(0);
			try {
				ai = (*this)[i];
			}
			catch (int err)
			{
				if (err == -1)
					ai = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				ai = static_cast<TYPE>(0);
			}
			try {
				bi = second[i];
			}
			catch (int err)
			{
				if (err == -1)
					bi = static_cast<TYPE>(0);
			}
			catch (const char*)
			{
				bi = static_cast<TYPE>(0);
			}
			if ((ai - bi) != static_cast<TYPE>(0))
			{
				monomial<TYPE> temp(ai - bi, i);
				(*result).add(temp);
			}
		}
		return *result;
	}
}

template <typename TYPE>
inline polynomial<TYPE>& polynomial<TYPE>::operator = (const polynomial<TYPE>& second)
{
	if (this == &second)
		return *this;

	while (_head)
	{
		monomial<TYPE>* temp = _head;
		_head = _head->_next;
		delete temp;
	}


	_N = second._N;

	monomial<TYPE>* cur = second._head;

	while (cur)
	{
		monomial<TYPE>* adding = new monomial<TYPE>(cur->_factor, cur->_power);
		adding->_next = _head;
		_head = adding;

		cur = cur->_next;
	}

	return *this;
}

template <typename TYPE>
inline polynomial<TYPE> polynomial<TYPE>::operator *(const TYPE& p_factor) const
{
	polynomial<TYPE> result(*this);

	monomial<TYPE>* temp = result._head;

	while (temp)
	{
		temp->_factor *= p_factor;
		temp = temp->_next;
	}

	return result;
}

template <typename TYPE>
inline polynomial<TYPE>& polynomial<TYPE>::operator*(const TYPE& p_factor)
{
	polynomial<TYPE>* result = new polynomial<TYPE>;

	monomial<TYPE>* temp = _head;

	while (temp)
	{

		result->set(temp->_factor * p_factor, temp->_power);
		//temp->_factor *= p_factor;
		temp = temp->_next;
	}

	return *result;
}

template <typename TYPE>
inline polynomial<TYPE>& operator*(const TYPE& p_factor, const polynomial<TYPE>& pol)
{
	polynomial<TYPE>* result = new polynomial<TYPE>(pol);

	monomial<TYPE>* temp = result->_head;

	while (temp)
	{
		temp->getFactor() *= p_factor;
		temp = temp->next();
	}

	return *result;
}

template <typename TYPE>
inline TYPE polynomial<TYPE>::calculate(const TYPE& x) const
{
	TYPE result = static_cast<TYPE>(0);
	monomial<TYPE>* temp = _head;

	while (temp)
	{
		result += temp->_factor * static_cast<TYPE>(pow(x, temp->_power));
		temp = temp->_next;
	}

	return result;
}