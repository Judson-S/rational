// rational.cpp : Defines the entry point for the application.
//

#include "rational.hpp"
#include <stdexcept>
#include <compare>

Rational::Rational() : _num{ 0 }, _den{ 1 } {}

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

int& Rational::den() 
{
	return _den;
}

int Rational::den() const
{
	return _den;
}

void Rational::den(int denominator)
{
	int common_factor;
	if (denominator != 0)
	{
		common_factor = GCF(_num, denominator);
		_den = denominator / common_factor;
		_num /= common_factor;
	}
	else
	{
		throw std::domain_error("Denominator cannot be zero");
	}
}

int& Rational::num() 
{
	return _num;
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

Rational Rational::operator/(Rational const& div)
{
	Rational rhs = div;
	Rational lhs;
	lhs.num(_num);
	lhs.den(_den);

	if (rhs.num() == 0)
	{
		throw std::domain_error("Cannot Divide if reciprocal denominator is 0");
	}
	int lcm = LCM(lhs.den(), rhs.num());

	lhs.num(lhs.num() * rhs.den());
	lhs.den(lhs.den() * rhs.num());
	return lhs;
}

Rational Rational::operator=(Rational value)
{
	this->num() = value.num();
	this->den() = value.den();

	return *this;
}

Rational& Rational::operator +=(Rational& addEqual)
{
	Rational lhs;
	lhs.num(_num);
	lhs.den(_den);

	lhs = lhs + addEqual;
	return lhs;
}

Rational& Rational::operator -=(Rational& subEqual)
{
	Rational lhs;
	lhs.num(_num);
	lhs.den(_den);

	lhs = lhs - subEqual;
	return lhs;
}

Rational& Rational::operator *=(Rational& multEqual)
{
	Rational lhs;
	lhs.num(_num);
	lhs.den(_den);

	lhs = lhs * multEqual;
	return lhs;
}

Rational& Rational::operator/=(Rational& divEqual)
{
	Rational lhs;
	lhs.num(_num);
	lhs.den(_den);

	lhs = lhs / divEqual;
	return lhs;
}

void Rational::increment()
{
	this->num(this->num() + this->den());
}
void Rational::decrement()
{
	this->num(this->num() - this->den());
}
Rational& Rational::operator ++()
{
	increment();
	return *this;
}

Rational& Rational::operator --()
{
	decrement();
	return *this;
}

Rational Rational::operator ++(int)
{
	Rational copy = *this;
	increment();
	return copy;
}

Rational Rational::operator --(int)
{
	Rational copy = *this;
	decrement();
	return copy;
}

Rational::Rational(int value) : Rational(value , 1){}

Rational::Rational(double value) : Rational( value * doubleBase, doubleBase ){}

Rational::operator int() const
{
	return (int)(this->num()) / this->den();
}

Rational::operator double() const
{
	return (double)(this->num()) / this->den();
}

std::strong_ordering Rational::operator<=>(Rational const& comp)
{
	Rational rhs = comp;
	Rational lhs;
	lhs.num(_num);
	lhs.den(_den);

	int lcm = LCM(lhs.den(), rhs.den());

	lhs.num(lhs.num() * (lcm / lhs.num()));
	rhs.num(rhs.num() * (lcm / rhs.num()));

	lhs.den(lcm);
	rhs.den(lcm);

	if (lhs.num() < rhs.num())
	{
		return std::strong_ordering::less;
	}
	if (lhs.num() > rhs.num())
	{
		return std::strong_ordering::greater;
	}
	if (lhs.num() == rhs.num())
	{
		return std::strong_ordering::equal;
	}
	return std::strong_ordering();
}


std::istream& operator>>(std::istream& in, Rational& rational)
{
	int num, den;
	char slash;

	if (!(in >> num))
	{
		in.putback(num);
		in.setstate(std::ios::failbit);
	}

	if (in >> slash && slash != '/')
	{
		in.putback(slash);
		in.setstate(std::ios::failbit);
	}
	
	if (!(in >> den))
	{
		in.putback(den);
		in.setstate(std::ios::failbit);
	}

	rational = Rational(num, den);
	in >> rational.den();

	return in;
}

std::ostream& operator<<(std::ostream& out,Rational const& rational)
{
	out << rational.num() << "/" << rational.den();
	return out;
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

//Rational operator ""_Rational(Rational lit)
//{
//
//}