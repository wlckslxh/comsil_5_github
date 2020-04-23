#ifndef __ARRAY__
#define __ARRAY__

#include <cstdlib>
#include<iostream>
using namespace std;

template <class T>
class Array{
	protected:
		T *data;
		int len;
	public:
			Array(int size);
			~Array();

			int length() const;

			T& operator[](int i);
			T operator[](int i)const;

			void print();
};

template <class T>
Array<T>::Array(int size)
{
	if (size < 0)
	{

	}
	else
	{
		len = size;
		data = new T[len];
	}
}

template <class T>
Array<T>::~Array()
{
	delete[] data;
}

template <class T>
int Array<T>::length() const
{
	return len;
}

template <class T>
T& Array<T>::operator[](int i)
{
	static T tmp;

	if (i >= 0 && i < len)
	{
		T &add = data[i];
		return add;
	}
	else
	{
		cout << "Array bound error!\n";
		return tmp;
	}
}

template <class T>
T Array<T>::operator[](int i) const
{
	if (i >= 0 && i < len)
	{
		return data[i];
	}
	else
	{
		cout << "Array bound error!\n";
		return 0;
	}
}

template <class T>
void Array<T>::print()
{
	int i;
	cout << "[";
	for (int i = 0; i < len; i++)
	{
		cout << data[i];
		if (i != len - 1)
		{
			cout << " ";
		}
	}
	cout << "]";

	cout << endl;
}
#endif
