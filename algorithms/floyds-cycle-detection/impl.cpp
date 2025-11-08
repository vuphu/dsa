#include <cassert>

class ListNode {
  public:
    int value;
    ListNode *next = nullptr;

    ListNode(int value) : value(value){};
};

bool has_cycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    assert(has_cycle(head) == false);

    head->next->next->next = head;
    assert(has_cycle(head) == true);

    return 0;
}
