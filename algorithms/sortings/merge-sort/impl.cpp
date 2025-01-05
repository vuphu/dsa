#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

std::vector<int> merge(const std::vector<int> &fronts, const std::vector<int> &backs) {
    std::vector<int> nums;
    int i = 0, j = 0;

    while (i < fronts.size() && j < backs.size()) {
        if (fronts[i] <= backs[j]) {
            nums.push_back(fronts[i]);
            i++;
        } else {
            nums.push_back(backs[j]);
            j++;
        }
    }

    while (i < fronts.size()) {
        nums.push_back(fronts[i]);
        i++;
    }
    while (j < backs.size()) {
        nums.push_back(backs[j]);
        j++;
    }

    return nums;
}

std::vector<int> merge_sort(const std::vector<int> nums) {
    int n = nums.size();
    int mid = n / 2;

    if (n <= 1) {
        return nums;
    }

    std::vector<int> fronts(nums.begin(), nums.begin() + mid);
    std::vector<int> backs(nums.begin() + mid, nums.end());
    fronts = merge_sort(fronts);
    backs = merge_sort(backs);

    return merge(fronts, backs);
}

int main() {
    std::vector<int> nums = {4, 2, 1, 3, 5};
    assert(merge_sort(nums) == (std::vector<int>{1, 2, 3, 4, 5}));

    return 0;
}
