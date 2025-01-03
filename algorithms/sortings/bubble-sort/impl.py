from typing import List


def bubble_sort(nums: List[int]) -> List[int]:
    n = len(nums)

    for i in range(n):
        for j in range(n - i - 1):
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]

    return nums

if __name__ == "__main__":
    nums = [4, 2, 1, 3, 5]
    assert bubble_sort(nums) == sorted(nums)
