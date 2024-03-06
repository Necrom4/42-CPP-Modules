#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
	public:
		~ScalarConverter();

		static int			errorHandler(const std::string &str);
		static std::string	whatType(const std::string &str);
		static std::string	convChar(const std::string &str, const std::string &type);
		static std::string	convNum(const std::string &str, const std::string &type);
		static std::string	formatF(const std::string &str, const std::string &type);
		static std::string	formatD(const std::string &str, const std::string &type);

		static void	convert(const std::string &str);
};
