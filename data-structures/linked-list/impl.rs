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

fn to_list_node(nums: &Vec<i32>) -> Option<Box<ListNode>> {
    let mut before_head = Box::new(ListNode::new(-1));
    let mut node = &mut before_head;
    for &num in nums.iter() {
        node.next = Some(Box::new(ListNode::new(num)));
        node = node.next.as_mut().unwrap();
    }
    before_head.next
}

fn to_list(head: &Option<Box<ListNode>>) -> Vec<i32> {
    let mut nums = vec![];
    let mut node = head.as_ref();
    while !node.is_none() {
        let curr = node.unwrap();
        nums.push(curr.value);
        node = curr.next.as_ref();
    }
    nums
}

fn reverse(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    fn recursion(
        current_node: Option<Box<ListNode>>,
        prev_node: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match current_node {
            Some(mut current_node) => {
                let next_node = current_node.next.take();
                current_node.next = prev_node;
                recursion(next_node, Some(current_node))
            }
            None => prev_node,
        }
    }
    recursion(head, None)
}

fn reverse_without_recursion(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut node = None;

    while let Some(mut current_node) = head {
        let next_node = current_node.next.take();
        current_node.next = node;
        node = Some(current_node);
        head = next_node;
    }

    node
}

fn main() {
    let nums = vec![1, 2, 3, 4, 5];
    let head = to_list_node(&nums);

    let mut reversed_nums = nums.clone();
    reversed_nums.reverse();

    let reversed_head = reverse(head);
    assert!(to_list(&reversed_head) == reversed_nums);

    let reversed_reversed_head = reverse_without_recursion(reversed_head);
    assert!(to_list(&reversed_reversed_head) == nums);
}
