#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const &elem)
{
	std::cout << elem << std::endl;
}

void printInt(int const &elem)
{
	std::cout << "int : " << elem << std::endl;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "test avec template:" << std::endl;
	iter(intArray, 5, print<int>);

	std::cout << "\n test function:" << std::endl;
	iter(intArray, 5, printInt);

	std::string strArray[] = {"PIW", "piw", "!"};
	std::cout << "\nstring :" << std::endl;
	iter(strArray, 3, print<std::string>);

	return 0;
}
