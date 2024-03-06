#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::ifstream	input_file;
	std::ifstream	data_file;
	std::multimap<std::string, std::string> input_map;
	std::multimap<std::string, std::string> data_map;

	if (BitcoinExchange::errorHandling(argc, argv))
		return -1;
	input_file.open(argv[1]);
	data_file.open("./other/data.csv");
	data_map = BitcoinExchange::storeDataMap(data_file);
	BitcoinExchange::printWallet(input_file, data_map);

	return 0;
}
