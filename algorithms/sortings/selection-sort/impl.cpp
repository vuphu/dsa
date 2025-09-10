#include <algorithm>
#include <vector>
#include <cassert>

std::vector<int> selection_sort(std::vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        std::swap(nums[i], nums[min_index]);
    }

    return nums;
}

int main() {
    std::vector<int> nums = {4, 2, 1, 3, 5};

    std::vector<int> sorted_nums = selection_sort(nums);
    assert(std::is_sorted(sorted_nums.begin(), sorted_nums.end()));

    return 0;
}