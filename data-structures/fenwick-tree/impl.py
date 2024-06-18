from typing import Callable


class FenwickTree:
    def __init__(self, n: int, func: Callable):
        self.tree = [0] * n
        self.func = func

    def bit_range(self, pos: int, down: bool = True):
        while pos >= 0 and pos < len(self.tree):
            yield pos
            pos = (pos & (pos + 1)) - 1 if down else pos | (pos + 1)

    def query(self, pos: int, initial_val: int):
        ans = initial_val
        for i in self.bit_range(pos):
            ans = self.func(ans, self.tree[i])
        return ans

    def update(self, pos: int, val: int):
        for i in self.bit_range(pos, False):
            self.tree[i] = self.func(self.tree[i], val)


if __name__ == "__main__":
    fenwick_tree = FenwickTree(10, lambda x, y: x + y)
    fenwick_tree.update(0, 5)
    fenwick_tree.update(1, 3)
    print(fenwick_tree.query(1, 0))
