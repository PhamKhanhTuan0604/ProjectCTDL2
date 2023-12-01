#include "Node.h"
#include <stdio.h>
#include <iostream>
using namespace std;

template <class DataType>
Node<DataType>::Node(DataType data)
{
	_data = data;
	_pNext = NULL;
}

template <class DataType>
void Node<DataType>::display()
{
	cout << _data << " ";
}