struct FenwickTree {
    tree: Vec<i32>,
    n: usize,
}

impl FenwickTree {
    fn new(n: usize) -> Self {
        FenwickTree {
            tree: vec![0; n],
            n,
        }
    }

    fn update(&mut self, mut pos: usize, value: i32) {
        while pos < self.n {
            self.tree[pos] += value;
            pos = pos | (pos + 1);
        }
    }

    fn query(&self, mut pos: isize) -> i32 {
        let mut total = 0;
        while pos >= 0 {
            total += self.tree[pos as usize];
            pos = (pos & (pos + 1)) - 1;
        }
        total
    }
}

fn main() {
    let mut fenwick_tree = FenwickTree::new(10);
    fenwick_tree.update(0, 5);
    fenwick_tree.update(1, 3);

    assert_eq!(fenwick_tree.query(1), 8);
}
