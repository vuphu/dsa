import collections

def find_subset_sums(nums: list[int]) -> list[int]:
    sums = []

    def attempt(i: int, s: int) -> None:
        if i == len(nums):
            sums.append(s)
            return
        attempt(i + 1, s)
        attempt(i + 1, s + nums[i])

    attempt(0, 0)
    return sums


def count_target_subsets(nums: list[int], target: int) -> int:
    n = len(nums)
    front_sums = find_subset_sums(nums[:n // 2])
    back_sums = find_subset_sums(nums[n // 2:])
    back_sum_counter = collections.Counter(back_sums)
    return sum([back_sum_counter[target - s] for s in front_sums])


if __name__ == "__main__":
    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    assert count_target_subsets(nums, 10) == 10
