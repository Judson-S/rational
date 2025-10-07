// rational.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

class Rational {

public:
	Rational();
	Rational(int den, int num);

	int den() const;
	void den(int denominator);

	int num() const;
	void num(int numerator);

	//math ops
	Rational operator +(Rational const& add);
	Rational operator -(Rational const& sub);
	Rational operator *(Rational const& mult);
	Rational operator /(Rational const& div);

	//math assign ops
	Rational operator +=(Rational const& add);
	Rational operator -=(Rational const& sub);
	Rational operator *=(Rational const& mult);
	Rational operator /=(Rational const& div);

	//compare ops
	Rational operator <=>(Rational const& rhs);
	Rational operator ==(Rational const& rhs);

	//convert ops
	double operator =(Rational const& conv);
	
	//IO ops
	std::istream& operator >>(Rational& in);
	std::ostream& operator <<(Rational const& out);

	//Literal ops in .cpp
	
private:
	int _den, _num;
	bool negative = false;
	int GCF(int x, int y);
	int LCM(int x, int y);
};
