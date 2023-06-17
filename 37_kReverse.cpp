#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// Time Complexity: O(length of list) + O(length of list – (length of list%k)), Space Complexity: O(1)
Node *rotate(Node *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    Node *temp = head;
    int length = 1;
    while (temp->next)
    {
        length++;
        temp = temp->next;
    }
    temp->next = head;
    k = k % length;
    int end = length - k;
    while (end--)
    {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;
    return head;
}