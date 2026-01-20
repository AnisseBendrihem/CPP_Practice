#include <iostream>
#include "Array.hpp"

int main(void)
{
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i] = i;

	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << std::endl;

	Array<int> copy(arr);
	copy[0] = 42;
	std::cout << "arr[0]: " << arr[0] << ", copy[0]: " << copy[0] << std::endl;

	try
	{
		arr[10];
	}
	catch (std::exception &e)
	{
		std::cout << "youre way too far !!" << std::endl;
	}

	return 0;
}
