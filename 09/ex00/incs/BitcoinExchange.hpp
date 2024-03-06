#pragma once
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
	public:
		~BitcoinExchange();

		static int	errorHandling(int argc, char **argv);
		static std::multimap<std::string, std::string>	storeDataMap(std::ifstream &file);
		static void	printWallet(std::ifstream &input_file, std::multimap<std::string, std::string> data_map);
		static bool	checkDate(std::string date);
		static bool	checkValue(std::string value);
		static float	closest(std::string date, std::multimap<std::string, std::string> data_map);
};
