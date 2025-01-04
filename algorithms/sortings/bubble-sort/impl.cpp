#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> bubble_sort(std::vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }

    return nums;
}

int main() {
    std::vector<int> nums = {4, 2, 1, 3, 5};
    assert(bubble_sort(nums) == (std::vector<int>{1, 2, 3, 4, 5}));

    return 0;
}