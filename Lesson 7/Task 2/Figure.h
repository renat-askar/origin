#pragma once

#include <string>

class Figure
{
	int sides_count{};
	std::string name{};

protected:
	Figure(int sides, const std::string& get_name);

public:
	Figure();

	int get_sides_count() const;
	const std::string& get_name() const;

	virtual void print_info() const;
};
