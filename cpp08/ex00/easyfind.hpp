#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
#include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "not found !!";
		}
};

template <typename T>
int easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
        if (it != container.end()) 
		{
            std::cout << "There is it !! : ";
            return value;
        }
		throw NotFoundException();
}

template <typename T>
int easyfind(T& container, int value) 
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) 
	{
        if ( *it == value ) 
		{
            std::cout << "There is it !! : ";
            return value;
        }
    }
    throw NotFoundException();
}

#endif
