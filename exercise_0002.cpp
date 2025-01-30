#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(0);
    ListNode* current = result;
    int carry = 0;
    while (l1 || l2 || carry) {
      int value_first = l1 ? l1->val : 0;
      int value_second = l2 ? l2->val : 0;
      int sum = value_first + value_second + carry;
      
      carry = sum / 10;
      current->next = new ListNode(sum % 10);
      current = current->next;
      
      l1 = l1 ? l1->next : l1;
      l2 = l2 ? l2->next : l2;
    }
    result = result->next;
    delete current;
    return result;
  }
};