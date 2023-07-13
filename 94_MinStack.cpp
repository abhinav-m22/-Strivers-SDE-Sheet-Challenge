#include <bits/stdc++.h> 
using namespace std;
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<pair<int, int>> s;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			int mini;
			if(s.empty()){
				mini = num;
			}
			else{
				mini = min(num, s.top().second);
			}
			s.push({num, mini});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(s.empty()) return -1;
			int val = s.top().first;
			s.pop();
			return val;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(s.empty()) return -1;
			return s.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(s.empty()) return -1;
			return s.top().second;
		}
};