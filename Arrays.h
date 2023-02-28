#pragma once
#include "TaskTemplates.h"
#include <iostream>
#include <random>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

class Arrays : public ITask
{
private: 
	std::random_device rnd;

	size_t size = 0;
	int** arr{};
public:
	~Arrays();

	void start() override;
};