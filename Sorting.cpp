#include "Sorting.h"

#include <random>
#include <future>
#include <thread>

using namespace DifferentTypesOfSort;
using std::future;
using std::packaged_task;
using std::thread;
using std::move;

template<typename T>
void copy(T*, size_t, T*);

template<typename T>
void find(T*, size_t);

void Sorting::start()
{
	size_t size = 40000;

	cout << "Enter size:" << endl;
	std::cin >> size;

	int* arr = new int[size];

	for (size_t i = 0; i < size; i++)
		arr[i] = rnd() % size;

	int* extra = new int[size];


	packaged_task<void()> task1([&arr, &size]()
		{
			{
				int* extra = new int[size];

				copy(arr, size, extra);
				Insertion::sort(extra, size);

				delete[] extra;
			}
		}
	);
	thread thread1(move(task1));

	packaged_task<void()> task2([&arr, &size]()
		{
			{
				int* extra = new int[size];

				copy(arr, size, extra);
				Selection::sort(extra, size);

				delete[] extra;
			}
		}
	);
	thread thread2(move(task2));

	packaged_task<void()> task3([&arr, &size]()
		{
			{
				int* extra = new int[size];

				copy(arr, size, extra);
				Bubble::sort(extra, size);

				delete[] extra;
			}
		}
	);
	thread thread3(move(task3));

	copy(arr, size, extra);
	Shell::sort(extra, size);

	copy(arr, size, extra);
	Merge::sort(extra, size);

	copy(arr, size, extra);
	Heap::sort(extra, size);

	copy(arr, size, extra);
	Quick::sort(extra, size);

	thread3.join();
	thread2.join();
	thread1.join();

	find(extra, size);

	delete[] arr, extra;
}

template<typename T>
void copy(T* arr1, size_t size, T* arr2)
{
	for (size_t i = 0; i < size; i++)
		arr2[i] = arr1[i];
}

template<typename T>
void find(T* arr, size_t size)
{
	T number = 0;
	bool done = false;

	cout << "\tEnter number: " << endl;
	std::cin >> number;

	for (size_t i = 0; i < size; i++)
		if (arr[i] == number)
		{
			cout << "Your element by index: " << i<< endl;
			done = true;
			break;
		}

	if (!done)
		cout << "Element " << number << " not found" << endl;
}
