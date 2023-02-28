#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <thread>
#include <future>

using std::cout;
using std::endl;

class Menu
{
private:
	enum FunctionLitterals
	{
		Up_Arrow = 72,
		Down_Arrow = 80,
		Enter = 13,
		LeftTriangle = 17,
		RightTriangle = 16,
	};

	SHORT x = 0, y = 0;
	size_t indentation = 0;

	void getCaretPosition();
	void addExit(std::string*&, size_t&);
	void StartCursor(const SHORT, const SHORT);
	void printOptions(std::string*, size_t, size_t);
	void clear(std::string*, size_t);
	BOOL ShowConsoleCursor(BOOL);
	void  animation(std::string, size_t);
public:
	/// <summary>
	/// Indentation from one side
	/// </summary>
	Menu(size_t indentation = 3)
	{
		this->indentation = indentation;
	}

	size_t getOption(std::string*, size_t);
};
