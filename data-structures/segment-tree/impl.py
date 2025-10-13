import math


class SegmentTree:
    def __init__(self, nums: list[int]):
        self.n = len(nums)
        self.tree = [0] * (2 * self.n)
        self.build(nums)

    def build(self, nums: list[int]):
        for i in range(self.n):
            self.tree[self.n + i] = nums[i]
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = min(self.tree[2 * i], self.tree[2 * i + 1])

    def update(self, pos: int, value: int):
        pos += self.n
        self.tree[pos] = value
        while pos > 1:
            pos //= 2
            self.tree[pos] = min(self.tree[2 * pos], self.tree[2 * pos + 1])

    def range_min_query(self, start_at: int, end_at: int) -> int:
        start_at += self.n
        end_at += self.n + 1
        value = math.inf

        while start_at < end_at:
            if start_at % 2 == 1:
                value = min(value, self.tree[start_at])
                start_at += 1
            if end_at % 2 == 1:
                end_at -= 1
                value = min(value, self.tree[end_at])
            start_at //= 2
            end_at //= 2

        return value


if __name__ == "__main__":
    nums = [1, 3, 2, 7, 9, 11, 3, 5, 6, 4, 8]
    segment_tree = SegmentTree(nums)

    assert segment_tree.range_min_query(0, 5) == 1

    segment_tree.update(0, 10)
    assert segment_tree.range_min_query(0, 5) == 2
