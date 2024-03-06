#pragma once
#include <iostream>
#include <list>
#include <deque>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
	public:
		~PmergeMe();

		static int	errorHandling(int argc, char **argv);
		template <typename T>
		static void	stockNums(T &stack, int argc, char **argv)
		{
			for (int i = 1; i < argc; i++)
				stack.push_back(std::stoi(argv[i]));
		}
		template <typename T>
		static bool isSorted(T &stack)
		{
			typename T::iterator prev = stack.begin();
			typename T::iterator current = std::next(prev);

			while (current != stack.end())
			{
				if (*prev > *current)
					return false;
				++prev;
				++current;
			}

			return true;
		}
		template <typename T>
		static void mergeInsertionsort(T &stack)
		{
			T stack_copy = stack;
			typename T::iterator current = stack_copy.begin();
			typename T::iterator next = std::next(current);

			while (current != stack_copy.end() && next != stack_copy.end())
			{
				if (*current > *next)
				{
					typename T::value_type tmp = *current;
					*current = *next;
					*next = tmp;
				}
				std::advance(current, 2);
				std::advance(next, 2);
			}
			stack.begin() = std::next(stack_copy.begin());
			typename T::iterator it = stack.begin();
			current = stack_copy.begin();
			std::advance(current, 3);
			while (current != stack_copy.end())
			{
				while (*current > *it)
					++it;
				stack.insert(it, *current);
				it = stack.begin();
				if (std::next(current) == stack_copy.end())
					break ;
				std::advance(current, 2);
			}
			it = stack.begin();
			current = stack_copy.begin();
			while (current != stack_copy.end())
			{
				while (*current > *it)
					++it;
				stack.insert(it, *current);
				it = stack.begin();
				if (std::next(current) == stack_copy.end())
					break ;
				std::advance(current, 2);
			}
			it = stack.begin();
			current = stack_copy.begin();
			while (current != stack_copy.end())
			{	++it; ++current;}
			stack.erase(it, stack.end());
		}
		template <typename T>
		static void mySort(T &stack)
		{
			int x = 0;

			while (!isSorted(stack))
			{
				typename T::iterator current = stack.begin();
				typename T::iterator next = std::next(current);

				if (x % 2 != 0)
				{
					++current;
					++next;
				}
				while (current != stack.end() && next != stack.end())
				{
					if (*current > *next)
					{
						typename T::value_type tmp = *current;
						*current = *next;
						*next = tmp;
					}
					std::advance(current, 2);
					std::advance(next, 2);
				}
				x++;
			}
		}
};
