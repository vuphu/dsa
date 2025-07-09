#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <functional>

int partition(std::vector<int> &nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (nums[j] < pivot) {
            i++;
            std::swap(nums[i], nums[j]);
        }
    }

    std::swap(nums[i + 1], nums[high]);
    return i + 1;
}

std::vector<int> quick_sort(std::vector<int> &nums) {
    std::function<void(int, int)> handler = [&](int low, int high) -> void {
        if (low < high) {
            int pivot_index = partition(nums, low, high);
            handler(low, pivot_index - 1);
            handler(pivot_index + 1, high);
        }
    };
    handler(0, nums.size() - 1);
    return nums;
}

int main() {
    std::vector<int> nums = {4, 2, 1, 3, 5};

    std::vector<int> sorted_nums = quick_sort(nums);
    assert(std::is_sorted(sorted_nums.begin(), sorted_nums.end()));

    return 0;
}