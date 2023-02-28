#include "WorkPresenter.h"

WorkPresenter::WorkPresenter()
{
	{
		Sorting* sorting = new Sorting();

		if (sorting)
			tasks.push_back(dynamic_cast<ITask*>(sorting));
	}

	{
		Functions* function = new Functions();

		if (function)
			tasks.push_back(dynamic_cast<ITask*>(function));
	}

	{
		Arrays* array = new Arrays();

		if (array)
			tasks.push_back(dynamic_cast<ITask*>(array));
	}

	{
		Strings* string = new Strings();

		if (string)
			tasks.push_back(dynamic_cast<ITask*>(string));
	}

	{
		ListOfAcademics* listOfAcademics = new ListOfAcademics();

		if (listOfAcademics)
			tasks.push_back(dynamic_cast<ITask*>(listOfAcademics));
	}
}

WorkPresenter::~WorkPresenter()
{
	tasks.clear();
}

void WorkPresenter::DoIt()
{
	size_t taskIndex = 0, size = this->tasks.size();
	string* options = new string[size]
	{
		"Sorting", "Functions", "Arrays", "Strings", "Files"
	};

	Menu menu;

	do
	{
		taskIndex = menu.getOption(options, size);

		if (taskIndex < size)
			tasks[taskIndex]->start();
		else break;

		system("pause");
		system("cls");
	} while (true);

	delete[] options;
}
