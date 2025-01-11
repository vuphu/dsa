#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> radix_sort(std::vector<int> &nums) {
    return nums;
}

int main() {
    std::vector<int> nums = {4, 2, 1, 3, 5};

    std::vector<int> sorted_nums = radix_sort(nums);
    assert(std::is_sorted(sorted_nums.begin(), sorted_nums.end()));

    return 0;
}