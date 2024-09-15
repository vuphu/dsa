from typing import List

import math
from collections import defaultdict


class SqrtDecomposition:
    def __init__(self, nums: List[int]):
        n = len(nums)
        self.nums = nums
        self.block_size = int(math.sqrt(n))
        self.blocks = [defaultdict(int) for _ in range((n + self.block_size - 1) // self.block_size)]

        for i in range(n):
            block_index = i // self.block_size
            self.blocks[block_index][nums[i]] += 1

    def query(self, left: int, right: int, k: int) -> int:
        left_block = left // self.block_size
        right_block = right // self.block_size
        value_count = 0

        if left_block == right_block:
            value_count = self.nums[left: right + 1].count(k)
        else:
            end_of_left_block = (left_block + 1) * self.block_size
            start_of_right_block = right_block * self.block_size

            value_count += self.nums[left: end_of_left_block].count(k)
            value_count += self.nums[start_of_right_block: right + 1].count(k)
            for block_id in range(left_block + 1, right_block):
                value_count += self.blocks[block_id][k]

        return value_count


if __name__ == "__main__":
    nums = [1, 2, 1, 3, 2, 1, 3, 1, 2]
    sd = SqrtDecomposition(nums)
    assert sd.query(2, 6, 1) == 2
    assert sd.query(2, 7, 1) == 3
