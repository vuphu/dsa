from __future__ import annotations


class ListNode:
    def __init__(self, value: int = 0, next: ListNode | None = None):
        self.value = value
        self.next = next


def has_cycle(head: ListNode) -> bool:
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False


if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)

    assert has_cycle(head) == False

    head.next.next.next = head
    assert has_cycle(head) == True
