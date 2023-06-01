#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Welcome to Upbit!\n\n" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
{
	*this = source;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &source)
{
	this->upbit = source.upbit;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "\n\nUpbit system is over!" << std::endl;
}

void BitcoinExchange::exchange_bit(std::ifstream &input, std::ifstream &data)
{
	std::string line;
	float result;

	read_data(data);
	std::getline(input, line);
	while (std::getline(input, line))
	{
		switch (check_valid(line, result))
		{
		case BadInput:
			std::cout << "Error: bad input => " << line << std::endl;
			break;
		case Notpositive:
			std::cout << "Error: not a positive number." << std::endl;
			break;
		case TooLagre:
			std::cout << "Error: too large a number." << std::endl;
			break;
		case NotValidDate:
			std::cout << "Error: not a valid date." << std::endl;
			break;
		default:
			std::cout << line.substr(0, 10) << " => " << line.substr(13) << " = " << result << std::endl;
			break;
		}
	}
}

void BitcoinExchange::read_data(std::ifstream &data)
{
	int date;
	float rate = 0.0;
	std::string line;
	std::map<int, float>::iterator iter;

	while (std::getline(data, line))
	{
		date = std::atoi(line.substr(0, 4).c_str()) * 10000;
		date += std::atoi(line.substr(5, 2).c_str()) * 100;
		date += std::atoi(line.substr(8, 2).c_str());
		std::stringstream ratio(line.substr(11));
		ratio >> rate;
		this->upbit.insert(std::pair<int, float>(date, rate));
	}
}

int BitcoinExchange::check_valid(const std::string &line, float &result)
{
	int year;
	int month;
	int day;
	int date;
	float value;

	if (line.size() < 14)
		return (BadInput);
	if (!isNum(line.substr(0, 4)) || !isNum(line.substr(5, 2)) || !isNum(line.substr(8, 2)))
		return (BadInput);
	if (!isFloat(line.substr(13)))
		return (BadInput);
	std::stringstream ss(line.substr(13));
	ss >> value;
	if (value > 1000)
		return (TooLagre);
	else if (value < 0)
		return (Notpositive);
	year = std::atoi(line.substr(0, 4).c_str());
	month = std::atoi(line.substr(5, 2).c_str());
	day = std::atoi(line.substr(8, 2).c_str());
	date = year * 10000 + month * 100 + day;
	if (!check_date(year, month, day, date))
		return (NotValidDate);
	if (upbit.find(date) != upbit.end())
		result = upbit[date] * value;
	else
		result = upbit[find_date(date)] * value;
	return (Valid);
}

bool BitcoinExchange::isNum(const std::string &line)
{
	for(size_t i = 0; i < line.size(); i++)
	{
		if (!std::isdigit(line[i]))
			return (false);
	}
	return (true);
}

bool BitcoinExchange::isFloat(const std::string &line)
{
	if (std::count(line.begin(), line.end() , '.') > 1)
		return (false);
	if (std::count(line.begin(), line.end() , '-') > 1)
		return (false);
	for(size_t i = 0; i < line.size(); i++)
	{
		if (!std::isdigit(line[i]) && line[i] != '.' && line[i] != '-')
			return (false);
	}
	return (true);
}

int BitcoinExchange::find_date(int &date)
{
	std::map<int, float>::iterator iter;

	for (iter = upbit.begin(); iter != upbit.end(); iter++)
	{
		if (iter->first < date && (iter++) != upbit.end() && iter->first > date)
			return ((--iter)->first);
		--iter;
	}
	return (0);
}

bool BitcoinExchange::check_date(int &year, int &month, int &day, int &date)
{
	std::map<int, float>::iterator iter = upbit.begin();

	if (iter->first > date)
		return (false);
	if (month == 0 || month > 12 || day == 0 || day > 31)
		return (false);
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (false);
	}
	else if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (day > 29)
				return (false);
		}
		else
		{
			if(day > 28)
				return (false);
		}
	}
	else
	{
		if (day > 31)
			return (false);
	}
	return (true);
}
