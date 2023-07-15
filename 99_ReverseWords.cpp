#include<bits/stdc++.h>
using namespace std;

string reverseString(string &s)
{
    // Write your code here.
    if (s.size() == 0)
        return s;

    stack<string> st;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        string word = "";
        if (s[i] == ' ')

            continue;

        while (i < s.size() && s[i] != ' ')
        {

            word += s[i];

            i++;
        }

        st.push(word);
    }

    while (st.empty() == 0)

    {

        ans += st.top();

        st.pop();

        if (!st.empty())

        {

            ans += ' ';
        }
    }

    return ans;
}