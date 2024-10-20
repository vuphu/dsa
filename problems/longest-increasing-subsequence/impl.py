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
    stack = []
    for num in nums:
        if not stack or stack[-1] < num:
            stack.append(num)
        else:
            stack[bisect.bisect_left(stack, num)] = num
    return len(stack)


if __name__ == "__main__":
    nums = [10, 9, 2, 5, 3, 7, 101, 18]

    assert longest_subsequence(nums) == 4
    assert fast_longest_subsequence(nums) == 4
