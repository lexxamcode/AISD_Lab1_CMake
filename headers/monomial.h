#pragma once

//Класс одночлена с полем коэффициент, степень и указатель на следующий одночлен
//Дружественный класс-список - многочлен
//конструктор по умолчанию, сеттеры и геттеры.

class monomial
{
private:
	double _factor;
	size_t _power;
	monomial* _next;
	friend class polynomial;
public:
	monomial(double factor, const size_t& power);
	void set(double factor, const size_t& power);
	size_t getPower() const;
	double& getFactor();
	double getFactor() const;
	monomial* next() const;
};

inline monomial::monomial(double factor, const size_t& power)
{
	if (power < 0) throw "Power can not be less than 0";

	_factor = factor;
	_power = power;
	_next = nullptr;
}

inline void monomial::set(double factor, const size_t& power)
{
	if (power < 0) throw "Power can not be less than 0";

	_factor = factor;
	_power = power;
}

inline size_t monomial::getPower() const
{
	return _power;
}

inline double& monomial::getFactor()
{
	return _factor;
}

inline double monomial::getFactor() const
{
	return _factor;
}

inline monomial* monomial::next() const
{
	return _next;
}

