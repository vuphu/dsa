class FenwickTree:
    def __init__(self, n: int):
        self.tree = [0] * n

    def tree_range(self, pos: int, down: bool = True):
        while 0 <= pos < len(self.tree):
            yield pos
            pos = (pos & (pos + 1)) - 1 if down else pos | (pos + 1)

    def query(self, pos: int):
        total = 0
        for i in self.tree_range(pos):
            total = total + self.tree[i]
        return total

    def update(self, pos: int, value: int):
        for i in self.tree_range(pos, False):
            self.tree[i] = self.tree[i] + value


if __name__ == "__main__":
    fenwick_tree = FenwickTree(10)
    fenwick_tree.update(0, 5)
    fenwick_tree.update(1, 3)

    assert fenwick_tree.query(1) == 8
