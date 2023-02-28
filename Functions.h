#pragma once
#include "TaskTemplates.h"
#include <iostream>

class Functions : public ITask
{
private:
	const size_t size = 10;
	long double* a;
	long double* b;
	long double z = 0;

	template <typename F>
	long double sumArray(long double* arr, F numeralFunction);
public:
	Functions();

	~Functions();

	long double getZ();

	void start() override;
};

template<typename F>
long double Functions::sumArray(long double* arr, F numeralFunction)
{
	long double minimal = arr[0];

	for (size_t i = 0; i < this->size; i++)
		if (arr[i] < minimal)
			minimal = arr[i];

	long double sum = 0;

	for (size_t i = 0; i < this->size; i++)
		sum += numeralFunction(arr[i]) / pow(minimal, 2);

	return sum;
}
