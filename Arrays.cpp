#include "Arrays.h"

void print(int**, size_t);

Arrays::~Arrays()
{
	for (size_t i = 0; i < size; i++)
		delete[] this->arr[i];
	delete[] this->arr;
}

void Arrays::start()
{
	cout << "Enter array size:" << endl;
	cin >> this->size;

	this->arr = new int* [this->size];

	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i] = new int[this->size];

		for (size_t b = 0; b < this->size; b++)
			this->arr[i][b] = rnd() % (46 * 2) - 46;
	}

	print(this->arr, this->size);

	int k = 0;

	cout << "Enter some number:" << endl;
	cin >> k;

	bool isDone = false;

	for (size_t i = this->size / 2, left = 0; i < this->size && !isDone; i++, left++)
	{
		for (size_t j = left; j >= 0; j--)
		{
			if (this->arr[i][i - j] % k == 0)
			{
				cout << "First element indices " << "[" << i + 1 << "][" << i - j + 1 << "]" << endl;

				isDone = true;
				break;
			}
		
			if (j == 0)
				break;
		}

		if (left >= 1 || size % 2 == 0)
			++left;
	}

	int max = this->arr[0][0];

	for (size_t i = 1; i < this->size; i++)
		if (max < arr[i][i])
			max = arr[i][i];

	size_t count = 0;

	for (size_t i = 0; i < size; i++)
		for (size_t b = i + 1; b < size; b++)
		{
			arr[i][b] = max;
			++count;
		}

	cout << "Amount elements: " << count << endl;

	print(arr, size);
}

void print(int** arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t b = 0; b < size; b++)
			cout << std::setw(4) << arr[i][b];

		cout << endl << endl;
	}
}