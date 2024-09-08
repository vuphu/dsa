from os import access
from typing import Optional


class TreeNode:
    def __init__(self, value: int, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
        self.value = value
        self.left = left
        self.right = right


def lowest_common_ancestor(root: TreeNode, first_value: int, second_value: int) -> TreeNode:
    def dfs(node: Optional[TreeNode]) -> Optional[TreeNode]:
        if not node:
            return None

        if node.value in [first_value, second_value]:
            return node

        found_left = dfs(node.left)
        found_right = dfs(node.right)

        if found_left and found_right:
            return node
        else:
            return found_left or found_right

    return dfs(root)


if __name__ == "__main__":
    root = TreeNode(
        value=1,
        left=TreeNode(value=2),
        right=TreeNode(
            value=3,
            left=TreeNode(value=4),
            right=TreeNode(value=5)
        )
    )

    ancestor = lowest_common_ancestor(root, 2, 5)
    assert ancestor == root
