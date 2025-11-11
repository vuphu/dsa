# naive solution
def count_inversions(nums: list[int]) -> int:
    n = len(nums)
    inversion_count = 0

    for i in range(n):
        for j in range(i + 1, n):
            if nums[i] > nums[j]:
                inversion_count += 1

    return inversion_count


# optimal solution use binary search
# notes: the time complexity is O(N²); we can use SortedList (from sortedcontainers) for optimization
def count_inversions_bs(nums: list[int]) -> int:
    import bisect

    sorted_nums = []
    inversion_count = 0

    for num in reversed(nums):
        inversion_count += bisect.bisect_left(sorted_nums, num)
        bisect.insort(sorted_nums, num)

    return inversion_count


# optimal solution use BIT (Binary Indexed Tree or Fenwick Tree)
def count_inversions_bit(nums: list[int]) -> int:
    n = len(nums)
    bit = [0] * (n + 1)
    ranks = {num: i + 1 for i, num in enumerate(sorted(set(nums)))}
    inversion_count = 0

    def update(i: int) -> None:
        while i <= n:
            bit[i] += 1
            i += i & -i

    def query(i: int) -> int:
        s = 0
        while i > 0:
            s += bit[i]
            i -= i & -i
        return s

    for num in reversed(nums):
        rank = ranks[num]
        inversion_count += query(rank - 1)
        update(rank)

    return inversion_count


if __name__ == '__main__':
    nums = [5, 4, 3, 2, 1, 2, 3, 4, 5]

    assert count_inversions(nums) == 16
    assert count_inversions_bs(nums) == 16
    assert count_inversions_bit(nums) == 16
