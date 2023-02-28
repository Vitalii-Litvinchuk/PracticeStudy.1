#include "Menu.h"

size_t Menu::getOption(std::string* options, size_t size)
{
	cout << '<';
	for (size_t i = 0; i < this->indentation * 2; i++)
		cout << '-';

	cout << "Choose options";

	for (size_t i = 0; i < this->indentation * 2; i++)
		cout << '-';
	cout << '>';

	cout << endl;
	getCaretPosition();
	ShowConsoleCursor(false);

	size_t choose = 0, size1 = size;
	std::string* options1 = new std::string[size1];

	for (size_t i = 0; i < size1; i++)
		options1[i] = options[i];

	addExit(options1, size1);

	printOptions(options1, size1, choose);

	bool isSelected = false;
	bool saver = false;
	char move = '\0';

	while (!isSelected)
	{
		if (move = _getch())
		{
			if (move == ' ' || move == (char)Enter)
				isSelected = true;

			if (move == char(Up_Arrow))
				if (choose == 0)
					choose = size1 - 1;
				else
					--choose;
			else if (move == char(Down_Arrow))
				if (choose == size1 - 1)
					choose = 0;
				else
					++choose;

			printOptions(options1, size1, choose);
		}
	}

	clear(options1, size1);
	ShowConsoleCursor(true);

	delete[] options1;

	return choose;
}

void Menu::getCaretPosition()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;

	if (GetConsoleScreenBufferInfo(hConsole, &cbsi))
	{
		x = cbsi.dwCursorPosition.X;
		y = cbsi.dwCursorPosition.Y;
	}
}

void Menu::addExit(std::string*& options, size_t& size)
{
	if (options[options->length() - 1] == "exit"
		|| options[options->length() - 1] == "Exit")
		return;

	size_t newSize = size + 1;
	std::string* newOptions = new std::string[newSize]{ "" };

	for (size_t i = 0; i < size; i++)
		newOptions[i] = options[i];

	newOptions[newSize - 1] = "Exit";

	size = newSize;
	options = newOptions;
}

void Menu::StartCursor(const SHORT x = 0, const SHORT y = 0)
{
	COORD position{ x + this->x, y + this->y };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hConsole, position);
}

void Menu::printOptions(std::string* options, size_t size, size_t choose)
{
	StartCursor();
	for (size_t i = 0; i < size; i++)
	{
		for (size_t b = 0; b < this->indentation; b++)
			cout << ' ';

		if (choose == i)
		{
			cout << (char)LeftTriangle;

			//cout << options[i];
			animation(options[i], i);

			cout << (char)RightTriangle;
		}
		else
			cout << options[i];

		for (size_t b = 0; b < this->indentation; b++)
			cout << ' ';
		cout << endl;
	}
}

void Menu::clear(std::string* options, size_t size)
{
	--this->y;

	StartCursor();

	for (size_t i = 0; i < 15 + indentation * 4 + 2; i++)
		cout << ' ';
	cout << endl;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t b = 0; b < options[i].length() + this->indentation * 2 + 2; b++)
			cout << ' ';
		cout << endl;
	}

	StartCursor();
}

BOOL Menu::ShowConsoleCursor(BOOL bShow)
{
	CONSOLE_CURSOR_INFO cci;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE)
		return FALSE;

	if (!GetConsoleCursorInfo(hStdOut, &cci))
		return FALSE;

	cci.bVisible = bShow;

	if (!SetConsoleCursorInfo(hStdOut, &cci))
		return FALSE;

	return TRUE;
}

void Menu::animation(std::string option, size_t choose)
{
	std::packaged_task<void()> task([&option, &choose, this]()
		{
			{
				char blockStart = (char)178;
				char blockMiddle = (char)177;
				char blockEnd = (char)176;

				for (size_t i = 0; i < option.length(); i++)
				{
					StartCursor((SHORT)(indentation + 1 + i), (SHORT)choose);
					cout << blockStart;

					if (i + 2 >= option.length())
					{
						StartCursor((SHORT)(indentation + 2 + i), (SHORT)choose);
						cout << blockMiddle;
					}

					if (i + 3 >= option.length())
					{
						StartCursor((SHORT)(indentation + 3 + i), (SHORT)choose);
						cout << blockEnd;
					}

					if (i % 2 == 0)
						Sleep(10);

					StartCursor((SHORT)(indentation + 1 + i), (SHORT)choose);
					cout << option[i];
				}

			}
		}
	);

	std::thread thread(move(task));

	thread.join();
}
