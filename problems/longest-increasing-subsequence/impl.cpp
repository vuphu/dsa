#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


int longest_subsequence(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 0);

    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        int length = 0;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                length = std::max(length, dp[j]);
            }
        }
        dp[i] = length + 1;
    }

    return *max_element(dp.begin(), dp.end());
}

int fast_longest_subsequence(const std::vector<int>& nums) {
    std::vector<int> stack;
    for (int num : nums) {
        auto it = std::lower_bound(stack.begin(), stack.end(), num);
        if (it == stack.end()) {
            stack.push_back(num);
        } else {
            *it = num;
        }
    }
    return stack.size();
}

int main() {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    assert(longest_subsequence(nums) == 4);
    assert(fast_longest_subsequence(nums) == 4);

    return 0;
}
