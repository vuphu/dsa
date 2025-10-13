#include <vector>
#include <cassert>
#include <algorithm>

class SegmentTree {
public:
    int n;
    std::vector<int> tree;

    SegmentTree(const std::vector<int>& nums) {
        n = nums.size();
        tree.assign(2 * n, 0);
        build(nums);
    }

    void build(const std::vector<int>& nums) {
        for (int i = 0; i < n; i++) {
            tree[n + i] = nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = std::min(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(int pos, int value) {
        pos += n;
        tree[pos] = value;
        while (pos > 1) {
            pos /= 2;
            tree[pos] = std::min(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    int range_min_query(int start_at, int end_at) {
        start_at += n;
        end_at += n + 1;
        int value = INT_MAX;

        while (start_at < end_at) {
            if (start_at % 2 == 1) {
                value = std::min(value, tree[start_at]);
                start_at++;
            }
            if (end_at % 2 == 1) {
                end_at--;
                value = std::min(value, tree[end_at]);
            }
            start_at /= 2;
            end_at /= 2;
        }

        return value;
    }
};

int main() {
    std::vector<int> nums = {1, 3, 2, 7, 9, 11, 3, 5, 6, 4, 8};
    SegmentTree segment_tree(nums);

    assert(segment_tree.range_min_query(0, 5) == 1);

    segment_tree.update(0, 10);
    assert(segment_tree.range_min_query(0, 5) == 2);
}
