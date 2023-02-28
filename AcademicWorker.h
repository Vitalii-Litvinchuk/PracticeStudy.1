#pragma once
#include "TaskTemplates.h"
#include "AcademicWorker.h"
#include "Menu.h"
#include "Files.h"
#include <iostream>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;

class ListOfAcademics : public ITask
{
private:
	enum WorkerTypes
	{
		Create = 0, GetOlder45, GetAll
	};
	string filename = "";

	void printAcademics(pair<Academic*, size_t>*);
	void createAcademic();
	pair<Academic*, size_t> getOlder45();
	pair<Academic*, size_t> getAll();
public:
	ListOfAcademics();

	void start() override;
};

