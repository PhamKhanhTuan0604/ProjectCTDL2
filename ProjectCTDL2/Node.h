#pragma once


template <class DataType>
class Queue;
template <class DataType>
class Node
{
	friend Queue<DataType>;
private:
	DataType _data;
	Node* _pNext;
public:
	Node(DataType data);
	void display();
};

