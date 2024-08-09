import bisect
from typing import List


def longest_subsequence(nums: List[int]) -> int:
    n = len(nums)
    dp = [0] * n

    dp[0] = 1
    for i in range(1, n):
        length = 0
        for j in range(i):
            if nums[j] < nums[i]:
                length = max(length, dp[j])
        dp[i] = length + 1

    return max(dp)


def fast_longest_subsequence(nums: List[int]) -> int:
    ans = []
    for num in nums:
        if not ans or ans[-1] <= num:
            ans.append(num)
        else:
            ans[bisect.bisect_right(ans, num)] = num
    return len(ans)


if __name__ == "__main__":
    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    print(longest_subsequence(nums))
    print(fast_longest_subsequence(nums))
