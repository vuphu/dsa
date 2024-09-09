#include <cassert>
#include <iostream>
#include <memory>
#include <cassert>

class TreeNode {
  public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value, TreeNode *left = nullptr, TreeNode *right = nullptr)
        : value(value), left(left), right(right) {}

    ~TreeNode() {
        delete this->left;
        delete this->right;
    }
};

TreeNode* lowest_common_ancestor(TreeNode *root, int first_value, int second_value) {
    auto dfs = [&](auto &&self, TreeNode *node) -> TreeNode* {
        if (!node) {
            return nullptr;
        }

        if (node->value == first_value || node->value == second_value) {
            return node;
        }

        auto found_left = self(self, node->left);
        auto found_right = self(self, node->right);

        if (found_left && found_right) {
            return node;
        } else {
            return found_left != nullptr ? found_left : found_right;
        }
    };

    return dfs(dfs, root);
}

int main() {
    TreeNode *root = new TreeNode(1,
                                  new TreeNode(2),
                                  new TreeNode(3,
                                               new TreeNode(4),
                                               new TreeNode(5)));

    TreeNode *ancestor = lowest_common_ancestor(root, 2, 5);
    assert(ancestor == root);

    delete root;
    return 0;
}
