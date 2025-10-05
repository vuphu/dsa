#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> next_greater_element(std::vector<int> nums) {
    std::vector<int> stack;
    std::vector<int> next_greater(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++) {
        while (!stack.empty() && nums[stack.back()] < nums[i]) {
            next_greater[stack.back()] = nums[i];
            stack.pop_back();
        }
        stack.push_back(i);
    }

    return next_greater;
}

int main() {
    std::vector<int> nums = {4, 1, 2};
    assert(next_greater_element(nums) == std::vector<int>({-1, 2, -1}));
}