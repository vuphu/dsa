#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>

class ListNode {
public:
  int value;
  ListNode *next = nullptr;

  ListNode(int value) : value(value){};
};

ListNode *to_list_node(const std::vector<int> &nums) {
  ListNode *before_head = new ListNode(-1);
  ListNode *node = before_head;
  for (auto &num : nums) {
    node->next = new ListNode(num);
    node = node->next;
  }
  return before_head->next;
}

std::vector<int> to_list(ListNode *head) {
  std::vector<int> nums;
  ListNode *node = head;
  while (node != nullptr) {
    nums.push_back(node->value);
    node = node->next;
  }
  return nums;
}

ListNode *reverse(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode *next_node = head->next;
  ListNode *reversed_head = reverse(next_node);
  head->next = nullptr;
  next_node->next = head;

  return reversed_head;
}

ListNode *reverse_without_recursion(ListNode *head) {
  ListNode *node = nullptr;

  while (head != nullptr) {
    ListNode *next_node = head->next;
    head->next = node;
    node = head;
    head = next_node;
  }

  return node;
}

int main() {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  ListNode *head = to_list_node(nums);

  std::vector<int> reversed_nums = nums;
  std::reverse(reversed_nums.begin(), reversed_nums.end());

  ListNode *reversed_head = reverse(head);
  assert(to_list(reversed_head) == reversed_nums);

  ListNode *reversed_reversed_head = reverse_without_recursion(reversed_head);
  assert(to_list(reversed_reversed_head) == nums);

  return 0;
}