#pragma once
#include<iostream>
using namespace std;

template<class elemType>
class SqDishManage
{
protected:
	int count;
	int maxSize;
	elemType* elems;


public:
	SqDishManage();
	virtual ~SqDishManage();
	int Length() const;
	bool Empty() const;
	void Clear();
	bool Traverse(string name, int& position) const;
	//bool BinarySearch() const; //二分查找菜品
	bool GetElem(int position, elemType& e) const;
	bool SetElem(int position, elemType& e);
	bool Delete(int position, elemType& e);
	bool Insert(int position, elemType& e);
	SqDishManage(const SqDishManage<elemType>& copy);
	SqDishManage<elemType>& operator = (const SqDishManage<elemType>& copy);
};

const int MAXSIZE = 500;


template<class elemType>
SqDishManage<elemType>::SqDishManage()
{
	count = 0;
	maxSize = MAXSIZE;
	elems = new elemType[maxSize];
}

template<class elemType>
SqDishManage<elemType>::~SqDishManage()
{
	delete[] elems;
}

/*template<class elemType>
void SqDishManage<elemType>::SqList_Sort() const
{
	//冒泡排序
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (elems[i] > elems[j + 1]) swap(elems[j], elems[j + 1]);
		}
	}
}*/

template<class elemType>
int SqDishManage<elemType>::Length() const
{
	return count;
}

template<class elemType>
bool SqDishManage<elemType>::Empty() const
{
	return count == 0;
}

template<class elemType>
void SqDishManage<elemType>::Clear()
{
	count = 0;
}

// 两种输出格式：1 带换行 0 不换行
template<class elemType>
bool SqDishManage<elemType>::Traverse(string name, int& position) const
{
	for (int i = 0; i < Length(); i++) {
		if (elems[i].getdishName() == name) {
			position = i;
			return true;
		}
	}
	return false;
}

template<class elemType>
bool SqDishManage<elemType>::GetElem(int position, elemType& e) const
{
	if (position < 1 || position > count) {
		cout << "数组越界，请检查数据是否正确！" << endl;
		return false;
	}
	else {
		e = elems[position - 1];
		return true;
	}
}

template<class elemType>
bool SqDishManage<elemType>::SetElem(int position, elemType& e)
{
	if (position < 1 || position > count) {
		cout << "数组越界，请检查数据是否正确！" << endl;
		return false;
	}
	else {
		elems[position - 1] = e;
		return true;
	}
}

template<class elemType>
bool SqDishManage<elemType>::Delete(int position, elemType& e)
{
	if (position < 1 || position > count) {
		cout << "数组越界，请检查数据是否正确！" << endl;
		return false;
	}
	else {
		e = elems[position - 1];  //GetElem(position, e);
		for (int pos = position; pos <= Length(); pos++) {
			elems[pos - 1] = elems[pos];
		}
		count--;
	}
	return true;
}

template<class elemType>
bool SqDishManage<elemType>::Insert(int position, elemType& e)
{
	if (count == maxSize) return false;
	else if (position < 1 || position > Length() + 1) {
		cout << "数组越界，请检查数据是否正确！" << endl;
		return false;
	}
	else {
		for (int pos = Length(); pos >= position; pos--) {
			elems[pos] = elems[pos - 1];
		}
		elems[position - 1] = e;
		count++;
		return true;
	}
}

template<class elemType>
SqDishManage<elemType>::SqDishManage(const SqDishManage<elemType>& copy)
{
	maxSize = copy.maxSize;
	elems = new elemType[maxSize];
	count = copy.count;

	for (int i = 0; i < copy.count; i++) {
		elems[i] = copy.elems[i];
	}
}

template<class elemType>
SqDishManage<elemType>& SqDishManage<elemType>::operator = (const SqDishManage<elemType>& copy)
{
	if (&copy != this) {
		maxSize = copy.maxSize;
		if (elems != NULL) delete[] elems;
		elems = new elemType[maxSize];
		count = copy.count;

		for (int i = 0; i < copy.count; i++) {
			elems[i] = copy.elems[i];
		}
	}
	return *this;
}
