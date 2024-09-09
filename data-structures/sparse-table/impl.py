from typing import List


# noinspection PyShadowingNames
class SparseTable:
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.n = len(nums)
        self.log = [0] * (self.n + 1)
        self.build_log()
        self.sparse_table = self.build_sparse_table()

    def build_log(self):
        for i in range(2, self.n + 1):
            self.log[i] = self.log[i // 2] + 1

    def build_sparse_table(self):
        k = self.log[self.n] + 1
        st = [[0] * k for _ in range(self.n)]
        
        for i in range(self.n):
            st[i][0] = self.nums[i]
        
        j = 1
        while (1 << j) <= self.n:
            i = 0
            while (i + (1 << j) - 1) < self.n:
                st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1])
                i += 1
            j += 1
        
        return st

    def range_min_query(self, start_at: int, end_at: int):
        j = self.log[end_at - start_at + 1]
        return min(self.sparse_table[start_at][j], self.sparse_table[end_at - (1 << j) + 1][j])
    
if __name__ == "__main__":
    nums = [1, 3, 2, 7, 9, 11, 3, 5, 6, 4, 8]
    sparse_table = SparseTable(nums)   

    assert sparse_table.range_min_query(0, 5) == 1
    assert sparse_table.range_min_query(3, 8) == 3