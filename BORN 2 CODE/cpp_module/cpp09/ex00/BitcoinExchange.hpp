#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, float> upbit;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &source);
	BitcoinExchange &operator = (const BitcoinExchange &source);
	~BitcoinExchange();
	void exchange_bit(std::ifstream &input, std::ifstream &data);
	void check_valid();
};

#endif
