#include <bits/stdc++.h>
// Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

// Recursive
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* result = NULL;
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    if(first->data <= second->data) {
        result = first;
        result->next = sortTwoLists(first->next, second);
    }
    else {
        result = second;
        result->next = sortTwoLists(first, second->next);
    }
    return result;
}

// Iterative
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* p = NULL;
    Node<int>* q = NULL;

    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    if(first->data < second->data) {
        p = first;
        q = first;
        first = first->next;
    }
    else {
        p = second;
        q = second;
        second = second->next;
    }

    while(first && second){
        if(first->data < second->data){
            q->next = first;
            q = first;
            first = first->next;
            q->next = NULL;
        }
        else{
            q->next = second;
            q = second;
            second = second->next;
            q->next = NULL;
        }
    }
    if(first){
        q->next = first;
    }
    if(second){
        q->next = second;
    }
    return p;
}