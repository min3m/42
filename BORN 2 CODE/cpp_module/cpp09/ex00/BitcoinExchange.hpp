#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define BadInput 0
#define Notpositive 1
#define TooLagre 2
#define NotValidDate 3
#define Valid 4

class BitcoinExchange
{
private:
	std::map<int, float> upbit;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &source);
	BitcoinExchange &operator = (const BitcoinExchange &source);
	~BitcoinExchange();
	void exchange_bit(std::ifstream &input, std::ifstream &data);
	void read_data(std::ifstream &data);
	int check_valid(const std::string &line, float &result);
	bool isNum(const std::string &line);
	bool isFloat(const std::string &line);
	int find_date(int &date);
	bool check_date(int &year, int &month, int &day, int &date);
};

#endif
