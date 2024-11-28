#include <iostream>
#include <stack>
#include <vector>

bool isValid(std::string str) {
  std::stack<char> s;
  for (int i = 0; i < str.length(); i++) {
    char c = str[i];
    if (c == '(' || c == '{' || c == '[') {
      s.push(c);
    } else {
      if (s.empty() || (c == '}' && s.top() != '{') ||
          (c == ')' && s.top() != '(') || (c == ']' && s.top() != '['))
        return false;
      else
        s.pop();
    }
  }
  if (!s.empty())
    return false;
  return true;
}

int main() { return 0; }