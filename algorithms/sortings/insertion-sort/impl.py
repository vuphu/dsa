from typing import List


def insertion_sort(nums: List[int]) -> List[int]:
    n = len(nums)

    for i in range(1, n):
        value = nums[i]
        j = i - 1
        while j >= 0 and nums[j] > value:
            nums[j + 1] = nums[j]
            j -= 1
        nums[j + 1] = value

    return nums



if __name__ == "__main__":
    nums = [4, 2, 1, 3, 5]
    assert insertion_sort(nums) == sorted(nums)
