struct UnionFind {
    parents: Vec<usize>,
}

impl UnionFind {
    pub fn new(n: usize) -> Self {
        Self {
            parents: (0..n).collect::<Vec<_>>(),
        }
    }

    pub fn find_parent(&mut self, u: usize) -> usize {
        if self.parents[u] != u {
            self.parents[u] = self.find_parent(self.parents[u]);
        }
        return self.parents[u];
    }

    pub fn unite(&mut self, u: usize, v: usize) {
        let pu = self.find_parent(u);
        let pv = self.find_parent(v);
        if pu != pv {
            self.parents[pu] = pv;
        }
    }
}

fn main() {
    let mut union_find = UnionFind::new(10);
    union_find.unite(1, 2);
    union_find.unite(1, 3);
    union_find.unite(2, 4);

    assert!(union_find.find_parent(3) == union_find.find_parent(4));
}
