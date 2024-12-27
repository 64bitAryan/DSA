#include <iostream>
#include <limits.h>
#include <stack>

class MinStack {
public:
  std::stack<long long> st;
  long long min = INT_MAX;
  MinStack() {}

  void push(int val) {
    if (st.empty()) {
      st.push(val);
      min = val;
    } else {
      if (val < min) {
        st.push(((long long)2 * val) - min);
        min = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    if (st.empty())
      return;
    long long n = st.top();
    st.pop();
    if (n < min) {
      min = 2 * min - n;
    }
  }

  int top() {
    if (st.empty())
      return -1;
    long long n = st.top();
    if (min < n)
      return n;
    return min;
  }

  int getMin() { return min; }
};

int main() {}