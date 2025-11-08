struct ListNode {
    pub value: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    fn new(value: i32) -> Self {
        ListNode {
            value: value,
            next: None,
        }
    }
}

fn has_cycle(head: &ListNode) -> bool {
    let mut slow = Some(head);
    let mut fast = Some(head);

    while let (Some(slow_node), Some(fast_node)) = (slow, fast) {
        slow = slow_node.next.as_deref();
        fast = fast_node.next.as_deref();
        if let Some(node) = fast {
            fast = node.next.as_deref();
        }
        if let (Some(slow), Some(fast)) = (slow, fast) {
            if std::ptr::eq(slow, fast) {
                return true;
            }
        }
    }

    false
}

fn main() {
    let mut head = ListNode::new(1);
    head.next = Some(Box::new(ListNode::new(2)));
    head.next.as_mut().unwrap().next = Some(Box::new(ListNode::new(3)));

    assert!(has_cycle(&head) == false);

    unsafe {
        let mut head = std::mem::ManuallyDrop::new(head);
        let head_ptr: *mut ListNode = &mut *head;
        let last_node = head.next.as_mut().unwrap().next.as_mut().unwrap();
        last_node.next = Some(Box::from_raw(head_ptr));
        assert!(last_node.next.as_mut().unwrap().value == head.value);
        assert!(has_cycle(&head) == true);
    }
}
