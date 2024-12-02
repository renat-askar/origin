#include "BadFigure.h"

BadFigure::BadFigure(const char* err): domain_error{"Ошибка создания фигуры."}, error{err}{}

const char* BadFigure::getError() const
{
	return error;
}
