# nums is already sorted
def binary_search(nums: list[int], target: int) -> bool:
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return True
        elif nums[mid] > target:
            right = mid - 1
        else:
            left = mid + 1

    return False


if __name__ == "__main__":
    nums = [1, 2, 4, 8, 16, 32, 64, 128]

    assert binary_search(nums, 32) == True
    assert binary_search(nums, 31) == False
