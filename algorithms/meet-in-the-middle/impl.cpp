#include <vector>
#include <functional>
#include <unordered_map>
#include <cassert>

std::vector<int> find_subset_sums(std::vector<int> nums) {
    std::vector<int> sums;

    std::function<void(int, int)> attempt = [&](int i, int s) -> void {
        if (i == nums.size()) {
            sums.push_back(s);
            return;
        }
        attempt(i + 1, s);
        attempt(i + 1, s + nums[i]);
    };

    attempt(0, 0);
    return sums;
}

int count_target_subsets(std::vector<int> nums, int target) {
    int n = nums.size();
    std::vector<int> front_sums = find_subset_sums(std::vector<int>(nums.begin(), nums.begin() + n / 2));
    std::vector<int> back_sums = find_subset_sums(std::vector<int>(nums.begin() + n / 2, nums.end()));

    std::unordered_map<int, int> back_sum_counter;
    for (auto &sum : back_sums) {
        back_sum_counter[sum] += 1;
    }

    int subset_count = 0;
    for (auto &sum : front_sums) {
        subset_count += back_sum_counter[target - sum];
    }

    return subset_count;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(count_target_subsets(nums, 10) == 10);

    return 0;
}