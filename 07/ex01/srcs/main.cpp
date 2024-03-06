#include "Serializer.hpp"

int main()
{
	Data		*data = new Data;
	uintptr_t	copied_data;
	Data		*returned_data;

	data->n = 17;
	data->str = "hey";

	std::cout << "Data: 		" << data << std::endl;
	std::cout << "		" << data->n << std::endl;
	std::cout << "		" << data->str << std::endl;
	copied_data = Serializer::serialize(data);
	std::cout << std::endl << "Copied Data:	"  << copied_data << std::endl << std::endl;
	returned_data = Serializer::deserialize(copied_data);
	std::cout << "Returned Data:	" << returned_data << std::endl;
	std::cout << "		" << returned_data->n << std::endl;
	std::cout << "		" << returned_data->str << std::endl;

	delete data;

	return 0;
}
