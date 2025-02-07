#include <iostream>
#include <vector>
#include <cassert>

// nums is already sorted
bool binary_search(const std::vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 4, 8, 16, 32, 64, 128};

    assert(binary_search(nums, 32) == true);
    assert(binary_search(nums, 31) == false);

    return 0;
}