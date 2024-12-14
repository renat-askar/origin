#pragma once

#ifdef FIGURE_EXPORTS
	#define FIGURE_API __declspec(dllexport)
#else
	#define FIGURE_API __declspec(dllimport)
#endif

#include <string>

class Figure
{
	int sides_count{};
	std::string name{};

	protected:
		Figure(int sides, const std::string& get_name);

	public:
		FIGURE_API Figure();

		int get_sides_count() const;
		const std::string& get_name() const;

		FIGURE_API virtual void print_info() const;
};
