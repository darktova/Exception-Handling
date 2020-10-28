#include "FloatArr.h"
#include "Fraction.h"

int main()
{
/*
	const FloatArr data(100, 7);
	try
	{
		while (true)
		{	
			int i = -1;
			std::cout << "\nInput the index of element: ";
			std::cin >> i;
			std::cout << data[i];
		}
	}
	catch (const BadIndex& e)
	{
		std::cerr << "\nError in reading: "
			<< "\nInvalid index: " << e.getBadIndex();
	}

	FloatArr data1(100);
	try
	{
		std::cout << "\nInserting & appending the elements.";
		data1.append(rand() % 10000);
		data1.insert(rand() % 10000, 1);
		data1.append(rand() % 10000);
		data1.insert(rand() % 10000, 855);
	}
	catch (const BadIndex& e)
	{
		std::cerr << "\nError in writing: "
			<< "\nInvalid index: " << e.getBadIndex();
	}

	for (int i = 0; i < data1.length(); i++)
		std::cout << data1[i] << '\n';
*/

	try
	{
		Fraction(1, 2);
		Fraction(0, 2);
		Fraction(1, 0);
	}
	catch (Fraction::DivError&)
	{
		std::cout << "\nError in initializing :"
			<< "\nThe denominator is 0!";
	}
	
	try
	{
		Fraction t = Fraction(2, 14) / Fraction(0);
	}
	catch (Fraction::DivError&)
	{
		std::cout << "\nError in division :"
			<< "\nNo division by zero!";
	}

	try
	{
		Fraction t(1);
		std::cin >> t;
	}
	catch (Fraction::DivError&)
	{
		std::cout << "\nError: Denominator is 0!"
			<< "\nNew denominator != 0: ...";
	}
}