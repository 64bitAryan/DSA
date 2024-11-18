#include <iostream>

void printInBack(int c, int n) {
  if (c < 1) {
    return;
  }

  printInBack(c - 1, n);
  std::cout << c << " ";
}

void printNTo1(int c, int n) {
  if (c > n) {
    return;
  }
  printNTo1(c + 1, n);
  std::cout << c << " ";
}

int sumTillN(int i) {
  if (i == 0)
    return 0;
  int sum = i + sumTillN(i - 1);
  return sum;
}

bool checkPalindromeRec(int i, std::string s) {
  if (i >= s.length() / 2)
    return true;
  if (s[i] != s[s.length() - i - 1])
    return false;
  else
    return true;
  return checkPalindromeRec(i + 1, s);
}

int main() {
  int n = 19;
  int res = checkPalindromeRec(0, "Hello");
  int res2 = checkPalindromeRec(0, "nolemonnomelon");
  std::cout << res << " " << res2 << "\n";
  return 0;
}