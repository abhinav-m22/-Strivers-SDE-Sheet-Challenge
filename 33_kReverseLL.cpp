#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int length(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    Node *temp = head;
    vector<int> a;

    while (temp)
    {
        a.push_back(temp->data);
        temp = temp->next;
    }

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        reverse(a.begin() + sum, min(a.begin() + sum + b[i], a.end()));
        sum += b[i];
    }

    temp = head;
    int i = 0;
    while (temp)
    {
        temp->data = a[i++];
        temp = temp->next;
    }

    return head;
}