#include <bits/stdc++.h> 
class Queue {

    int* arr;
    int size;
    int qfront;
    int rear;

public:
    Queue() {
        // Implement the Constructor
        size = 10000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return qfront == rear;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear != size) arr[rear++] = data;
        else return;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront == rear) return -1;
        else {
            int temp = arr[qfront++];
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return temp;
        }
    }

    int front() {
        // Implement the front() function
        if(rear == qfront)
         return -1;
        return arr[qfront]; 
    }
};