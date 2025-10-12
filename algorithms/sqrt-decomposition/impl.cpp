#include <vector>
#include <unordered_map>
#include <cassert>
#include <algorithm>

class SqrtDecomposition {
  public:
    std::vector<int> nums;
    int n, block_size;
    std::vector<std::unordered_map<int, int>> blocks;

    SqrtDecomposition(const std::vector<int> &nums) : nums(nums) {
        n = nums.size();
        block_size = std::sqrt(n);
        blocks.resize((n + block_size - 1) / block_size);

        for (int i = 0; i < n; i++) {
            int block_index = i / block_size;
            blocks[block_index][nums[i]]++;
        }
    }

    int query(int left, int right, int k) {
        int left_block = left / block_size;
        int right_block = right / block_size;
        int value_count = 0;

        if (left_block == right_block) {
            value_count = std::count(nums.begin() + left, nums.begin() + right + 1, k);
        } else {
            int end_of_left_block = (left_block + 1) * block_size;
            int start_of_right_block = right_block * block_size;

            value_count += std::count(nums.begin() + left, nums.begin() + end_of_left_block, k);
            value_count += std::count(nums.begin() + start_of_right_block, nums.begin() + right + 1, k);

            for (int block_id = left_block + 1; block_id < right_block; block_id++) {
                value_count += blocks[block_id][k];
            }
        }

        return value_count;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 1, 3, 2, 1, 3, 1, 2};
    SqrtDecomposition sd(nums);

    assert(sd.query(2, 6, 1) == 2);
    assert(sd.query(2, 7, 1) == 3);

    return 0;
}
