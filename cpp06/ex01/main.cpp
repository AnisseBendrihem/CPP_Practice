#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "Test";
	data.value = 3.14;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "Original: " << &data << std::endl;
	std::cout << "Deserialized: " << ptr << std::endl;
	if (ptr == &data)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;

	return 0;
}
