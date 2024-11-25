#include "Figure.h"

#include <iostream>

Figure::Figure(int sides, const std::string& get_name): sides_count{sides}, name{get_name}{};

Figure::Figure(): name{"Фигура"}{};

int Figure::get_sides_count() const {return sides_count;}
const std::string& Figure::get_name() const {return name;}

void Figure::print_info() const {std::cout << name << "\n\n";}
