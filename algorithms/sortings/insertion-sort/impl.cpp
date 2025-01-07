#include <algorithm>
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

    std::vector<int> sorted_nums = insertion_sort(nums);
    assert(std::is_sorted(sorted_nums.begin(), sorted_nums.end()));

    return 0;
}