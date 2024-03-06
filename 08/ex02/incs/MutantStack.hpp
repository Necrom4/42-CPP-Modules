#pragma once
#include <iostream>
#include <stack>
#include <deque>
#include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
	private:
	public:
		typedef typename std::deque<T>::iterator iterator;
		MutantStack(){}
		MutantStack(const MutantStack &copy){*this = copy;}
		MutantStack &operator=(const MutantStack &copy){this->c = copy.c; return *this;}
		~MutantStack(){}

		iterator begin(){return this->c.begin();}
		iterator end(){return this->c.end();}
};
