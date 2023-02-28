#include "AcademicWorker.h"

ListOfAcademics::ListOfAcademics()
{
	this->filename = "academics.bin";
}

void ListOfAcademics::printAcademics(pair<Academic*, size_t>* academics)
{
	for (size_t i = 0; i < academics->second; i++)
	{
		cout << academics->first[i].getName() << " "
			<< academics->first[i].getSurname() << " "
			<< academics->first[i].getBirthday() << " "
			<< academics->first[i].getDegree() << " "
			<< academics->first[i].getNumberOfPulications() << " "
			<< academics->first[i].getSalary() << endl;
	}
}

void ListOfAcademics::createAcademic()
{
	string name = "", surname = "", birthday = "", degree = "", salary = "";
	size_t numberOfPublications = 0;

	cout << "Enter name: ";
	cin >> name;

	cout << "Enter surname: ";
	cin >> surname;

	cout << "Enter birthday(year): ";
	cin >> birthday;

	cout << "Enter degree: ";
	cin >> degree;

	cout << "Enter number of publications: ";
	cin >> numberOfPublications;

	cout << "Enter salary: ";
	cin >> salary;

	Academic academic(name, surname, birthday, degree, numberOfPublications, salary);

	Files::writeBinaryAcademicFile(this->filename, academic);
}

pair<Academic*, size_t> ListOfAcademics::getOlder45()
{
	pair<Academic*, size_t> allAcademics = Files::readBinaryAcademicFile(filename);
	auto condition = [](Academic academic)
	{
		try
		{
			return stoi(academic.getBirthday()) < 2023 - 45;
		}
		catch (const std::exception&) {}
		return false;
	};
	size_t size = 0;

	for (size_t i = 0; i < allAcademics.second; i++)
		if (condition(allAcademics.first[i]))
			++size;

	pair<Academic*, size_t> academicsOlder = std::make_pair(new Academic[size], size);

	for (size_t i = 0, b = 0; i < allAcademics.second; i++)
		if (condition(allAcademics.first[i]))
		{
			academicsOlder.first[b] = allAcademics.first[i];
			++b;
		}

	return academicsOlder;
}

pair<Academic*, size_t> ListOfAcademics::getAll()
{
	return Files::readBinaryAcademicFile(filename);
}

void ListOfAcademics::start()
{
	size_t choose = 0;
	pair<Academic*, size_t> academics{};

	Menu menu(5);
	size_t size = 3;
	string* options = new string[3]
	{
		"Create academic", "Print academics older 45", "Print all academics"
	};

	do
	{
		cout << "<>" << endl;
		choose = menu.getOption(options, size);

		switch (choose)
		{
		case Create:
			createAcademic();
			break;

		case GetOlder45:
			academics = getOlder45();
			printAcademics(&academics);
			delete[] academics.first;
			break;

		case GetAll:
			academics = getAll();
			printAcademics(&academics);
			delete[] academics.first;
			break;

		default: break;
		}
	} while (choose >= 0 && choose < 3);
}
