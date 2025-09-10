#include <algorithm>
#include <vector>
#include <cassert>

std::vector<int> counting_sort(std::vector<int> nums, int exp) {
    int n = nums.size();
    std::vector<int> counter(10, 0);
    std::vector<int> sorted_nums = nums;

    for (int i = 0; i < n; i++) {
        int bucket = (nums[i] / exp) % 10;
        counter[bucket] += 1;
    }

    for (int i = 1; i < 10; i++) {
        counter[i] += counter[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int bucket = (nums[i] / exp) % 10;
        sorted_nums[counter[bucket] - 1] = nums[i];
        counter[bucket] -= 1;
    }

    return sorted_nums;
}

std::vector<int> radix_sort(std::vector<int> &nums) {
    int max_num = *std::max_element(nums.begin(), nums.end());
    int exp = 1;

    while (max_num / exp > 0) {
        nums = counting_sort(nums, exp);
        exp *= 10;
    }

    return nums;
}

int main() {
    std::vector<int> nums = {64, 2, 16, 512, 1024};

    std::vector<int> sorted_nums = radix_sort(nums);
    assert(std::is_sorted(sorted_nums.begin(), sorted_nums.end()));

    return 0;
}