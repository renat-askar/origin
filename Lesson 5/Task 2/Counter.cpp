#include "Counter.h"

Counter::Counter() = default;

Counter::Counter(int initial): count{initial}{}

const int Counter::get() const
{
	return count;
}

void Counter::increase()
{
	++count;
}

void Counter::decrease()
{
	--count;
}
