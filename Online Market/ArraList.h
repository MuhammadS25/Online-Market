#pragma once
template<class T>
class ArraList
{
	T* arr;
	int count, size;
public:
	ArraList(void);
	int length();
	void append(T value);
	void expand();
	void display();
	T at(int index);
	void insertAt(int index, T value);
	void deletAt(int index);
	~ArraList(void);
};

