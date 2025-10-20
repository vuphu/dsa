#include <vector>
#include <cassert>

void next_permutation(std::vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i -= 1;
    }

    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j -= 1;
        }
        std::swap(nums[i], nums[j]);
    }

    std::reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    next_permutation(nums);
    assert(nums == (std::vector<int>{1, 2, 3, 5, 4}));

    next_permutation(nums);
    assert(nums == (std::vector<int>{1, 2, 4, 3, 5}));

    return 0;
}