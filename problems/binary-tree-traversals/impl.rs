struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32, left: Option<Node>, right: Option<Node>) -> Self {
        Node {
            value,
            left: left.map(Box::new),
            right: right.map(Box::new),
        }
    }

    fn leaf(value: i32) -> Self {
        Node {
            value,
            left: None,
            right: None,
        }
    }
}

fn inorder(node: &Node) -> Vec<i32> {
    let mut values = vec![];

    if let Some(left) = &node.left {
        values.extend(inorder(left));
    }

    values.push(node.value);

    if let Some(right) = &node.right {
        values.extend(inorder(right));
    }

    values
}

fn preorder(node: &Node) -> Vec<i32> {
    let mut values = vec![node.value];

    if let Some(left) = &node.left {
        values.extend(preorder(left));
    }

    if let Some(right) = &node.right {
        values.extend(preorder(right));
    }

    values
}

fn postorder(node: &Node) -> Vec<i32> {
    let mut values = vec![];

    if let Some(left) = &node.left {
        values.extend(postorder(left));
    }

    if let Some(right) = &node.right {
        values.extend(postorder(right));
    }

    values.push(node.value);

    values
}

fn main() {
    let root = Node::new(
        1,
        Some(Node::new(2, Some(Node::leaf(4)), Some(Node::leaf(5)))),
        Some(Node::new(3, None, Some(Node::leaf(6)))),
    );

    assert_eq!(inorder(&root), vec![4, 2, 5, 1, 3, 6]);
    assert_eq!(preorder(&root), vec![1, 2, 4, 5, 3, 6]);
    assert_eq!(postorder(&root), vec![4, 5, 2, 6, 3, 1]);
}
