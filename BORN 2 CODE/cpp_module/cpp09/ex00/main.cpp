#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange bit;
	std::ifstream input;
	std::ifstream data;

	input.open(argv[1]);
	data.open("data.csv");

	if (input.fail() || data.fail())
		std::cout << "Error: could not open file." << std::endl;
	bit.exchange_bit(input, data);
	return (0);
}
