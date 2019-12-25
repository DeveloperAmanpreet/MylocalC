#include <iostream>

int main_basic()
{

	std::cout << "Working of if loop. Ret value of the condition\
		\b\b\b\b\bis printed when the ones that " << std::endl;
	if (-1)
	{
		std::cout << "Ret Value: " << -5 << " (any negative value)" << std::endl;
	}
	int val = 4 == 4;
	int val2 = 4 && 4;
	if (0)
	{
		std::cout << "Ret Value: " << val << " (NULL, 0 value) " << std::endl;
	}
	if (val)
	{
		std::cout << "Ret Value: " << val << " (any Positive value)" << std::endl;
	}
	return 0;
}