#include "Fraction.h"

// Constructors:
Fraction::Fraction(long z, long n) throw(Fraction::DivError)
{
	if (n == 0) 
		throw Fraction::DivError();
	else if (z < 0) z = -z, n = -n;
	numerator = z; denominator = n;
}
Fraction::Fraction(double x)
{
	x *= 1000.0;
	x += (x >= 0.0) ? 0.5 : -0.5; // Round the 4th digit.
	numerator = (long)x;
	denominator = 1000;
	simplify();
}

// To simplify fractions:
void Fraction::simplify()
{
	// Divide the numerator and denominator by
	// the greatest common divisor.
	if (numerator == 0)
	{
		denominator = 1;
		return;
	}
	// Calculating the greatest common divisor
	// using an algorithm by Euclid.
	long a = (numerator < 0) ? -numerator : numerator,
		b = denominator,
		help;
	while (b != 0)
	{
		help = a % b; a = b; b = help;
	}
	// a is the greatest common divisor
	numerator /= a;
	denominator /= a;
}

Fraction operator+(const Fraction& a, const Fraction& b)
{
	Fraction temp;
	temp.denominator = a.denominator * b.denominator;
	temp.numerator = a.numerator * b.denominator
		+ b.numerator * a.denominator;
	temp.simplify();
	return temp;
}
Fraction operator-(const Fraction& a, const Fraction& b)
{
	Fraction temp = a; temp += (-b);
	return temp;
}
Fraction operator*(const Fraction& a, const Fraction& b)
{
	Fraction temp;
	temp.numerator = a.numerator * b.numerator;
	temp.denominator = a.denominator * b.denominator;
	return temp;
}
Fraction operator/(const Fraction& a, const Fraction& b)
{
	if (b.numerator == 0)
		throw Fraction::DivError();
	
	// To multiply a by the inverse of b:
	Fraction temp;
	temp.numerator = a.numerator * b.denominator;
	temp.denominator = a.denominator * b.numerator;
	if (temp.denominator < 0)
		temp.numerator = -temp.numerator,
		temp.denominator = -temp.denominator;
	return temp;
}
std::ostream& operator<<(std::ostream& os, const Fraction& a)
{
	os << a.numerator << "/" << a.denominator;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& a)
{
	std::cout << "Enter a fraction:\n"
		" Numerator: "; is >> a.numerator;
	std::cout << " Denominator != 0: "; is >> a.denominator;
	if (!is) return is;
	if (a.denominator == 0)
	{
		std::cout << "\nError: The denominator is 0\n"
			" New denominator != 0: ";
		is >> a.denominator;
		if (a.denominator == 0)
			throw Fraction::DivError();
	}
	if (a.denominator < 0)
		a.numerator = -a.numerator,
		a.denominator = -a.denominator;
	return is;
}