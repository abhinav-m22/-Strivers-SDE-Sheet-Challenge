#include <bits/stdc++.h>
using namespace std;
/*
        This is signature of helper function 'knows'.
        You should not implement it, or speculate about its implementation.

        bool knows(int A, int B);
        Function 'knows(A, B)' will returns "true" if the person having
        id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
  stack<int> s;
  for (int i = 0; i < n; i++) {
    s.push(i);
  }

  while (s.size() > 1) {
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    if (knows(a, b))
      s.push(b);
    else
      s.push(a);
  }
  int ans = s.top();
  for (int i = 0; i < n; i++) {
    if (i == ans) {
      continue;
    }

    if (knows(ans, i)) {
      return -1;
    }
    if (!knows(i, ans)) {
      return -1;
    }
  }
  return ans;
}