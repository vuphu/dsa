struct TreeNode {
    value: i32,
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}

impl TreeNode {
    fn new(value: i32) -> Self {
        TreeNode {
            value,
            left: None,
            right: None,
        }
    }
}

fn lowest_common_ancestor(
    root: &TreeNode,
    first_value: i32,
    second_value: i32,
) -> Option<&TreeNode> {
    fn dfs(node: Option<&TreeNode>, first_value: i32, second_value: i32) -> Option<&TreeNode> {
        let node = node.as_ref()?;

        if node.value == first_value || node.value == second_value {
            return Some(node);
        }

        let found_left = dfs(node.left.as_deref(), first_value, second_value);
        let found_right = dfs(node.right.as_deref(), first_value, second_value);

        match (found_left, found_right) {
            (Some(_), Some(_)) => Some(node),
            (Some(node), None) | (None, Some(node)) => Some(node),
            _ => None,
        }
    }

    dfs(Some(root), first_value, second_value)
}

fn main() {
    let root = TreeNode {
        value: 1,
        left: Some(Box::new(TreeNode::new(2))),
        right: Some(Box::new(TreeNode {
            value: 3,
            left: Some(Box::new(TreeNode::new(4))),
            right: Some(Box::new(TreeNode::new(5))),
        })),
    };

    let ancestor = lowest_common_ancestor(&root, 2, 5).unwrap();
    assert!(std::ptr::eq(ancestor, &root));
}
