#pragma once

#include "Node.h"
#include <iostream>
#include <stdio.h>
template <class DataType>
class Queue
{
private:
	Node<DataType>* _pFront;
	Node<DataType>* _pRear;
	int _iSize;
public:
	Queue();
	~Queue();
	bool isEmpty();
	void enQueue(DataType data);
	DataType deQueue();
	DataType peek();
	void display();
	void clear();
	int getSize();
};
