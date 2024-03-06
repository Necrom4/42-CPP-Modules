#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){*this = copy;}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy){(void)copy; return *this;}

BitcoinExchange::~BitcoinExchange(){}

int		BitcoinExchange::errorHandling(int argc, char **argv)
{
	std::ifstream	input_file;
	std::ifstream	data_file;
	std::string		input_line;
	std::string		data_line;

	if (argc != 2)
	{	std::cerr << "Error: wrong number of arguments" << std::endl; return 1; }
	input_file.open(argv[1]);
	data_file.open("./other/data.csv");
	if (data_file.fail())
	{	std::cerr << "Error: could not find .csv" << std::endl; return 1; }
	if (!(std::string(argv[1]).find(".txt") != std::string::npos) || input_file.fail())
	{	std::cerr << "Error: could not find file" << std::endl; return 1; }
	getline(input_file, input_line);
	if (input_line.compare("date | value"))
	{	std::cerr << "Error: wrong input.txt file format" << std::endl; return 1; }
	while (!input_file.eof() && getline(input_file, input_line) && !input_line.compare(""));
	if (input_file.eof())
	{	std::cerr << "Error: empty input.txt" << std::endl; return 1; }
	getline(data_file, data_line);
	if (data_line.compare("date,exchange_rate"))
	{	std::cerr << "Error: wrong data.csv file format" << std::endl; return 1; }
	while (!data_file.eof() && getline(data_file, data_line) && !data_line.compare(""));
	if (data_file.eof())
	{	std::cerr << "Error: empty data.csv" << std::endl; return 1; }

	return 0;
}


std::multimap<std::string, std::string>	BitcoinExchange::storeDataMap(std::ifstream &file)
{
	std::multimap<std::string, std::string>	map;
	std::string		line;
	std::string		date;
	std::string		value;
	std::string		delimiter = ",";

	getline(file, line);
	if (!line.compare("date | value"))
		delimiter = " | ";
	while (!file.eof() && getline(file, line))
	{
		date = line.substr(0, line.find(delimiter));
		value = line.substr(line.find(delimiter) + delimiter.length(), line.length() - 1);
		map.insert(std::make_pair(date, value));
	}

	return map;
}

bool	BitcoinExchange::checkDate(std::string date)
{
	std::string	 test = date.substr(0, 4);
	std::string	test2;

	for (size_t i = 0; i < 3; i++)
		if (!std::isdigit(test[i]))
			return false;
	if (date[4] != '-')
		return false;

	test = date.substr(5, 2);
	for (size_t i = 0; i < 2; i++)
		if (!std::isdigit(test[i]))
			return false;
	if (std::stoi(test) < 1 || std::stoi(test) > 12)
		return false;
	if (date[7] != '-')
		return false;

	test2 = date.substr(8, 2);
	for (size_t i = 0; i < 2; i++)
		if (!std::isdigit(test[i]))
			return false;
	if (std::stoi(test) < 1 || std::stoi(test) > 31)
		return false;
	if (std::stoi(test2) == 31 && (std::stoi(test) != 1 || std::stoi(test) != 3 || std::stoi(test) != 5 || std::stoi(test) != 7 || std::stoi(test) != 8 || std::stoi(test) != 10 || std::stoi(test) != 12))
		return false;
	else if (std::stoi(test) == 2 && std::stoi(test2) == 29 && std::stoi(date.substr(0, 4)) % 4 != 0)
		return false;

	return true;
}

bool	BitcoinExchange::checkValue(std::string value)
{
	if (!std::isdigit(value[0]))
	{
		if (std::stod(value) < 0)
			std::cerr << "Error: not a positive number => " << value << std::endl;
		else
			std::cerr << "Error: bad input => " << value << std::endl;
		return false;
	}
	for (size_t i = 0; i < value.length(); i++)
		if (!std::isdigit(value[i]) && value[i] != '.')
		{	std::cerr << "Error: bad input => " << value << std::endl; return false;}
	if (!(std::stod(value) >= 0 && std::stod(value) <= 1000))
	{	std::cerr << "Error: number too large => " << value << std::endl; return false;}

	return true;
}

float	BitcoinExchange::closest(std::string date, std::multimap<std::string, std::string> data_map)
{
	std::multimap<std::string, std::string>::iterator data_it = data_map.find(date);

	if (data_map.find(date) != data_map.end() && data_it == data_map.end())
		return std::stof(data_it->second);
	else if (date < data_map.begin()->first)
		return 0;

	return std::stof(data_map.lower_bound(date)->second);
}

void	BitcoinExchange::printWallet(std::ifstream &input_file, std::multimap<std::string, std::string> data_map)
{
	std::string line;

	getline(input_file, line);
	while (!input_file.eof() && getline(input_file, line))
	{
		std::string	date = line.substr(0, line.find(" | "));
		std::string	amount = line.substr(line.find(" | ") + std::string(" | ").length(), line.length() - 1);

		if (checkDate(date) == false)
		{	std::cerr << "Error: bad input => " << date << std::endl; continue;}
		else if (checkValue(amount) == false)
		{	continue;}
		float	value = std::stof(amount) * BitcoinExchange::closest(date, data_map);
		std::cout << date << " => " << amount << " = " << value << std::endl;
	}
}
