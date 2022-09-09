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
shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, uint16_t start, uint16_t finish)
{
    if(start == finish)
    {
        return L; // -> NO need to reverse
    }
    auto dummy_head = make_shared<ListNode<int>> (ListNode<int>{0,L});
    auto sublist_head = dummy_head;
    int k = 1;
    while(k++ < start)
    {
        sublist_head = sublist_head ->next;
    }

    // Reversing the Sublist
    auto sublist_iter = sublist_head->next;
    while(start++ < finish)
    {
        auto temp = sublist_iter->next;
        temp->next = sublist_head->next;
        sublist_head->next = temp;
    }
    return dummy_head->next;
}
shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>> &head)
{
    shared_ptr<ListNode<int>> fast = head,slow = head;
    while(fast && fast->next)
    {
        slow = slow->next, fast = fast->next->next;
        if(slow == fast)
        {
            // cycle detected
            uint16_t cycle_len = 0;
            do 
            {
                ++cycle_len;
                fast = fast->next;

            } while (slow!=fast); 
            // Finding the start of the cycle
            auto cycle_len_advanced_iter = head;
            while(cycle_len--)
            {
                cycle_len_advanced_iter = cycle_len_advanced_iter->next;
            }
            auto iter = head;
            // Both iterators advance in parallel
            while(iter!= cycle_len_advanced_iter)
            {
                iter = iter->next;
                cycle_len_advanced_iter = cycle_len_advanced_iter->next;

            }
            return iter;
        
        }

    }
    return nullptr;
}