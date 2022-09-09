#include <iostream>
#include <algorithm>
#include <memory>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
    
};

shared_ptr<ListNode<int>> SearchList(shared_ptr<ListNode<int>> L , int key)
{
    while (L && L->data != key)
    {
        L = L->next;
    }
    return L;
}
void InsertAfter(const shared_ptr<ListNode<int>> & node,
                 const shared_ptr<ListNode<int>> & new_node) {
    
    new_node->next = node->next;
    node->next = new_node;
}
void DeleteAfter(const shared_ptr<ListNode<int>> & node)
{
    node->next = node->next->next;

}
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2)
{
    // Placeholder for the result
    shared_ptr<ListNode<int>> dummy_head(new ListNode<int>);
    auto tail = dummy_head;
    while(L1 && L2)
    {
        AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
            
    }
    tail->next = L1 ? L1 : L2;
    return dummy_head->next;
}
void AppendNode(shared_ptr<ListNode<int>> *node, shared_ptr<ListNode<int>> * tail)
{
    (*tail)->next = *node;
    *tail = *node ; // -> updates tail
    *node = (*node)->next;
}