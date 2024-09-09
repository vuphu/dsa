class UnionFind:
    def __init__(self, n: int) -> None:
        self.parents = list(range(n))
        
    def find_parent(self, u: int) -> int:
        if self.parents[u] != u:
            self.parents[u] = self.find_parent(self.parents[u])
        return self.parents[u]
    
    def unite(self, u: int, v: int) -> None:
        pu = self.find_parent(u)
        pv = self.find_parent(v)
        if pu != pv:
            self.parents[pu] = pv

if __name__ == "__main__":
    union_find = UnionFind(10)
    union_find.unite(1, 2)
    union_find.unite(1, 3)
    union_find.unite(2, 4)

    assert union_find.find_parent(3) == union_find.find_parent(4)