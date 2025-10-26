#include <vector>
#include <cassert>


template <typename T>
std::vector<T> &operator+=(std::vector<T> &a, const std::vector<T> &b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}

class Node {
public:
  int value;
  Node *left;
  Node *right;

  Node(int value, Node *left = nullptr, Node *right = nullptr)
      : value(value), left(left), right(right) {}

  ~Node() {
    delete left;
    delete right;
  }
};

std::vector<int> inorder(Node *node) {
  if (node == nullptr) {
    return {};
  }

  std::vector<int> values = inorder(node->left);
  values += {node->value};
  values += inorder(node->right);

  return values;
}

std::vector<int> preorder(Node *node) {
  if (node == nullptr) {
    return {};
  }

  std::vector<int> values = {node->value};
  values += preorder(node->left);
  values += preorder(node->right);

  return values;
}

std::vector<int> postorder(Node *node) {
  if (node == nullptr) {
    return {};
  }

  std::vector<int> values = postorder(node->left);
  values += postorder(node->right);
  values += {node->value};

  return values;
}

int main() {
  Node *root = new Node(
    1,
    new Node(2, new Node(4), new Node(5)),
    new Node(3, nullptr, new Node(6))
  );

  assert(inorder(root) == (std::vector<int>{4, 2, 5, 1, 3, 6}));
  assert(preorder(root) == (std::vector<int>{1, 2, 4, 5, 3, 6}));
  assert(postorder(root) == (std::vector<int>{4, 5, 2, 6, 3, 1}));

  delete root;
  return 0;
}
