#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> quick_sort(std::vector<int> &nums) {
    return nums;
}

int main() {
    std::vector<int> nums = {4, 2, 1, 3, 5};
    assert(quick_sort(nums) == (std::vector<int>{1, 2, 3, 4, 5}));

    return 0;
}