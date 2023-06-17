#include <bits/stdc++.h>
using namespace std;

//   Following is the class structure of the Node class:

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
Node *firstNode(Node *head)
{
    unordered_set<Node*> st;
    while(head != NULL) {
        if(st.find(head) != st.end()) return head;
        st.insert(head);
        head = head->next;
    }
    return NULL;
}

// Time Complexity: O(n), Space Complexity: O(1)
Node *firstNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (slow != temp)
            {
                slow = slow->next;
                temp = temp->next;
            }
            return slow;
        }
    }
    return NULL;
}