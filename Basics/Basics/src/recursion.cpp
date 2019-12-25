#include <recursion.h>
#include <logger.h>

std::uint64_t headRecursion(std::uint64_t n)
{
	LOGGER_INFO("Start");
	if (n == 2)
	{
		LOGGER_INFO("End");
		return 2;
	}
	else
	{
		LOGGER_INFO("End");
		return n + headRecursion(n - 1);
	}
}

void tailRecursion(std::uint64_t n, std::uint64_t& result)
{
	LOGGER_INFO("Start");
	if (n == 2)
		result = result + 2;
	else
		result += (result - 1);

	LOGGER_INFO("End");
	return tailRecursion(n - 1, result);

	
}

//'t' for tail recursion and 'h' for head recursion
int main_recursion(const char& choice)
{
	LOGGER_INFO("Start");
	
	if ('t' == choice)
	{
		std::uint64_t result;
		tailRecursion(999999, result);
		std::cout << result << std::endl;
	}
	else if ('h' == choice )
	{
		std::cout << headRecursion(999999) << std::endl;
	}
	
	LOGGER_INFO("End");
	return 0;
}