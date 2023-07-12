#include<bits/stdc++.h>
using namespace std;

class Stack {
	// Define the data members.

   public:
   queue<int> q;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.empty();
    }

    void push(int element) {
        // Implement the push() function.
        int n = q.size();
        q.push(element);
        for(int i = 0; i < n; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(q.empty()) return -1;

        else {
          int n = q.front();
          q.pop();
          return n;
        }
    }

    int top() {
        // Implement the top() function.
        if (!q.empty()) {
          return q.front();
        }
        else{
            return -1;
        }
    }
};