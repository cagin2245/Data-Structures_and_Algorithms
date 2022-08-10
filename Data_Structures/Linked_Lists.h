#pragma once
#include <iostream>
#include <memory>
using namespace std;


struct Node {
		int data;
		unique_ptr<Node> next;
		
		Node(int data) : data{ data }, next(nullptr){}
		
		
		
		
		
};
struct List {
	List() : head{ nullptr } {};

	void push(int data) {
		auto temp{ make_unique<Node>(data) };
		if (head)
		{
			temp->next = move(head);
			head = move(temp);

		}
		else {
			head = move(temp);
		}

	}
	void clean() {
		while (head) {
			head = move(head->next);
		}
	}
	
	
	List(const List& list) {
		Node* root = list.head.get();
		unique_ptr<Node> new_head(nullptr);
		Node* pnew_head(nullptr);
		while (root) {
			auto temp{ make_unique<Node>(root->data) };
			if (new_head == nullptr)
			{
				new_head = move(temp);
				pnew_head = new_head.get();
			}
			else {
				pnew_head->next = std::move(temp);
				pnew_head = pnew_head->next.get();

			}
			root = root->next.get();
		}
		head = move(new_head);
	};
	List(List&& list) {
		head = move(list.head);
	}
	void reverse() {
		List tmp;
		Node* root = head.get();
		
		while (root) {
			tmp.push(root->data);
			root = root->next.get();
		}
		clean();
		head = move(tmp.head);

	}
	~List() {
		clean();
	}
	friend ostream& operator<<(std::ostream& os, const List& list);
	void pop()
	{
		if (head == nullptr)
		{
			return;
		}
		unique_ptr<Node> temp = move(head);
		head = move(temp->next);
	}
	
private:
	unique_ptr<Node> head;
	


};

ostream& operator<<(ostream& os, const List& list) {
	Node* head = list.head.get();
	     while (head) {
		         os << head->data << ' ';
		       head = head->next.get();
		
	}
	     return os;
}
int linkedL() {
	
	List list;		
	
      
	 return 0;
}
