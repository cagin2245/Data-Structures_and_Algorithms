#pragma once
#include <iostream>
#include <memory>
using namespace std;


struct Node {
	int data;
	Node* next;
	Node* prev;


};

Node * Dpush(Node* r, int x) {
	if (r == NULL)
	{
		r = new Node();
		r->next = NULL;
		r->prev = NULL;
		r->data = x;
		return r;
	}
	if (r->data > x) {
		// ilk elemandan sonra kücük durumu
		// root degisiyor
		Node* temp = new Node();
		temp->data = x;
		temp->next = r;
		temp->prev = NULL;
		r->prev = temp;
		return temp;

	}
	Node* iter = r;
	while (iter->next != NULL && iter->next->data < x)
	{
		iter = iter->next;
	}
	Node* temp = new Node();
	temp->next = iter->next;
	iter->next = temp;
	temp->prev = iter;
	if(temp->next != NULL)
	temp->next->prev = temp;
	temp->data = x;
	return r;

}
Node* Dremove(Node* r, int x)
{
	Node* temp;
	Node* iter = r;
	if (r->data == x)
	{
		temp = r;
		r = r->next;
		free(temp);
		return r;
	}
	while (iter->next != NULL && iter->next->data != x)
	{
		iter = iter->next;

	}
	if (iter->next == NULL) {
		cout << "Sayi bulunamadi." << '\n';
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;	
	free(temp);	
	if (iter->next != NULL)
		iter->next->prev = iter;
	return r;
}
void print(Node* r) {
	while (r != NULL) {
		printf("%d\n", r->data);
		r = r->next;
	}
}
int DlinkedL() {

	Node* root;
	root = NULL;

	Dpush(root, 30);
	Dpush(root, 43);
	print(root);
	

	


	return 0;

}
