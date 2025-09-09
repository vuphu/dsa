def bucket_sort(nums: list[float]) -> list[float]:
    n = len(nums)
    buckets = [[] for _ in range(n)]
    sorted_nums = []

    for num in nums:
        index = int(num * n)
        buckets[index].append(num)

    for bucket in buckets:
        for num in sorted(bucket):
            sorted_nums.append(num)

    return sorted_nums


if __name__ == "__main__":
    nums = [0.5, 0.99, 0.75, 0.25, 0.01]
    assert bucket_sort(nums) == sorted(nums)
