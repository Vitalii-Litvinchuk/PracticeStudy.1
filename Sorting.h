#pragma once
#include "TaskTemplates.h"
#include "Timer.h"
#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::swap;

class Sorting : public ITask
{
private:
	std::random_device rnd;
public:
	void start() override;
};

namespace DifferentTypesOfSort
{
	/// <summary>
	/// One dimensional array.
	/// Sort to greater.
	/// Print sort time.
	/// </summary>
	class Insertion
	{
	public:
		template<typename T>
		static void sort(T*, size_t);
	};

	template<typename T>
	inline void Insertion::sort(T* arr, size_t size)
	{
		Timer timer;
		timer.start();

		T key;

		for (size_t i = 1, j = 0; i < size; i++)
		{
			key = arr[i];
			j = i - 1;

			while (arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}

		timer.stop();
		cout << "------------------------Insertion------------------------" << endl;
		cout << "Sort time: " << timer.elapsedMilliseconds() << " milliseconds" << endl;
	}

	/// <summary>
	/// One dimensional array.
	/// Sort to greater.
	/// Print sort time.
	/// </summary>
	class Selection
	{
	public:
		template<typename T>
		static void sort(T*, size_t);
	};

	template<typename T>
	inline void Selection::sort(T* arr, size_t size)
	{
		Timer timer;
		timer.start();

		for (size_t i = 0, j = 0, min_index = 0; i < size - 1; i++)
		{
			min_index = i;
			for (j = i + 1; j < size; j++)
				if (arr[j] < arr[min_index])
					min_index = j;

			if (min_index != i)
				swap(arr[min_index], arr[i]);
		}

		timer.stop();
		cout << "------------------------Selection------------------------" << endl;
		cout << "Sort time: " << timer.elapsedMilliseconds() << " milliseconds" << endl;
	}

	/// <summary>
	/// One dimensional array.
	/// Sort to greater.
	/// Print sort time.
	/// </summary>
	class Bubble
	{
	public:
		template<typename T>
		static void sort(T*, size_t);
	};

	template<typename T>
	inline void Bubble::sort(T* arr, size_t size)
	{
		Timer timer;
		timer.start();

		for (size_t i = 0; i < size; i++)
			for (size_t b = i + 1; b < size; b++)
				if (arr[i] > arr[b])
					swap(arr[i], arr[b]);

		timer.stop();
		cout << "------------------------Bubble------------------------" << endl;
		cout << "Sort time: " << timer.elapsedMilliseconds() << " milliseconds" << endl;
	}

	/// <summary>
	/// One dimensional array.
	/// Sort to greater.
	/// Print sort time.
	/// </summary>
	class Shell
	{
	public:
		template<typename T>
		static void sort(T*, size_t);
	};

	template<typename T>
	inline void Shell::sort(T* arr, size_t size)
	{
		cout << "------------------------Shell------------------------" << endl;
		Timer timer;
		timer.start();

		for (size_t gap = size / 2; gap > 0; gap /= 2)
			for (size_t i = gap; i < size; i += 1)
			{
				T temp = arr[i];

				size_t j;
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
					arr[j] = arr[j - gap];

				arr[j] = temp;
			}

		timer.stop();
		cout << "Sort time: " << timer.elapsedMilliseconds() << " milliseconds" << endl;
	}

	/// <summary>
	/// One dimensional array.
	/// Sort to greater.
	/// Print sort time.
	/// </summary>
	class Merge
	{
	private:
		template<typename T>
		static void merge(T* array, size_t const left, size_t const mid, size_t const right);

		template<typename T>
		static void mergeSort(T* array, size_t const begin, size_t const end);
	public:
		template<typename T>
		static void sort(T*, size_t);
	};

	template<typename T>
	inline void Merge::merge(T* array, size_t const left, size_t const mid, size_t const right)
	{
		auto const subArrayOne = mid - left + 1;
		auto const subArrayTwo = right - mid;

		auto* leftArray = new int[subArrayOne],
			* rightArray = new int[subArrayTwo];

		for (auto i = 0; i < subArrayOne; i++)
			leftArray[i] = array[left + i];

		for (auto j = 0; j < subArrayTwo; j++)
			rightArray[j] = array[mid + 1 + j];

		auto indexOfSubArrayOne = 0,
			indexOfSubArrayTwo = 0;
		size_t indexOfMergedArray = left;

		while (indexOfSubArrayOne < subArrayOne
			&& indexOfSubArrayTwo < subArrayTwo)
		{
			if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
			{
				array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

				indexOfSubArrayOne++;
			}
			else
			{
				array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];

				indexOfSubArrayTwo++;
			}

			indexOfMergedArray++;
		}

		while (indexOfSubArrayOne < subArrayOne)
		{
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

			indexOfSubArrayOne++;
			indexOfMergedArray++;
		}

		while (indexOfSubArrayTwo < subArrayTwo)
		{
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];

			indexOfSubArrayTwo++;
			indexOfMergedArray++;
		}

		delete[] leftArray;
		delete[] rightArray;
	}

	template<typename T>
	inline void Merge::mergeSort(T* array, size_t const begin, size_t const end)
	{
		if (begin >= end)
			return;

		auto mid = begin + (end - begin) / 2;
		mergeSort(array, begin, mid);
		mergeSort(array, mid + 1, end);
		merge(array, begin, mid, end);
	}

	template<typename T>
	inline void Merge::sort(T* arr, size_t size)
	{
		cout << "------------------------Merge------------------------" << endl;
		Timer timer;

		size_t begin = 0, end = size - 1;

		timer.start();

		mergeSort(arr, begin, end);

		timer.stop();
		cout << "Sort time: " << timer.elapsedMilliseconds() << " milliseconds" << endl;
	}

	/// <summary>
	/// One dimensional array.
	/// Sort to greater.
	/// Print sort time.
	/// </summary>
	class Heap
	{
	private:
		template<typename T>
		static void heapify(T*, size_t, size_t);
	public:
		template<typename T>
		static void sort(T*, size_t);
	};

	template<typename T>
	inline void Heap::heapify(T* arr, size_t size, size_t i)
	{
		size_t largest = i,
			left = 2 * i + 1,
			right = 2 * i + 2;

		if (left < size && arr[left] > arr[largest])
			largest = left;

		if (right < size && arr[right] > arr[largest])
			largest = right;

		if (largest != i)
		{
			swap(arr[i], arr[largest]);

			heapify(arr, size, largest);
		}
	}

	template<typename T>
	inline void Heap::sort(T* arr, size_t size)
	{
		cout << "------------------------Heap------------------------" << endl;
		Timer timer;
		timer.start();

		if (size > 1)
		{
			for (size_t i = size / 2; i > 0; i--)
				heapify(arr, size, i);

			heapify(arr, size, 0);

			for (size_t i = size - 1; i > 0; i--)
			{
				swap(arr[0], arr[i]);
				heapify(arr, i, 0);
			}
		}

		timer.stop();
		cout << "Sort time: " << timer.elapsedMilliseconds() << " milliseconds" << endl;
	}

	/// <summary>
	/// One dimensional array.
	/// Sort to greater.
	/// Print sort time.
	/// </summary>
	class Quick
	{
	private:
		template<typename T>
		static size_t partition(T*, size_t, size_t);

		template<typename T>
		static void quickSort(T*, size_t, size_t);
	public:
		template<typename T>
		static void sort(T*, size_t);
	};

	template<typename T>
	inline size_t Quick::partition(T* arr, size_t low, size_t high)
	{
		T pivot = arr[high];
		size_t i = low;

		for (size_t j = low; j < high; j++)
			if (arr[j] < pivot)
			{
				swap(arr[i], arr[j]);
				++i;
			}

		swap(arr[i], arr[high]);

		return i;
	}

	template<typename T>
	inline void Quick::quickSort(T* arr, size_t low, size_t high)
	{
		if (low < high)
		{
			size_t pi = partition(arr, low, high);

			quickSort(arr, low, pi == 0 ? 0 : pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}

	template<typename T>
	inline void Quick::sort(T* arr, size_t size)
	{
		cout << "------------------------Quick------------------------" << endl;
		Timer timer;
		timer.start();

		quickSort(arr, 0, size - 1);

		timer.stop();
		cout << "Sort time: " << timer.elapsedMilliseconds() << " milliseconds" << endl;
	}

};