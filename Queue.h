#pragma once
#include <memory>
using std::unique_ptr;
using std::make_unique;

template<class t_Data>
class Queue
{
	struct Node
	{
		t_data data;
		unique_ptr<Node> nextNode;

		Node(const t_data&_data)
			:data(_data){}
	};
	unique_ptr<Node> firstNode;
	Node* lastNode = nullptr;
	int count = 0;
};