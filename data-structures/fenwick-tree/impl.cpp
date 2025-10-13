#include <vector>
#include <cassert>

class FenwickTree {
  public:
    std::vector<int> tree;
    int n;

    FenwickTree(int n) : tree(n, 0), n(n) {}

    void update(int pos, int value) {
        while (pos < n) {
            tree[pos] += value;
            pos = pos | (pos + 1);
        }
    }

    int query(int pos) {
        int total = 0;
        while (pos >= 0) {
            total += tree[pos];
            pos = (pos & (pos + 1)) - 1;
        }
        return total;
    }
};

int main() {
    FenwickTree fenwick_tree(10);
    fenwick_tree.update(0, 5);
    fenwick_tree.update(1, 3);
    
    assert(fenwick_tree.query(1) == 8);

    return 0;
}
