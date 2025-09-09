#include <algorithm>
#include <vector>
#include <cassert>

std::vector<float> bucket_sort(std::vector<float> &nums) {
    int n = nums.size();
    std::vector<std::vector<float>> buckets(n);
    std::vector<float> sorted_nums;

    for (auto &num: nums) {
        int index = int(num * n);
        buckets[index].push_back(num);
    }

    for (auto &bucket: buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    for (auto &bucket: buckets) {
        for (auto &num: bucket) {
            sorted_nums.push_back(num);
        }
    }

    return sorted_nums;
}

int main() {
    std::vector<float> nums = {0.5, 0.99, 0.75, 0.25, 0.01};

    std::vector<float> sorted_nums = bucket_sort(nums);
    assert(std::is_sorted(sorted_nums.begin(), sorted_nums.end()));

    return 0;
}