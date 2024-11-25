#include "calculator.h"

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul(int num1, int num2)
{
	return num1 * num2;
}

int divi(int num1, int num2)
{
	return num1 / num2;
}

int pow(int num, int exp)
{
	for(size_t ex{1}; ex < exp; ++ex)
	{
		num *= num;
	}
	return num;
}
