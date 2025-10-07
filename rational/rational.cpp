// rational.cpp : Defines the entry point for the application.
//

#include "rational.hpp"
#include <stdexcept>

Rational::Rational()
{
	_num = 0;
	_den = 1;
}

Rational::Rational(int den, int num)
{
	if (den != 0)
	{
		_den = den / GCF(num, den);
		_num = num / GCF(num, den);
	}
	else
	{
		throw std::domain_error("Denominator cannot be zero");
	}
}

int Rational::den() const
{
	return _den;
}

void Rational::den(int denominator)
{
	if (denominator != 0);
	{
		_den = denominator / GCF(_num, denominator);
	}
}

int Rational::num() const
{
	return _num;
}

void Rational::num(int numerator)
{
	_num = numerator / GCF(numerator, _den);
}

Rational Rational::operator+(Rational const& add)
{
	Rational rhs = add;
	Rational lhs;
	lhs.num(_num);
	lhs.den(_den);

	int lcm = LCM(lhs.den(), rhs.den());
	
	lhs.num( lhs.num() * (lcm / lhs.num()));
	rhs.num( rhs.num() * (lcm / rhs.num()));

	lhs.den(lcm);
	rhs.den(lcm);

	lhs.num(lhs.num() + rhs.num());

	return lhs;
}

Rational Rational::operator-(Rational const& sub)
{
	Rational rhs = sub;
	Rational lhs;
	lhs.num(_num);
	lhs.den(_den);

	int lcm = LCM(lhs.den(), rhs.den());

	lhs.num(lhs.num() * (lcm / lhs.num()));
	rhs.num(rhs.num() * (lcm / rhs.num()));

	lhs.den(lcm);
	rhs.den(lcm);

	lhs.num(lhs.num() - rhs.num());
	return lhs;
}

Rational Rational::operator*(Rational const& mult)
{
	Rational rhs = mult;
	Rational lhs;
	lhs.num(_num);
	lhs.den(_den);

	int lcm = LCM(lhs.den(), rhs.den());

	lhs.num(lhs.num() * rhs.num());
	lhs.num(lhs.den() * rhs.den());
	return lhs;
}

int Rational::GCF(int x, int y)
{
	if (x % y == 0)
	{
		return y;
	}
	else
	{
		return GCF(y, x % y);
	}

	return 0;
}

int Rational::LCM(int lhs, int rhs)
{
	return lhs/GCF(lhs,rhs) * rhs;
}

Rational operator ""_Rational(Rational lit)
{

}