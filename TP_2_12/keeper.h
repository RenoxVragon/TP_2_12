#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Keeper
{
private:
	T* arr;
	int size;
public:
	Keeper();
	Keeper(int _size);
	Keeper(const Keeper<T>& keeper_copy);
	~Keeper();
	void date_sort();
	void set_size(int _size);
	int get_size();
	T& operator[] (int i);
	Keeper<T>& operator += (const T& data);
	Keeper<T>& operator -= (const int j);
	Keeper<T>& operator = (const Keeper<T>& keeper_copy);
};

template <class T>
Keeper<T>::Keeper()
{
	cout << "Constructor default Keeper." << endl;
	this->size = 0;
	this->arr = new T[this->get_size()];
}

template <class T>
Keeper<T>::Keeper(int _size)
{
	cout << "Constructor parameter Keeper." << endl;
	this->size = _size;
	this->arr = new T[this->get_size()];
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

template <class T>
Keeper<T>::Keeper(const Keeper<T>& keeper_copy)
{
	cout << "Constructor copy Keeper." << endl;
	*this = keeper_copy;
}

template <class T>
Keeper<T>& Keeper<T>::operator = (const Keeper<T>& keeper_copy)
{
	if (&keeper_copy == this) return *this;
	delete[] arr;

	size = keeper_copy.size;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
		arr[i] = keeper_copy.arr[i];
	return *this;
}

template <class T>
Keeper<T>::~Keeper()
{
	cout << "Deconstructor Keeper." << endl;
	delete[] arr;
	size = 0;
}

template <class T>
T& Keeper<T>::operator[] (int i)
{
	return arr[i];
}

template <class T>
void Keeper<T>::set_size(int _size)
{
	this->size = _size;
}

template <class T>
int Keeper<T>::get_size()
{
	return this->size;
}

template <typename T>
Keeper<T>& Keeper<T>::operator += (const T& data)
{
	T* tmp = arr;
	size++;
	arr = new T[size];
	for (int i = 0; i < size - 1; i++)
		arr[i] = tmp[i];
	arr[size - 1] = data;
	return *this;
}

template <typename T>
Keeper<T>& Keeper<T>::operator -= (const int j)
{
	if (size > 1)
	{
		T* tmp = new T[size - 1];
		int k = 0;
		for (int i = 0; i < size; i++)
			if (i != j)
				tmp[k++] = arr[i];
		size--;
		arr = tmp;
	}
	else
	{
		size--;
		arr = new T[0];
	}
	return *this;
}


template <typename T>
void Keeper<T>::date_sort()
{
	for (int i = 1; i < size; i++)
		for (int j = 0; j < size - i; j++)
		{
			int date1[3]; for (int i = 0; i < 3; i++)  date1[i] = arr[j].get_date(i);
			int date2[3]; for (int i = 0; i < 3; i++)  date2[i] = arr[j + 1].get_date(i);
			if (date1[2] > date2[2])
			{
				Note temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			else if (date1[1] > date2[1])
			{
				Note temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			else if (date1[0] > date2[0])
			{
				Note temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}