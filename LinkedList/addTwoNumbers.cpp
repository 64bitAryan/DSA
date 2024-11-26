#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// approach 1
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *ptr1 = l1;
  ListNode *ptr2 = l2;

  ListNode *res = new ListNode();
  ListNode *curr = res;

  int carry = 0;
  int sum = 0;
  while (ptr1 && ptr2) {
    sum = (ptr1->val + ptr2->val + carry) % 10;
    carry = (ptr1->val + ptr2->val + carry) / 10;
    ListNode *t = new ListNode(sum);
    curr->next = t;
    curr = curr->next;
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  while (ptr1) {
    sum = (ptr1->val + carry) % 10;
    carry = (ptr1->val + carry) / 10;
    ListNode *t = new ListNode(sum);
    curr->next = t;
    curr = curr->next;
    ptr1 = ptr1->next;
  }

  while (ptr2) {
    sum = (ptr2->val + carry) % 10;
    carry = (ptr2->val + carry) / 10;
    ListNode *t = new ListNode(sum);
    curr->next = t;
    curr = curr->next;
    ptr2 = ptr2->next;
  }

  if (carry > 0) {
    ListNode *t = new ListNode(carry);
    curr->next = t;
    curr = curr->next;
  }

  return res->next;
}

// approach 2
ListNode *addTwoNumbersAlt(ListNode *l1, ListNode *l2) {
  ListNode *ptr1 = l1;
  ListNode *ptr2 = l2;

  ListNode *res = new ListNode();
  ListNode *curr = res;

  int carry = 0;

  while (ptr1 || ptr2 || carry) {
    int sum = 0;
    if (ptr1) {
      sum += ptr1->val;
      ptr1 = ptr1->next;
    }

    if (ptr2) {
      sum += ptr2->val;
      ptr2 = ptr2->next;
    }
    sum += carry;
    carry = sum / 10;
    ListNode *c = new ListNode(sum % 10);
    curr->next = c;
    curr = curr->next;
  }
  return res->next;
}

int main() { return 0; }