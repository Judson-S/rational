// rational.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

class Rational {

public:
	Rational();
	Rational(int den, int num);

	int& den();
	int den() const;
	void den(int denominator);

	int& num();
	int num() const;
	void num(int numerator);

	//math ops
	Rational operator +(Rational const& add);
	Rational operator -(Rational const& sub);
	Rational operator *(Rational const& mult);
	Rational operator /(Rational const& div);

	//assign ops
	Rational operator =(Rational value);

	//math assign ops
	Rational& operator +=(Rational& addEqual);
	Rational& operator -=(Rational& subEqual);
	Rational& operator *=(Rational& multEqual);
	Rational& operator /=(Rational& divEqual);

	//prefix and postfix incr and decr ops
	Rational& operator ++();
	Rational& operator --();

	Rational operator ++(int);
	Rational operator --(int);

	//compare ops
	std::strong_ordering operator<=>(Rational const& comp);

	//convert ops
	Rational(int);
	Rational(double);
	
	explicit operator int() const;
	explicit operator double() const;
	//IO ops

	//Literal ops in .cpp
	

	friend std::istream& operator>>(std::istream& in, Rational& rational);
private:
	int _den, _num;
	bool negative = false;
	static int const doubleBase{ 1000000 };
	int GCF(int x, int y);
	int LCM(int x, int y);
	void increment();
	void decrement();
};
