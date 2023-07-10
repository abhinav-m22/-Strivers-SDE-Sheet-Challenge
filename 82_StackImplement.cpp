#include <bits/stdc++.h>
// Stack class.
class Stack
{

public:
    int *data;
    int nextIndex;
    int capacity;

    Stack(int capacity)
    {
        // Write your code here.
        data = new int[capacity];
        nextIndex = 0;
        this->capacity = capacity;
    }

    void push(int num)
    {
        // Write your code here.
        if (nextIndex == capacity)
            return;
        data[nextIndex++] = num;
    }

    int pop()
    {
        // Write your code here.
        if (nextIndex == 0)
            return -1;
        int temp = data[nextIndex - 1];
        nextIndex--;
        return temp;
    }

    int top()
    {
        // Write your code here.
        if (nextIndex == 0)
            return -1;
        return data[nextIndex - 1];
    }

    int isEmpty()
    {
        // Write your code here.
        return nextIndex == 0;
    }

    int isFull()
    {
        // Write your code here.
        return nextIndex == capacity;
    }
};