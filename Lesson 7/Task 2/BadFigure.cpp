#include "BadFigure.h"

BadFigure::BadFigure(const char* err): domain_error{"������ �������� ������."}, error{err}{}

const char* BadFigure::getError() const
{
	return error;
}
