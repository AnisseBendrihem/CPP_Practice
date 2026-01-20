#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
	T *_data;
	unsigned int _size;

public:
	Array() : _data(NULL), _size(0) {}
	Array(unsigned int n) : _data(new T[n]()), _size(n) {}
	Array(const Array &other) : _data(NULL), _size(0)
	{
		if (other._size > 0)
		{
			_data = new T[other._size];
			_size = other._size;
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
	}
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			if (_data != NULL)
				delete[] _data;
			_data = NULL;
			_size = 0;
			if (other._size > 0)
			{
				_data = new T[other._size];
				_size = other._size;
				for (unsigned int i = 0; i < _size; ++i)
					_data[i] = other._data[i];
			}
		}
		return *this;
	}
	~Array()
	{
		if (_data != NULL)
			delete[] _data;
	}

	T &operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::exception();
		return _data[index];
	}

	const T &operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::exception();
		return _data[index];
	}

	// Size member function
	unsigned int size() const
	{
		return _size;
	}
};

#endif