#include <iostream>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <ctime>
#include <iterator>
#include <random>
#include <complex>
#include <forward_list>
#include "monomial.h"

template <typename TYPE>
class polynomial
{
private:
	std::forward_list<monomial<TYPE>> _monomials;
	size_t _size;
public:

	auto begin() { return _monomials.begin(); }
	const auto begin() const { return _monomials.begin(); }
	auto end() { return _monomials.end(); }
	const auto end() const { return _monomials.end(); }
	polynomial& randomize();
	polynomial()
	{
		_monomials = { monomial<TYPE>(1,0) };
		_size = 0;
	}

	polynomial(const size_t& size)
	{
		_size = size;
		for (size_t i = 0; i <= size; i++)
			_monomials.push_front(monomial<TYPE>(1, i));
	}

	monomial<TYPE> get(const size_t& power)
	{
		for (auto it = begin(); it != end(); it++)
		{
			if ((*it).getPower() == power)
				return *it;
		}

		throw - 1;
	}

	void add(const monomial<TYPE>& element)
	{
		_monomials.push_front(element);

		if (element.getPower() >= _size)
			_size = element.getPower();
	}

	size_t find_max_power() const
	{
		size_t max = 0;
		for (auto it = begin(); it != end(); it++)
		{
			if ((*it).getPower() > max)
				max = (*it).getPower();
		}

		return max;
	}

	void remove(const size_t& power)
	{
		if (!_monomials.empty())
		{
			auto bt = _monomials.before_begin();
			for (auto it = begin(); it != end(); it++)
			{
				if ((*it).getPower() == power)
				{
					_monomials.erase_after(bt);
					if (power == _size)
					{
						_size = find_max_power();
					}
					break;
				}
				bt++;
			}
		}
	}

	TYPE operator [](const size_t& power) const
	{
		if (_monomials.empty()) throw "List is empty";

		if (power <= _size)
		{
			for (auto it = begin(); it != end(); it++)
			{
				if ((*it).getPower() == power)
					return (*it).getFactor();
			}
		}

		return 0;
	}

	TYPE& operator[](const size_t& power)
	{
		if (_monomials.empty()) throw "List is empty";

		if (power <= _size)
		{
			for (auto it = begin(); it != end(); it++)
			{
				if ((*it).getPower() == power)
					return (*it).getFactor();
			}
		}

		throw -1;
	}

	void set(const TYPE& factor, const size_t power)
	{
		if (factor == static_cast<TYPE>(0))
			remove(power);
		else
		{
			try
			{
				(*this)[power] = factor;
			}
			catch (int err)
			{
				if (err == -1)
				{
					monomial<TYPE> temp(factor, power);
					add(temp);
				}
			}
			catch (const char* msg)
			{
				if (!strcmp(msg, "List is empty"))
				{
					monomial<TYPE> temp(factor, power);
					add(temp);
				}
			}
		}
	}
	
	polynomial<TYPE> operator+(const polynomial<TYPE>& second) const
	{
		polynomial<TYPE> result;

		if (_size >= second._size)
		{
			for (size_t i = 0; i <= _size; i++)
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
			for (size_t i = 0; i <= second._size; i++)
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
	}

	polynomial<TYPE>& operator + (const polynomial<TYPE>& second)
	{
		polynomial<TYPE>* result = new polynomial<TYPE>;

		if (_size >= second._size)
		{
			for (size_t i = 0; i <= _size; i++)
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
			for (size_t i = 0; i <= second._size; i++)
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

	polynomial<TYPE> const operator - (const polynomial<TYPE>& second) const
	{
		polynomial<TYPE> result;

		if (_size >= second._size)
		{
			for (size_t i = 0; i <= _size; i++)
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
			for (size_t i = 0; i <= second._size; i++)
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
	inline polynomial<TYPE>& operator - (const polynomial<TYPE>& second)
	{
		polynomial<TYPE>* result = new polynomial<TYPE>;

		if (_size >= second._size)
		{
			for (size_t i = 0; i <= _size; i++)
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
			for (size_t i = 0; i <= second._size; i++)
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

	polynomial<TYPE> operator *(const TYPE& p_factor) const
	{
		polynomial<TYPE> result(*this);

		for (const monomial<TYPE> i : *this)
			result.set(i.getFactor() * p_factor, i.getPower());

		return result;
	}

	polynomial<TYPE>& operator*(const TYPE& p_factor)
	{
		polynomial<TYPE>* result = new polynomial<TYPE>(*this);

		for (const monomial<TYPE>& i : *this)
			result->set(i.getFactor() * p_factor, i.getPower());

		return *result;
	}

	TYPE polynomial<TYPE>::calculate(const TYPE& x) const
	{
		TYPE result = static_cast<TYPE>(0);

		for (const monomial<TYPE>& i : *this)
			result += i.getFactor() * static_cast<TYPE>(pow(x, i.getPower()));

		return result;
	}

};

template <typename TYPE>
inline polynomial<TYPE>& operator*(const TYPE& p_factor, const polynomial<TYPE>& pol)
{
	polynomial<TYPE>* result = new polynomial<TYPE>(pol);

	for (const monomial<TYPE>& i : pol)
		result->set(i.getFactor() * p_factor, i.getPower());

	return *result;
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
			std::complex<float> factor(-1 * (r_factor), -1 * (i_factor));
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