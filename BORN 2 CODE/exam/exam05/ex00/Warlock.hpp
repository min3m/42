#pragma once

#include <iostream>
#include <string>

class Warlock
{
private:
	std::string _name;
	std::string _title;

	Warlock();
	Warlock(const Warlock &src);
	Warlock &operator=(const Warlock &src);

public:
	Warlock(std::string name, std::string title);
	~Warlock();
	const std::string &getName() const;
	const std::string &getTitle() const;
	void setTitle(const std::string &src);
	void introduce() const;
};

