#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  std::vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int count = 0;
    ListNode *itr = head;
    while (itr) {
      count++;
      itr = itr->next;
    }

    int base_len = count / k;
    int extra = count % k;
    std::vector<ListNode *> res(k, nullptr);

    itr = head;

    for (int i = 0; i < k; i++) {
      res[i] = itr;

      int part_len = base_len + (i < extra ? 1 : 0);

      for (int j = 0; j < part_len - 1 && itr; j++) {
        itr = itr ? itr->next : nullptr;
      }

      if (itr) {
        ListNode *next = itr->next;
        itr->next = nullptr;
        itr = next;
      }
    }

    return res;
  }
};
int main() { return 0; }