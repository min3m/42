#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <list>
#include <string>
#include <iostream>
#include <limits>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	std::vector<unsigned int> vec;
	std::deque<unsigned int> deq;

public:
	PmergeMe()
	{
	}
	PmergeMe(const PmergeMe &source)
	{
		*this = source;
	}
	PmergeMe &operator = (const PmergeMe &source)
	{
		this->vec = source.vec;
		this->deq = source.deq;
		return (*this);
	}
	~PmergeMe()
	{
	}
	void init(int argc, char *argv[])
	{
		for (int i = 1; i < argc; i++)
		{
			std::string num(argv[i]);
			check_vaild(num);
			vec.push_back(std::atoi(argv[i]));
			deq.push_back(std::atoi(argv[i]));
		}
		std::cout << "Before: ";
		for (std::vector<unsigned int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		{
			std::cout << *iter << " ";
		}
		std::cout << std::endl;
		std::clock_t start, finish;
		start = clock();
		merge_sort(vec, 0, static_cast<int>(vec.size() - 1), 16);
		finish = clock();
		double vector_time = static_cast<double>(finish - start) / 1000.0;
		start = clock();
		merge_sort(deq, 0, static_cast<int>(deq.size() - 1), 16);
		finish = clock();
		double deque_time = static_cast<double>(finish - start) / 1000.0;
		if (issorted())
			std::cout << "\n\nTwo container are sorted!\n\n" << std::endl;
		else
			std::cout << "\n\nSorry... I have to retry...\n\n" << std::endl;
		std::cout << "After:  ";
		for (std::vector<unsigned int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		{
			std::cout << *iter << " ";
		}
		std::cout << std::endl;
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : ";
		std::cout << std::fixed << std::setprecision(6) << vector_time << "s" << std::endl;
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : ";
		std::cout << std::fixed << std::setprecision(6) << deque_time << "s" << std::endl;
	}
	void check_vaild(std::string &num)
	{
		long number;
		char *end;

		number = std::strtol(num.c_str(), &end, 10);
		if (errno == ERANGE || number > std::numeric_limits<unsigned int>::max())
		{
			throw std::invalid_argument("Error: too big number");
		}
		if (*end)
			throw std::invalid_argument("Error: not a vaild number");
	}
	template <typename T>
	void merge_sort(T &container, int left, int right, int size)
	{
		if (right - left + 1 <= size)
		{
			insertion_sort(container, left, right);
			return ;
		}
		int mid = (left + right) / 2;
		merge_sort(container, left, mid, size);
		merge_sort(container, mid + 1, right, size);
		merge(container, left, mid, right);
	}
	template <typename T>
	void merge(T &container, int left, int mid, int right)
	{
		int l = left;
		int r = mid + 1;
		int k = 0;
		T tmp(right - left + 1);

		while (l <= mid && r <= right)
		{
			if (container[l] <= container[r])
				tmp[k++] = container[l++];
			else
				tmp[k++] = container[r++];
		}
		int i = (l > mid) ? r : l;
		while (k <= right - left)
			tmp[k++] = container[i++];
		for (int j = 0; j < k; j++)
		{
			container[j + left] = tmp[j];
		}
	}
	template <typename T>
	void insertion_sort(T &container, int start, int end)
	{
		unsigned int tmp;

		for (int i = start + 1; i <= end; i++)
		{
			tmp = container[i];
			int j = i;
			while (j >= start + 1 && container[j - 1] > tmp)
			{
				container[j] = container[j - 1];
				j--;
			}
			container[j] = tmp;
		}
	}
	bool issorted()
	{
		for (std::size_t i = 0; i < vec.size() - 1; i++)
		{
			if (vec[i] > vec[i + 1])
				return (false);
			if (deq[i] > deq[i + 1])
				return (false);
		}
		return (true);
	}
};

#endif
