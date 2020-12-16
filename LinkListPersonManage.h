#pragma once

#include<iostream>
using namespace std;
//普通结点类模板
template<class elemType>
struct Node
{
	elemType data;
	Node<elemType>* next;

	Node();
	Node(elemType item, Node<elemType>* link = NULL);
};

template<class elemType>
Node<elemType>::Node()
{
	next = NULL;
}

template<class elemType>
Node<elemType>::Node(elemType item, Node<elemType>* link)
{
	data = item;
	next = link;
}


template<class elemType>
class LinkListPersonManage
{
protected:
	Node<elemType>* head;
	//返回position位置的元素的指针
	Node<elemType>* GetElemPtr(int position) const;
	//void PrintHelp(const elemType& e)const;

public:
	LinkListPersonManage();
	virtual ~LinkListPersonManage();
	int Length() const;
	bool Empty() const;
	void Clear();
	void Traverse() const;
	bool GetElem(int position, elemType& e) const;
	bool SetElem(int position, const elemType& e);
	bool Delete(int position, elemType& e);
	bool Insert(int position, const elemType& e);
	LinkListPersonManage(const LinkListPersonManage<elemType>& copy);
	LinkListPersonManage<elemType>& operator = (const LinkListPersonManage<elemType>& copy);
};

template<class elemType>
Node<elemType>* LinkListPersonManage<elemType>::GetElemPtr(int position) const
{
	Node<elemType>* p = head;
	int pos = 0;
	while (p->next != NULL && pos < position) {
		p = p->next;
		pos++;
	}
	if (p != NULL && pos == position) {
		return p;
	}
	else {
		return NULL;
	}
}

template<class elemType>
LinkListPersonManage<elemType>::LinkListPersonManage()
{
	head = new Node<elemType>;
	head->next = NULL;
}

template<class elemType>
LinkListPersonManage<elemType>::~LinkListPersonManage()
{
	delete head;
}

template<class elemType>
int LinkListPersonManage<elemType>::Length() const
{
	Node<elemType>* p = head->next;
	int len = 0;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

template<class elemType>
bool LinkListPersonManage<elemType>::Empty() const
{
	return Length() == 0 ? true : false;
}

template<class elemType>
void LinkListPersonManage<elemType>::Clear()
{
	if (!Empty()) {
		Node<elemType> tmpPtr = head->next;
		Node<elemType> tempPtr = tmpPtr;
		while (tmpPtr != NULL) {
			tmpPtr = tempPtr->next;
			delete tempPtr;
			tempPtr = tmpPtr;
		}
	}
}


template<class elemType>
bool LinkListPersonManage<elemType>::Insert(int position, const elemType& e)
{
	if (position < 1 || position > Length() + 1) {
		cout << "Insert操作链表越界" << endl;
		return false;
	}
	Node<elemType>* tmpPtr = GetElemPtr(position - 1);
	Node<elemType>* newPtr = new Node<elemType>(e, tmpPtr->next);
	/*newPtr->data = e;

	newPtr->next = proPtr->next;*/
	tmpPtr->next = newPtr;
	return true;
}

template<class elemType>
bool LinkListPersonManage<elemType>::Delete(int position, elemType& e)
{
	if (position < 1 || position > Length()) {
		cout << "Delete操作链表越界" << endl;
		return false;
	}
	Node<elemType>* tmpPtr = GetElemPtr(position - 1);  //获取要删除的元素的前一个位置
	Node<elemType>* nextPtr = tmpPtr->next;
	if (tmpPtr->next == NULL) tmpPtr->next = NULL;
	else {
		e = tmpPtr->next->data;  //将删除的数值保存
		tmpPtr->next = tmpPtr->next->next;
	}
	delete nextPtr; //释放
	return true;
}

template<class elemType>
void LinkListPersonManage<elemType>::Traverse() const
{
	if (Empty()) {
		cout << "当前为空表" << endl;
	}
	else {
		for (Node<elemType>* tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next) {
			(tmpPtr->data).ViewInformation();
		}
		cout << endl;
	}
}

template<class elemType>
bool LinkListPersonManage<elemType>::GetElem(int position, elemType& e) const
{
	if (position < 1 || position > Length()) {
		cout << "GetElem操作链表越界" << endl;
		return false;
	}
	Node<elemType>* tmpPtr = GetElemPtr(position);
	e = tmpPtr->data;
	return true;
}

template<class elemType>
bool LinkListPersonManage<elemType>::SetElem(int position, const elemType& e)
{
	if (position < 1 || position > Length()) {
		cout << "SetElem操作链表越界" << endl;
		return false;
	}
	Node<elemType>* tmpPtr = GetElemPtr(position);
	tmpPtr->data = e;
	return true;
}

template<class elemType>
LinkListPersonManage<elemType>::LinkListPersonManage(const LinkListPersonManage<elemType>& copy)
{
	Node<elemType>* tmpPtr = copy.head->next;
	Node<elemType>* newPtr = head;
	while (tmpPtr != NULL) {
		newPtr->next = tmpPtr;
		tmpPtr = tmpPtr->next;
		newPtr = newPtr->next;
	}
}

template<class elemType>
LinkListPersonManage<elemType>& LinkListPersonManage<elemType>::operator = (const LinkListPersonManage<elemType>& copy)
{
	if (&copy != this) {
		if (head->next != NULL) Clear();
		Node<elemType>* tmpPtr = copy.head->next;
		Node<elemType>* newPtr = head;
		while (tmpPtr != NULL) {
			newPtr->next = tmpPtr;
			tmpPtr = tmpPtr->next;
			newPtr = newPtr->next;
		}
	}
	return *this;
}

