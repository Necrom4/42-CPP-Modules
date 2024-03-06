#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = copy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter assignement operator called" << std::endl;
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

int		ScalarConverter::errorHandler(const std::string &str)
{
	int	i;
	int nb_mins = 0;
	int nb_fs = 0;
	int nb_dots = 0;

	if (!str[0])
		return 0;
	for (std::string::size_type i = 0; i < str.length(); i++)
		if (str[i] == '-')
			nb_mins++;
	if (nb_mins > 1)
		return 0;
	else if (nb_mins == 1 && str[0] != '-')
		return 0;
	for (std::string::size_type i = 0; i < str.length(); i++)
		if (str[i] == 'f')
			nb_fs++;
	if (nb_fs > 1 && str.compare("-inff") && str.compare("+inff"))
		return 0;
	else if (nb_fs == 1 && str[str.length() - 1] != 'f')
		return 0;
	else if (str.length() > 1 && nb_fs == 1 && str[str.length() - 1] == 'f' && !std::isdigit(str[str.length() - 2]) && str.compare("nanf") && str.compare("+inf") && str.compare("-inf"))
		return 0;
	for (std::string::size_type i = 0; i < str.length(); i++)
		if (str[i] == '.')
			nb_dots++;
	if (nb_dots > 1)
		return 0;
	else if (str.length() > 1 && nb_dots == 1 && (str[0] == '.' || str[str.length() - 1] == '.' || (nb_mins == 1 && str[1] == '.') || (str[str.length() - 2] == '.' && str[str.length() - 1] == 'f')))
		return 0;
	if (str.length() > 1 && (str.compare("-inf") && str.compare("+inf") && str.compare("nan") && str.compare("-inff") && str.compare("+inff") && str.compare("nanf")))
	{
		i = -1;
		while (str[++i] && (std::isdigit(str[i]) || str[i] == '-' || str[i] == '.' || str[i] == 'f'));
		if (static_cast<std::string::size_type>(i) != str.length())
			return 0;
	}
	return 1;
}

std::string	ScalarConverter::whatType(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return "CHAR";
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan") || !str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return "IMP";
	if (std::stold(str) >= static_cast<long double>(1.7976931348623158e+308))
		return "GIGA_DOUBLE";
	if (std::stod(str) >= static_cast<float>(3.402823466e+38))
		return "GIGA_FLOAT";
	if ((std::stod(str) >= 2147483647 || std::stod(str) <= -2147483648))
		return "GIGA_INT";
	for (std::string::size_type i = 0; i < str.length(); i++)
		if (str[i] == '.')
		{
			if (str[str.length() - 1] == 'f')
				return "FLOAT";
			else
				return "DOUBLE";
		}
	return "INT";
}

std::string	ScalarConverter::convChar(const std::string &str, const std::string &type)
{
	if (type == "CHAR" && std::isprint(str[0]))
		return str;
	else if (type == "CHAR" && !std::isprint(str[0]))
		return "Non displayable";
	else if ((type == "INT" || type == "FLOAT" || type == "DOUBLE") && (std::stod(str) == std::stoi(str)) && std::stoll(str) >= 32 && std::stoll(str) <= 126)
		return std::string(1, static_cast<char>(std::stoi(str)));
	else if (type == "IMP" || std::stold(str) < 0 || std::stold(str) > 127)
		return "Impossible";
	return "Non displayable";
}

std::string	ScalarConverter::convNum(const std::string &str, const std::string &type)
{
	if (type == "CHAR")
		return std::to_string(static_cast<int>(str[0]));
	else if (type == "INT" || type == "FLOAT" || type == "DOUBLE" || type == "IMP" || type == "GIGA_INT" || type == "GIGA_FLOAT" || type == "GIGA_DOUBLE")
		return str;
	return "Impossible";
}

std::string ScalarConverter::formatF(const std::string &str, const std::string &type)
{
	if (type == "CHAR")
	{
		if (static_cast<float>(str[0]) == static_cast<int>(str[0]) && static_cast<float>(str[0]) < 1000000 && static_cast<float>(str[0]) > -1000000)
			return ".0f";
		return "f";
	}
	else if (type != "IMP")
	{
		if (type != "GIGA_INT" && std::stof(str) == std::stoi(str) && std::stof(str) < 1000000 && std::stof(str) > -1000000)
			return ".0f";
		return "f";
	}
	else if (str.length() > 1 && str[str.length() - 2] != 'f')
		return "f";
	return "f";
}

std::string ScalarConverter::formatD(const std::string &str, const std::string &type)
{
	if (type == "CHAR")
	{
		if (static_cast<double>(str[0]) == static_cast<int>(str[0]) && static_cast<double>(str[0]) < 1000000 && static_cast<double>(str[0]) > -1000000)
			return ".0";
	}
	else if (type != "IMP" && type != "GIGA_INT" && type != "GIGA_FLOAT")
		if (std::stod(str) == std::stoi(str) && std::stod(str) < 1000000 && std::stod(str) > -1000000)
			return ".0";
	return "";
}

void	ScalarConverter::convert(const std::string &str)
{
	std::string	type;

	if (!errorHandler(str))
	{
		std::cout << "char: Impossible" << std::endl
				  << "int: Impossible" << std::endl
				  << "float: Impossible" << std::endl
				  << "double: Impossible" << std::endl;
		return;
	}
	type = whatType(str);
	std::cout << "char: " << convChar(str, type) << std::endl;
	if (type != "IMP" && type != "GIGA_INT" && type != "GIGA_FLOAT" && type != "GIGA_DOUBLE")
		std::cout << "int: " << std::stoi(convNum(str, type)) << std::endl;
	else
		std::cout << "int: " << "Impossible" << std::endl;
	if (type != "GIGA_FLOAT" && type != "GIGA_DOUBLE")
		std::cout << "float: " << std::stof(convNum(str, type)) << formatF(str, type) << std::endl;
	else
		std::cout << "float: " << "Impossible" << std::endl;
	if (type != "GIGA_DOUBLE")
		std::cout << "double: " << std::stod(convNum(str, type)) << formatD(str, type) << std::endl;
	else
		std::cout << "double: " << "Impossible" << std::endl;
}
