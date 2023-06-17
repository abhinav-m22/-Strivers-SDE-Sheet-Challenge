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

// Time Complexity: O(n), Space Complexity: O(n)
bool detectCycle(Node* head){
    unordered_set<Node*> s;
    while(head != NULL) {
        if(s.find(head) != s.end()) return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}

// Time Complexity: O(n), Space Complexity: O(1)
bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}