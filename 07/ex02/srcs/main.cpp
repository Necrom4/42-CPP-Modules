#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate(void)
{
	std::srand(time(0));
	int	which = rand() % 3 + 1;

	if (which == 1)
	{std::cout << "A generated" << std::endl; return new A;}
	else if (which == 2)
	{std::cout << "B generated" << std::endl; return new B;}
	else if (which == 3)
	{std::cout << "C generated" << std::endl; return new C;}
	return 0;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A* identified" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B* identified" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C* identified" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A& identified" << std::endl;
	}
	catch (std::exception &e){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B& identified" << std::endl;
	}
	catch (std::exception &e){}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C& identified" << std::endl;
	}
	catch (std::exception &e){}
}

int main()
{
	Base *base = new Base;
	base = generate();
	identify(base);
	identify(*base);

	return 0;
}
