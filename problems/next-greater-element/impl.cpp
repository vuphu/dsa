#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> next_greater_element(std::vector<int> nums) {
    std::vector<int> stack;
    std::vector<int> ans(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++) {
        while (!stack.empty() && nums[stack.back()] < nums[i]) {
            ans[stack.back()] = nums[i];
            stack.pop_back();
        }
        stack.push_back(i);
    }

    return ans;
}

int main() {
    std::vector<int> nums = {4, 1, 2};
    assert(next_greater_element(nums) == std::vector<int>({-1, 2, -1}));
}