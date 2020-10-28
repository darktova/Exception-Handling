#include "FloatArr.h"
// Constructors, destructor, assignment,
// and subscript operator unchanged.

FloatArr::FloatArr(const FloatArr& src)
{
	max = src.max; cnt = src.cnt;
	arrPtr = new float[max];
	for (int i = 0; i < cnt; i++)
		arrPtr[i] = src.arrPtr[i];
}

FloatArr::FloatArr(int n)
{
}

FloatArr::FloatArr(int n, float val)
{
}

FloatArr::~FloatArr()
{
}

// Private auxiliary function to enlarge the array.
void FloatArr::expand(int newMax)
{
	if (newMax == max)
		throw BadIndex(newMax);
	max = newMax;
	if (max < cnt)
		cnt = max;

	float* temp = new float[max];
	for (int i = 0; i < cnt; ++i)
		temp[i] = arrPtr[i];
	delete[] arrPtr;
	arrPtr = temp;
}

int FloatArr::length() const
{
	return cnt;
}

float& FloatArr::operator[](int i)
{
	if (i < 0 || i >= cnt)
		throw BadIndex(i);
	else return arrPtr[i];
}

float FloatArr::operator[](int i) const
{
	if (i < 0 || i >= cnt)
		throw BadIndex(i);
	else return arrPtr[i];
}

// Append floating-point number or an array of floats.
void FloatArr::append(float val)
{
	if (cnt + 1 > max)
		expand(cnt + 1);
	arrPtr[cnt++] = val;
}

void FloatArr::append(const FloatArr& v)
{
	if (cnt + v.cnt > max)
		expand(cnt + v.cnt);

	int count = v.cnt; // Necessary if v == *this
	for (int i = 0; i < count; ++i)
		arrPtr[cnt++] = v.arrPtr[i];
}

FloatArr& FloatArr::operator=(const FloatArr& src)
{
	if (this != &src) // No self assignments!
	{
		max = src.max;
		cnt = src.cnt;
		delete[] arrPtr; // Release memory,
		arrPtr = new float[max]; // reallocate and
		for (int i = 0; i < cnt; i++) // copy elements.
			arrPtr[i] = src.arrPtr[i];
	}
	return *this;
}

FloatArr& FloatArr::operator+=(float val)
{
	append(val); return *this;
}

FloatArr& FloatArr::operator+=(const FloatArr& v)
{
	append(v); return *this;
}

// Insert a float or an array of floats
void FloatArr::insert(float val, int pos)
{
	return insert(FloatArr(1, val), pos);
}

void FloatArr::insert(const FloatArr& v, int pos)
{
	if (pos < 0 || pos >= cnt)
		throw BadIndex(cnt); // Invalid position
	if (max < cnt + v.cnt)
		expand(cnt + v.cnt);

	int i;
	for (i = cnt - 1; i >= pos; --i) // Shift up
		arrPtr[i + v.cnt] = arrPtr[i]; // starting at pos
	for (i = 0; i < v.cnt; ++i) // Fill gap.
		arrPtr[i + pos] = v.arrPtr[i];
	cnt = cnt + v.cnt;
}

// To delete
void FloatArr::remove(int pos)
{
	if (pos >= 0 && pos < cnt)
	{
		for (int i = pos; i < cnt - 1; ++i)
			arrPtr[i] = arrPtr[i + 1];
		--cnt;
	}
	else
		throw BadIndex(pos);
}

// Output the array
std::ostream& operator<<(std::ostream& os, const FloatArr& v)
{
	int w = os.width(); // Save field width.
	for (float* p = v.arrPtr; p < v.arrPtr + v.cnt; ++p)
	{
		if (*p <= 0 || *p >= v.cnt)
			throw(*p);
		os.width(w); os << *p;
	}
	return os;
}

int BadIndex::getBadIndex() const
{
	return index;
}
