#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> insertion_sort(std::vector<int> &nums) {
    int n = nums.size();

    for (int i = 1; i < n; i++) {
        int value = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > value) {
            nums[j + 1] = nums[j];
            j -= 1;
        }
        nums[j + 1] = value;
    }

    return nums;
}

int main() {
    std::vector<int> nums = {4, 2, 1, 3, 5};
    assert(insertion_sort(nums) == (std::vector<int>{1, 2, 3, 4, 5}));

    return 0;
}