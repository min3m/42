#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <class T>
class Array
{
private:
	T *_array;
	unsigned int _length;

public:
	Array()
	{
		_array = NULL;
		_length = 0;
	}
	Array(const unsigned int &length)
		:_length(length)
	{
		_array = new T[_length];
		for (unsigned int i = 0; i < _length; i++)
			_array[i] = 0;
	}
	Array(const Array &source)
	{
		(*this) = source;
	}
	Array &operator = (const Array &source)
	{
		if (this == &source)
			return (*this);
		delete [] _array;
		_length = source._length;
		_array = new T[_length];
		for (unsigned int i = 0; i < _length; i++)
			_array[i] = source._array[i];
		return (*this);
	}
	T &operator [] (const int &index)
	{
		if (index < 0 || static_cast<unsigned int>(index) >= _length)
			throw OutOfRangeException();
		return (_array[index]);
	}
	~Array()
	{
		delete [] _array;
	}
	unsigned int size()
	{
		return (_length);
	}
	class OutOfRangeException : public std::exception
	{
	public:
		virtual const char * what() const throw()
		{
			return ("Index is out of range");
		}
	};
};

#endif
