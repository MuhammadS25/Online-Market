#pragma once
template<class T>
class Node {
public:
	T value;
	Node<T>* next;
	Node(void);
	Node(T val);
};
template<class T>
class LinkedList
{
	int count;
	Node<T>* first;
	Node<T>* last;
public:
	LinkedList(void);
	int length();
	T at(int);
	void insertAt(int index, T val);
	void append(T val);
	void deleteAt(int index);
	~LinkedList(void);
};

