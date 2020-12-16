#pragma once

#include<iostream>
using namespace std;

template<class Elemtype>
class SqQueueDishesManage
{
protected:
	int front, rear;
	int maxSize;
	int count;
	Elemtype* elems;
public:
	SqQueueDishesManage(int Size);
	virtual ~SqQueueDishesManage();
	int Length() const;
	bool Empty() const;
	void Clear();
	void Traverse(void (*visit)(const Elemtype e)) const;
	bool InQueue(Elemtype& e);
	bool GetHead(Elemtype& e);
	bool OutQueue(Elemtype& e);
	SqQueueDishesManage(const SqQueueDishesManage<Elemtype>& copy);
	SqQueueDishesManage<Elemtype>& operator = (const SqQueueDishesManage<Elemtype>& copy);
};

template<class Elemtype>
SqQueueDishesManage<Elemtype>::SqQueueDishesManage(int Size)
{
	maxSize = Size;
	front = rear = 0;
	count = 0;
	elems = new Elemtype[maxSize];
}

template<class Elemtype>
SqQueueDishesManage<Elemtype>::~SqQueueDishesManage()
{
	Clear();
	delete[] elems;
}

template<class Elemtype>
int SqQueueDishesManage<Elemtype>::Length() const
{
	return count;
}

template<class Elemtype>
bool SqQueueDishesManage<Elemtype>::Empty() const
{
	return count == 0;
}

template<class Elemtype>
void SqQueueDishesManage<Elemtype>::Clear()
{
	count = 0;
	front = rear = 0;
}

template<class Elemtype>
void SqQueueDishesManage<Elemtype>::Traverse(void (*visit)(const Elemtype e)) const
{
	for (int pos = front; pos != rear; pos = (pos + 1) % maxSize) {
		(*visit)(elems[pos]);
	}
}

template<class Elemtype>
bool SqQueueDishesManage<Elemtype>::InQueue(Elemtype& e)
{
	if (count == maxSize) {
		cout << "InQueueÊ§°Ü" << endl;
		return false;
	}
	else {
		count++;
		elems[rear] = e;
		rear = (rear + 1) % maxSize;
		return true;
	}
}

template<class Elemtype>
bool SqQueueDishesManage<Elemtype>::GetHead(Elemtype& e)
{
	if (!Empty()) {
		e = elems[front];
		return true;
	}
	return false;
}

template<class Elemtype>
bool SqQueueDishesManage<Elemtype>::OutQueue(Elemtype& e)
{
	if (!Empty()) {
		count--;
		e = elems[front];
		front = (front + 1) % maxSize;
		return true;
	}
	else {
		cout << "OutQueueÊ§°Ü" << endl;
		return false;
	}
}

template<class Elemtype>
SqQueueDishesManage<Elemtype>::SqQueueDishesManage(const SqQueueDishesManage<Elemtype>& copy)
{
	count = copy.count;
	front = copy.front;
	rear = copy.rear;
	maxSize = copy.maxSize;
	elems = new Elemtype[maxSize];
	for (int pos = front; pos != rear; pos = (pos + 1) % maxSize) elems[pos] = copy.elems[pos];
}

template<class Elemtype>
SqQueueDishesManage<Elemtype>& SqQueueDishesManage<Elemtype>:: operator= (const SqQueueDishesManage<Elemtype>& copy)
{
	if (this != &copy) {
		count = copy.count;
		front = copy.front;
		rear = copy.rear;
		maxSize = copy.maxSize;
		delete[] elems;
		elems = new Elemtype[maxSize];
		for (int pos = front; pos != rear; pos = (pos + 1) % maxSize) elems[pos] = copy.elems[pos];
	}
	return *this;
}



