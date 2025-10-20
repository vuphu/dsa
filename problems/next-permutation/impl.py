def next_permutation(nums: list[int]) -> None:
    n = len(nums)
    i = n - 2

    while i >= 0 and nums[i] >= nums[i + 1]:
        i -= 1

    if i >= 0:
        j = n - 1
        while nums[j] <= nums[i]:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]

    nums[i + 1:] = reversed(nums[i + 1:])


if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5]

    next_permutation(nums)
    assert nums == [1, 2, 3, 5, 4]

    next_permutation(nums)
    assert nums == [1, 2, 4, 3, 5]
