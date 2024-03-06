#pragma once
#include <iostream>
#include <cstdint>

struct Data
{
	int			n;
	std::string str;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
	public:
		~Serializer();

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
