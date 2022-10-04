#include <iostream>

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int v, ListNode* n) {
    val = v;
    next = n;
  }
};
// 1, 10, 20, 50

int main() {
  ListNode* n1 = new ListNode(1,0);
  ListNode* n2 = new ListNode(10,0);
  ListNode* n3 = new ListNode(20,0);
  ListNode* n4 = new ListNode(50,0);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = 0;

  ListNode* p = n1;
  while (p != 0) {
    std::cout << p->val << std::endl;
    p = p->next;
  }
}


