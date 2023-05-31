#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Welcome to Upbit!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
{
	*this = source;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &source)
{
	*this = source;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Upbit system is over!" << std::endl;
}

void BitcoinExchange::exchange_bit(std::ifstream &input, std::ifstream &data)
{
}

void BitcoinExchange::check_valid()
{
}
