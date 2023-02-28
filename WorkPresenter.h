#pragma once
#include "Menu.h"
#include "TaskTemplates.h"
#include "Sorting.h"
#include "Functions.h"
#include "Arrays.h"
#include "Strings.h"
#include "AcademicWorker.h"
#include <vector>

using std::cin;

class WorkPresenter
{
private:
	std::vector<ITask*> tasks;
public:
	WorkPresenter();

	~WorkPresenter();

	void DoIt();
};