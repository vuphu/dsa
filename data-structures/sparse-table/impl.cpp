#include <vector>
#include <algorithm>
#include <cassert>

class SparseTable {
  public:
    std::vector<int> nums;
    int n;
    std::vector<int> log;
    std::vector<std::vector<int>> sparse_table;

    SparseTable(const std::vector<int> &nums) : nums(nums), n(nums.size()), log(n + 1) {
        build_log();
        build_sparse_table();
    }

    void build_log() {
        log[1] = 0;
        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }
    }

    void build_sparse_table() {
        int k = log[n] + 1;
        sparse_table.assign(n, std::vector<int>(k));

        for (int i = 0; i < n; i++) {
            sparse_table[i][0] = nums[i];
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                sparse_table[i][j] = std::min(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int range_min_query(int start_at, int end_at) {
        int j = log[end_at - start_at + 1];
        return std::min(sparse_table[start_at][j], sparse_table[end_at - (1 << j) + 1][j]);
    }
};

int main() {
    std::vector<int> nums = {1, 3, 2, 7, 9, 11, 3, 5, 6, 4, 8};
    SparseTable sparse_table(nums);

    assert(sparse_table.range_min_query(0, 5) == 1);
    assert(sparse_table.range_min_query(3, 8) == 3);

    return 0;
}
