#pragma once

#include <stdexcept>
#include <iostream>

class BadFigure: public std::domain_error
{
	const char* error{};

	public:
		BadFigure(const char* err);

		const char* getError() const;
};
