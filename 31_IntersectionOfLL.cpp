#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* findIntersection(Node *head1, Node *head2)
{
    Node *a = head1;
    Node *b = head2;

    while (1)
    {
        if (a == b)
            return a;
        a = a->next;
        b = b->next;

        if (a == NULL && b == NULL)
            return NULL;

        if (!a)
            a = head2;
        if (!b)
            b = head1;
    }
    return a;
}