#include "ScalarConverter.hpp"

// constructeur coni=onique inutiles--------------------------------------------------------------------
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

// lecture  ---------------------------------------------------------------------------------
bool ScalarConverter::isChar(const std::string &str)
{
	return (str.length() == 1 && !std::isdigit(str[0]));
}
bool ScalarConverter::isInt(const std::string &str)
{
	if (str.empty())
		return false;
	size_t i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (i == str.length())
		return false;
	for (;i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}
bool ScalarConverter::isFloat(const std::string &str)
{
	if (str.empty())
		return false;
	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
		return true;
	if (str[str.length() - 1] != 'f')
		return false;
	
	std::string tmp = str.substr(0, str.length() - 1);
	if (tmp.empty())
		return false;
	
	size_t i = 0;
	bool hasDot = false;
	
	if (tmp[0] == '-' || tmp[0] == '+')
		i++;
	if (i == tmp.length())
		return false;
	
	for (; i < tmp.length(); i++)
	{
		if (tmp[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(tmp[i]))
			return false;
	}
	return hasDot;
}
bool ScalarConverter::isDouble(const std::string &str)
{
	if (str.empty())
		return false;
	if (str == "-inf" || str == "+inf" || str == "nan" || str == "inf")
		return true;
	
	size_t i = 0;
	bool hasDot = false;
	
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (i == str.length())
		return false;
	
	for (; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	return hasDot;
}
bool ScalarConverter::isPseudoLiteral(const std::string &str)
{
	return (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff" ||
			str == "-inf" || str == "+inf" || str == "nan" || str == "inf");
}

// Convertion --------------------------------------------------------------------------------------
void ScalarConverter::convertFromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}
void ScalarConverter::convertFromInt(int i)
{
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	
	std::cout << "int: " << i << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}
void ScalarConverter::convertFromFloat(float f)
{
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (f < 32 || f >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	
	if (std::isnan(f) || std::isinf(f) || f < static_cast<float>(std::numeric_limits<int>::min()) || 
		f > static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}
void ScalarConverter::convertFromDouble(double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (d < 32 || d >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	
	if (std::isnan(d) || std::isinf(d) || d < static_cast<double>(std::numeric_limits<int>::min()) || 
		d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	
	if (std::isinf(d) && d > 0)
		std::cout << "float: inff" << std::endl;
	else if (std::isinf(d) && d < 0)
		std::cout << "float: -inff" << std::endl;
	else if (std::isnan(d))
		std::cout << "float: nanf" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
// fonction principale -----------------------------------------------------------------------------------
void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "Error: empty input" << std::endl;
		return;
	}


	if (isChar(literal))
	{
		convertFromChar(literal[0]);
		return;
	}

	if (isPseudoLiteral(literal))
	{
		double d;
		if (literal == "nan" || literal == "nanf")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff")
			d = std::numeric_limits<double>::infinity();
		else
			d = -std::numeric_limits<double>::infinity();
		convertFromDouble(d);
		return;
	}

	if (isInt(literal))
	{
		long l = std::strtol(literal.c_str(), NULL, 10);
		if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		convertFromInt(static_cast<int>(l));
		return;
	}

	if (isFloat(literal))
	{
		float f = std::strtof(literal.c_str(), NULL);
		convertFromFloat(f);
		return;
	}

	if (isDouble(literal))
	{
		double d = std::strtod(literal.c_str(), NULL);
		convertFromDouble(d);
		return;
	}

	std::cout << "Error: invalid input" << std::endl;
}
