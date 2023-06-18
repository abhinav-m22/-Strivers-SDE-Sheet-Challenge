#include <bits/stdc++.h>
using namespace std;

// Following is the LinkedListNode class structure

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Brute Force Approach: Time Complexity: O(n)+O(n), Space Complexity: O(n)
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> map;
    LinkedListNode<int> *temp = head;

    while (temp != NULL)
    {
        map[temp] = new LinkedListNode<int>(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        map[temp]->next = map[temp->next];
        map[temp]->random = map[temp->random];
        temp = temp->next;
    }

    return map[head];
}


// Optimal Approach: Time Complexity: O(n)+O(n)+O(n), Space Complexity: O(1)
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // LinkedListNode<int>* temp = head;

    // // 1
    // while(temp){
    //     LinkedListNode<int>* newNode = new LinkedListNode<int>(temp->data);
    //     newNode->next = temp->next;
    //     temp->next = newNode;
    //     temp = temp->next->next;
    // }

    // // 2
    // LinkedListNode<int>* iter = head;
    // while(iter){
    //     if(iter->random){
    //         iter->next->random = iter->random->next;
    //     }
    //     iter = iter->next->next;
    // }

    // // 3
    // LinkedListNode<int>* dummy = new LinkedListNode<int>(0);
    // iter = head;
    // temp = dummy;
    // LinkedListNode<int>* fast;
    // while(iter){
    //     fast = iter->next->next;
    //     temp->next = iter->next;
    //     iter->next = fast;
    //     temp = temp->next;
    //     iter = fast;
    // }
    // return dummy->next;

    LinkedListNode<int>* iter = head;
    LinkedListNode<int>* front = head;

    // 1
    while(iter){
        front = iter->next;
        LinkedListNode<int>* copy = new LinkedListNode<int>(iter->data);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }

    // 2
    iter = head;
    while(iter){
        if(iter->random){
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }

    // 3
    iter = head;
    LinkedListNode<int>* dummy = new LinkedListNode<int>(0);
    LinkedListNode<int>* copy = dummy;

    while(iter){
        front = iter->next->next;
        copy->next = iter->next;
        iter->next = front;
        copy = copy->next;
        iter = front;
    }
    return dummy->next;
}