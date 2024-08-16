from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def build(nums: List[int]) -> Optional[ListNode]:
    before_head = ListNode(-1)
    node = before_head
    for num in nums:
        node.next = ListNode(num)
        node = node.next
    return before_head.next


def to_list(head: Optional[ListNode]) -> List[int]:
    node = head
    nums = []
    while node:
        nums.append(node.val)
        node = node.next
    return nums


def reverse(head: Optional[ListNode]) -> Optional[ListNode]:
    if not head or not head.next:
        return head
    
    next_node = head.next
    reversed_head = reverse(next_node)
    head.next = None
    next_node.next = head
    
    return reversed_head


def reverse_without_recursion(head: Optional[ListNode]) -> Optional[ListNode]:
    node = None
    
    while head:
        next_node = head.next
        head.next = node
        node = head
        head = next_node
        
    return node

if __name__ == "__main__":
    head = build([1, 2, 3, 4, 5])
    print(to_list(head))

    reversed_head = reverse(head)
    print(to_list(reversed_head))
    
    reversed_reversed_head = reverse_without_recursion(reversed_head)
    print(to_list(reversed_reversed_head))
