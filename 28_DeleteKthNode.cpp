
// Following is the class structure of the Node class:

#include <bits/stdc++.h>
using namespace std;

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

// Time Complexity: O(N)
// Space Complexity: O(1)

Node *removeKthNode(Node *head, int K)
{
    Node* start = new Node();
    start->next = head;
    Node* fast = start;
    Node* slow = start;

    for(int i = 1; i <= K; i++) {
        fast = fast->next;
    }

    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return start->next;
}
