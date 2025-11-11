#include <vector>
#include <set>
#include <functional>
#include <map>
#include <cassert>

// naive solution
int count_inversions(const std::vector<int> &nums) {
    int n = nums.size();
    int inversion_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]) {
                inversion_count += 1;
            }
        }
    }

    return inversion_count;
}

// optimal solution use binary search
// notes: the time complexity is O(N²); we can use third-party libraries for optimization
int count_inversions_bs(const std::vector<int> &nums) {
    std::multiset<int> sorted_nums;
    int inversion_count = 0;

    for (int num: nums) {
        auto pos = sorted_nums.lower_bound(num);
        inversion_count += std::distance(sorted_nums.begin(), pos);
        sorted_nums.insert(num);
    }

    return inversion_count;
}

// optimal solution use BIT (Binary Indexed Tree or Fenwick Tree)
int count_inversions_bit(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> bit(n + 1, 0);
    std::unordered_map<int, int> ranks;
    int inversion_count = 0;

    std::set<int> unique_nums(nums.begin(), nums.end());
    int rank = 1;
    for (int num: unique_nums) {
        ranks[num] = rank++;
    }

    std::function<void(int)> update = [&](int i) -> void {
        while (i <= n) {
            bit[i] += 1;
            i += i & -i;
        }
    };

    std::function<int(int)> query = [&](int i) -> int {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    };

    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
        int rank = ranks[*it];
        inversion_count += query(rank - 1);
        update(rank);
    }

    return inversion_count;
}

int main() {
    std::vector<int> nums = {5, 4, 3, 2, 1, 2, 3, 4, 5};

    assert(count_inversions(nums) == 16);
    assert(count_inversions_bs(nums) == 16);
    assert(count_inversions_bit(nums) == 16);

    return 0;
}