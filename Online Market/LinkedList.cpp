#include "LinkedList.h"
#include<assert.h>

template<class T>
Node<T>::Node() {
	value = 0;
	next = NULL;
}

template<class T>
Node<T>::Node(T val)
{
	value = val;
	next = NULL;
}

template<class T>
LinkedList<T>::LinkedList() {
	first = last = NULL;
	count = 0;
}

template<class T>
int LinkedList<T>::length()
{
	return count;
}

template<class T>
T LinkedList<T>::at(int index)
{
	assert(index >= 0 && index < count);

	Node<T>* tmp = first;
	for (int i = 0; i < index; i++)
		tmp = tmp->next;
	return tmp->value;
}

template<class T>
void LinkedList<T>::insertAt(int index, T val)
{
	Node<T>* newitem = new Node<T>(val);
	if (index == 0) {
		newitem->next = first;
		first = newitem;
	}
	else {
		Node<T>* tmp = first;
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		newitem->next = tmp->next;
		tmp->next = newitem;
	}
	count++;
}

template<class T>
void LinkedList<T>::append(T val)
{
	Node<T>* newitem = new Node<T>(val);
	if (count == 0)
		first = last = newitem;
	else
	{
		last->next = newitem;
		last = newitem;
	}
	count++;
}

template<class T>
void LinkedList<T>::deleteAt(int index)
{
	Node<T>* tmp = first;
	if (index == 0) {
		first = first->next;
		delete tmp;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		Node<T>* cur = tmp->next;
		tmp->next = cur->next;
		delete cur;
		if (index == count-1)
			last = tmp;
	}
	count--;

}

template<class T>
LinkedList<T>::~LinkedList(void)
{
	first = last = NULL;
	count = 0;
}
