/******************************************************************************

    Welcome to GDB Online.
      GDB online is an online compiler and debugger tool for C, C++, Python,
   PHP, Ruby, C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL,
   HTML, CSS, JS Code, Compile, Run and Debug online from anywhere in world.

    *******************************************************************************/
#include <bits/stdc++.h>

int main() {

  std::vector<int> temp = {1, 2, 3, 4, 5, 6, 7};
  std::reverse(temp.begin(), temp.end());

  for (auto s : temp) {
    std::cout << s << " ";
  }

  return 0;
}
// find . -type f -name "*.cpp" | wc -l