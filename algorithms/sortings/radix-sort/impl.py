def counting_sort(nums: list[int], exp: int) -> list[int]:
    n = len(nums)
    counter = [0] * 10
    sorted_nums = [0] * n

    for num in nums:
        bucket = (num // exp) % 10
        counter[bucket] += 1

    for i in range(1, 10):
        counter[i] += counter[i - 1]

    for i in range(n - 1, -1, -1):
        bucket = (nums[i] // exp) % 10
        sorted_nums[counter[bucket] - 1] = nums[i]
        counter[bucket] -= 1

    return sorted_nums


def radix_sort(nums: list[int]) -> list[int]:
    max_num = max(nums)
    exp = 1

    while max_num // exp > 0:
        nums = counting_sort(nums, exp)
        exp *= 10

    return nums


if __name__ == "__main__":
    nums = [64, 2, 16, 512, 1024]
    assert radix_sort(nums) == sorted(nums)
