#include <cstdlib>
#include <iostream>
#include "Array.h"
using namespace std;

template <class T>
class GrowableArray : public Array<T>{
	public :
		GrowableArray(int size) : Array<T>(size){}
		~GrowableArray(){} 
		void growarray ();
		T& operator[] (int i);
};

template <class T>
void GrowableArray<T>::growarray()
{
	T *tmp;
	tmp = new T[this->len * 2];
	for (int i = 0; i < this->len; i++)
	{
		tmp[i] = this->data[i];
	}
	for (int i = this->len; i < this->len * 2; i++)
	{
		tmp[i] = 0;
	}
	delete [] this->data;
	this->len = this->len * 2;
	this->data = new T[this->len];
	for (int i = 0; i < this->len; i++)
	{
		this->data[i] = tmp[i];
	}
}

template <class T>
T& GrowableArray<T>::operator[] (int i)
{
	static T tmp;
	if (i >= 0 && i < this->len)
	{
		return this->data[i];
	}
	else if (i >= this->len)
	{
		growarray();
		return this->data[i];
	}
	else
	{
		cout << "c\n";
		cout << "Array bound error!" << endl;
		return tmp;
	}
}

