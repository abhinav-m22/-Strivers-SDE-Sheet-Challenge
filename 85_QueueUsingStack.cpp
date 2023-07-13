// Time Complexity: O(N)
class Queue {
    // Define the data members(if any) here.
    stack<int> input, output;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(val);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(input.empty()) return -1;
        int val = input.top();
        input.pop();
        return val;
    }

    int peek() {
        // Implement the peek() function here.
        if(input.empty()) return -1;
        return input.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return input.empty();
    }
};
