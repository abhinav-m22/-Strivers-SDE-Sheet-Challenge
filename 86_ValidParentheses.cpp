#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<int> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            st.push(s[i]);
        else if ((s[i] == ')' && st.top() == '(') ||
                 (s[i] == ']' && st.top() == '[') ||
                 (s[i] == '}' && st.top() == '{'))
            st.pop();
        else
            st.push(s[i]);
    }

    return st.empty();
}