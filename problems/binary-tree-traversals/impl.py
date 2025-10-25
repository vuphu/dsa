from __future__ import annotations


class Node:
    def __init__(self, value: int, left: Node | None = None, right: Node | None = None):
        self.value = value
        self.left = left
        self.right = right


def inorder(node: Node | None) -> list[int]:
    if not node:
        return []
    return inorder(node.left) + [node.value] + inorder(node.right)


def preorder(node: Node | None) -> list[int]:
    if not node:
        return []
    return [node.value] + preorder(node.left) + preorder(node.right)


def postorder(node: Node | None) -> list[int]:
    if not node:
        return []
    return postorder(node.left) + postorder(node.right) + [node.value]


if __name__ == '__main__':
    root = Node(
        1,
        left=Node(2, left=Node(4), right=Node(5)),
        right=Node(3, right=Node(6))
    )

    assert inorder(root) == [4, 2, 5, 1, 3, 6]
    assert preorder(root) == [1, 2, 4, 5, 3, 6]
    assert postorder(root) == [4, 5, 2, 6, 3, 1]
