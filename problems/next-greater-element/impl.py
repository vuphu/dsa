def next_greater_element(nums: list[int]) -> list[int]:
    stack = []
    next_greater = [-1] * len(nums)

    for i in range(len(nums)):
        while stack and nums[stack[-1]] < nums[i]:
            next_greater[stack.pop()] = nums[i]
        stack.append(i)

    return next_greater

if __name__ == "__main__":
    nums = [4, 1, 2]
    assert next_greater_element(nums) == [-1, 2, -1]