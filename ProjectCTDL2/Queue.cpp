
#include "Queue.h"

#include "Node.h"
#include "Node.cpp"
#include <iostream>
#include <stdio.h>
using namespace std;
template <class DataType>
Queue<DataType>::Queue()
{
	_pFront = NULL;
	_pRear = NULL;
	_iSize = 0;
}

template <class DataType>
Queue<DataType>::~Queue()
{
	//clear();
}

template <class DataType>
bool Queue<DataType>::isEmpty()
{
	return (_pFront == NULL);
}
template <class DataType>
void Queue<DataType>::enQueue(DataType data)
{
	Node<DataType>* pNew = new Node<DataType>(data);
	if (pNew == NULL)	
		cout << "Khong the them";
	else
	{
		if (_pRear == NULL)
		{
			_pFront = pNew;
			_pRear = pNew;
		}
		else
		{
			_pRear->_pNext = pNew;
			_pRear = pNew;
		}
		_iSize++;
	}
}

template <class DataType>
DataType Queue<DataType>::deQueue()
{
	if (isEmpty())
	{
		exit;
	}

	Node<DataType>* pTemp = _pFront;
	DataType temp = pTemp->_data;
	_pFront = pTemp->_pNext;
	delete pTemp;
	_iSize--;

	if (_pFront == NULL)	
		_pRear = NULL;
	return temp;
}

template <class DataType>
DataType Queue<DataType>::peek()
{
	if (isEmpty())
		exit;
	return _pFront->_data;
}

template <class DataType>
void Queue<DataType>::display()
{
	if (isEmpty())
		cout << "Rong!!";
	else
	{
		for (Node<DataType>* p = _pFront; p != NULL; p = p->_pNext)
		{
			p -> display();
		}
	}
}

template <class DataType>
void Queue<DataType>::clear()
{
	Node<DataType>* pTemp;
	while (_pFront != NULL)
	{
		pTemp = _pFront;
		_pFront = pTemp->_pNext;
		delete pTemp;
	}
	_iSize = 0;
	_pRear = NULL;
}

template <class DataType>
int Queue<DataType>::getSize()
{
	return _iSize;
}