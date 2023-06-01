#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	BitcoinExchange bit;
	std::ifstream input;
	std::ifstream data;

	static_cast<void>(argc);
	input.open(argv[1]);
	data.open("data.csv");

	if (input.fail() || data.fail())
	{
		std::cout << "Error: could not open file." << std::endl;
		input.close();
		data.close();
		return (0);
	}
	bit.exchange_bit(input, data);
	input.close();
	data.close();
	return (0);
}
