#include "Functions.h"

Functions::Functions()
{
	this->a = new long double[size]
	{
		6, 5.6, 8.3, 7.4, 3.1, 4.6, 3.5, 1.4, 5.2, 8.3
	};

	this->b = new long double[size]
	{
		-8.5, 1.3, 4.9, -5.6, 6.7, -1.2, 7.8, 9.3, 14.5, 12.1
	};

	auto funcA = [](long double a)
	{
		return sqrt(a);
	};
	auto funcB = [](long double b)
	{
		return abs(b);
	};

	long double sumA = sumArray(this->a, funcA),
		sumB = sumArray(this->b, funcB);

	this->z = 0.75 * (sumA + sqrt(sumB));
}

Functions::~Functions()
{
	delete[] this->a, this->b;
}

long double Functions::getZ()
{
	return this->z;
}

void Functions::start()
{
	std::cout << "Expression value: " << getZ() << std::endl;
}
