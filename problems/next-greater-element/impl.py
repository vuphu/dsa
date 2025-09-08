def next_greater_element(nums: list[int]) -> list[int]:
    n, stack = len(nums), []
    ans = [-1] * len(nums)

    for i in range(len(nums)):
        while stack and nums[stack[-1]] < nums[i]:
            ans[stack.pop()] = nums[i]
        stack.append(i)

    return ans

if __name__ == "__main__":
    nums = [4, 1, 2]
    assert next_greater_element(nums) == [-1, 2, -1]