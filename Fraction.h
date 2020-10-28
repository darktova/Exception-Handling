#pragma once
#ifndef _FRACTION_
#define _FRACTION_
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdexcept>

class Fraction
{
private: 
	long numerator, denominator;

public:
	class DivError 
	{
	public:
		DivError() {};
	};
	Fraction(long z, long n) throw(Fraction::DivError);
	Fraction(double x); // double-constructor
	// Default long- and int-constructor:
	Fraction(long z = 0): numerator(z), denominator(1) {}
	Fraction(int z): numerator(z), denominator(1) {}
	void simplify();
	operator double() // Fraction -> double
	{
		return (double)numerator / (double)denominator;
	}
	Fraction operator-() const
	{
		return Fraction(-numerator, denominator);
	}
	Fraction& operator+=(const Fraction& a)
	{
		numerator = a.numerator * denominator
			+ numerator * a.denominator;
		denominator *= a.denominator;
		return *this;
	}
	Fraction& operator-=(const Fraction& a)
	{
		*this += (-a);
		return *this;
	}
	Fraction& operator++()
	{
		numerator += denominator;
		return *this;
	}
	Fraction& operator--()
	{
		numerator -= denominator;
		return *this;
	}

	friend Fraction operator+(const Fraction&, const Fraction&);
	friend Fraction operator-(const Fraction&, const Fraction&);
	friend Fraction operator*(const Fraction&, const Fraction&);
	friend Fraction operator/(const Fraction&, const Fraction&) throw(Fraction::DivError);
	friend std::ostream& operator<< (std::ostream& os, const Fraction& a);
	friend std::istream& operator>> (std::istream& is, Fraction& a) throw(Fraction::DivError);
};
#endif