#pragma once
//Êëàññ îäíî÷ëåíà ñ ïîëåì êîýôôèöèåíò, ñòåïåíü è óêàçàòåëü íà ñëåäóþùèé îäíî÷ëåí
//Äðóæåñòâåííûé êëàññ-ñïèñîê - ìíîãî÷ëåí
//êîíñòðóêòîð ïî óìîë÷àíèþ, ñåòòåðû è ãåòòåðû.

template <typename TYPE>
class monomial
{
private:
	TYPE _factor;
	size_t _power;
	monomial* _next;
	template <typename N_TYPE>
	friend class polynomial;
public:
	monomial(const TYPE& factor, const size_t& power);
	void set(const TYPE& factor, const size_t& power);
	bool operator ==(const monomial<TYPE>& second);
	size_t getPower() const;
	TYPE& getFactor();
	TYPE getFactor() const;
	monomial* next() const;
};

template <typename TYPE>
inline monomial<TYPE>::monomial(const TYPE& factor, const size_t& power)
{
	_factor = factor;
	_power = power;
	_next = nullptr;
}

template<typename TYPE>
inline bool monomial<TYPE>::operator ==(const monomial<TYPE>& second)
{
	if ((_factor == second._factor) && (_power == second._power))
		return true;
	
	return false;
}

template <typename TYPE>
inline void monomial<TYPE>::set(const TYPE& factor, const size_t& power)
{
	if (power < 0) throw "Power can not be less than 0";

	_factor = factor;
	_power = power;
}

template <typename TYPE>
inline size_t monomial<TYPE>::getPower() const
{
	return _power;
}

template <typename TYPE>
inline TYPE& monomial<TYPE>::getFactor()
{
	return _factor;
}

template <typename TYPE>
inline TYPE monomial<TYPE>::getFactor() const
{
	return _factor;
}

template <typename TYPE>
inline monomial<TYPE>* monomial<TYPE>::next() const
{
	return _next;
}