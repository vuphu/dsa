def quick_sort(nums: list[int]) -> list[int]:
    n = len(nums)

    if n <= 1:
        return nums

    pivot = nums[n // 2]
    fronts = [num for num in nums if num < pivot]
    middles = [num for num in nums if num == pivot]
    backs = [num for num in nums if num > pivot]

    return [*quick_sort(fronts), *middles, *quick_sort(backs)]


if __name__ == "__main__":
    nums = [4, 2, 1, 3, 5]
    assert quick_sort(nums) == sorted(nums)
