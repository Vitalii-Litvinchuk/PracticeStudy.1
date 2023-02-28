#pragma once
#include <string>

using std::string;

class People
{
private:
	string name = "";
	string surname = "";
	string birthdayYear = "";
public:
	People() = default;

	People(string name, string surname, string birthdayYear)
	{
		setName(name);
		setSurname(surname);
		setBirthdayYear(birthdayYear);
	}

	void setName(string name)
	{
		this->name = name;
	}
	void setSurname(string surname)
	{
		this->surname = surname;
	}
	void setBirthdayYear(string birthdayYear)
	{
		this->birthdayYear = birthdayYear;
	}

	string getName()
	{
		return name;
	}
	string getSurname()
	{
		return surname;
	}
	string getBirthday()
	{
		return birthdayYear;
	}
};

class Academic : public People
{
private:
	string degree = "";
	size_t numberOfPublications = 0;
	string salary = "";
public:
	Academic() = default;

	Academic(string name, string surname, string birthdayYear, string degree, size_t numberOfPublications, string salary)
		: People(name, surname, birthdayYear)
	{
		setDegree(degree);
		setNumberOfPublications(numberOfPublications);
		setSalary(salary);
	}

	void setDegree(string degree)
	{
		this->degree = degree;
	}
	void setNumberOfPublications(size_t numberOfPublications)
	{
		this->numberOfPublications = numberOfPublications;
	}
	void setSalary(string salary)
	{
		this->salary = salary;
	}

	string getDegree()
	{
		return degree;
	}
	size_t getNumberOfPulications()
	{
		return numberOfPublications;
	}
	string getSalary()
	{
		return salary;
	}
};