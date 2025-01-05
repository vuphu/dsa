from typing import List


def merge(fronts: List[int], backs: List[int]) -> List[int]:
    nums = []
    i, j = 0, 0

    while i < len(fronts) and j < len(backs):
        if fronts[i] <= backs[j]:
            nums.append(fronts[i])
            i += 1
        else:
            nums.append(backs[j])
            j += 1

    nums.extend(fronts[i:])
    nums.extend(backs[j:])

    return nums


def merge_sort(nums: List[int]) -> List[int]:
    n = len(nums)
    mid = n // 2

    if n <= 1:
        return nums

    fronts = merge_sort(nums[:mid])
    backs = merge_sort(nums[mid:])

    return merge(fronts, backs)


if __name__ == "__main__":
    nums = [4, 2, 1, 3, 5]
    assert merge_sort(nums) == sorted(nums)
