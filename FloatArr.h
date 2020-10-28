#pragma once
#ifndef _FLOATARR_
#define _FLOATARR_
#include <iostream>
#include <stdexcept>

class BadIndex
{
private:
	int index;

public:
	BadIndex(int i)
		: index(i) {};
	int getBadIndex() const;

};

class FloatArr
{
private:
	float* arrPtr; // Dynamic member
	int max; // Maximum quantity without
	// reallocating new storage.

	int cnt; // Number of present array elements
	void expand(int newMax) throw(BadIndex); // Helps enlarge the array

public:
	FloatArr(const FloatArr& src);
	FloatArr(int n = 256); // Constructor
	FloatArr(int n, float val);
	~FloatArr(); // Destructor
	int length() const;
	float& operator[](int i) throw(BadIndex); // Subscript operator.
	float operator[](int i) const throw(BadIndex);
	void append(float val) ;
	void append(const FloatArr&);
	FloatArr& operator=(const FloatArr&); // Assignment
	FloatArr& operator+=(float);
	FloatArr& operator+=(const FloatArr& v);
	// Methods to insert a floating-point number
	// or an array of floating-point numbers:
	void insert(float val, int pos) throw(BadIndex);
	void insert(const FloatArr& v, int pos) throw(BadIndex);
	void remove(int pos) throw(BadIndex); // Delete at position pos.
	// To output the array
	friend std::ostream& operator<<(std::ostream& os,
		const FloatArr& v) throw(BadIndex);
};
#endif // _FLOATARR_

