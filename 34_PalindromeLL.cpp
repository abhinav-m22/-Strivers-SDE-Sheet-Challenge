#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the LinkedListNode class:

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int>* reverse(LinkedListNode<int>* head)
{
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* fwd = NULL;

    while (curr)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

// int length(LinkedListNode<int *> head)
// {
//     int count = 0;
//     LinkedListNode<int *> temp = head;
//     while (temp != NULL)
//     {
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }

bool isPalindrome(LinkedListNode<int> *head)
{
    /*Solution 1*/

    // if (!head || !head->next)
    //     return true;

    // LinkedListNode<int> *p = head;
    // int x = length(head) / 2;
    // for (int i = 1; i < x; i++)
    // {
    //     p = p->next;
    // }

    // LinkedListNode<int> *h2 = p->next;
    // p->next = NULL;
    // h2 = reverse(h2);

    // while (head && h2)
    // {
    //     if (head->data != h2->data)
    //     {
    //         return false;
    //     }
    //     head = head->next;
    //     h2 = h2->next;
    // }

    // return true;

    /*Solution 2*/

    // Time Complexity: O(N/2)+O(N/2)+O(N/2) = O(N)
    if(!head || !head->next) return true;

    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;
    LinkedListNode<int>* temp = head;

    while(slow){
        if(temp->data != slow->data) return false;
        temp = temp->next;
        slow = slow->next;
    }
    return true;
}