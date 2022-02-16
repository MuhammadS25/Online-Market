#include "ArraList.h"
#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
ArraList<T>::ArraList() {
	count = 0;
	size = 5;
	arr = new T[size];
}

template<class T>
int ArraList<T>::length()
{
	return count;
}

template<class T>
void ArraList<T>::append(T val)
{
	if (count == size)
		expand();
	arr[count] = val;
	count++;
}

template<class T>
void ArraList<T>::expand()
{
	size *= 2;
	T* tmp = new T[size];
	for (int i = 0; i < count; i++) {
		tmp[i] = arr[i];
	}
	delete[]arr;
	arr = tmp;
}

template<class T>
void ArraList<T>::display()
{
	assert(!count==0);
	for (int i = 0; i < count; i++) {
		cout << arr[i] << endl;
	}
}

template<class T>
T ArraList<T>::at(int index)
{
	assert(index >= 0 && index < count);
	return arr[index];
}

template<class T>
void ArraList<T>::insertAt(int index, T val)
{
	assert(index >= 0 && index < count);
	if (count == size)
		expand();
	for (int i = count; i > index; i--)
		arr[i] = arr[i - 1];
	arr[index] = val;
	count++;
}

template<class T>
void ArraList<T>::deletAt(int index)
{
	assert(index >= 0 && index < count);
	for (int i = index; i < count - 1; i++)
		arr[i] = arr[i + 1];
	count--;
}

template<class T>
ArraList<T>::~ArraList(void)
{
	delete[]arr;
}
