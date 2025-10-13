use std::cmp::min;

struct SparseTable {
    nums: Vec<i32>,
    n: usize,
    log: Vec<usize>,
    sparse_table: Vec<Vec<i32>>,
}

impl SparseTable {
    fn new(nums: Vec<i32>) -> Self {
        let n = nums.len();
        let mut sparse_table = SparseTable {
            nums,
            n,
            log: vec![0; n + 1],
            sparse_table: Vec::new(),
        };
        sparse_table.build_log();
        sparse_table.build_sparse_table();
        sparse_table
    }

    fn build_log(&mut self) {
        for i in 2..=self.n {
            self.log[i] = self.log[i / 2] + 1;
        }
    }

    fn build_sparse_table(&mut self) {
        let k = self.log[self.n] + 1;
        self.sparse_table = vec![vec![0; k]; self.n];

        for i in 0..self.n {
            self.sparse_table[i][0] = self.nums[i];
        }

        let mut j = 1;
        while (1 << j) <= self.n {
            let mut i = 0;
            while i + (1 << j) - 1 < self.n {
                self.sparse_table[i][j] = min(
                    self.sparse_table[i][j - 1],
                    self.sparse_table[i + (1 << (j - 1))][j - 1],
                );
                i += 1;
            }
            j += 1;
        }
    }

    fn range_min_query(&self, start_at: usize, end_at: usize) -> i32 {
        let j = self.log[end_at - start_at + 1];
        min(
            self.sparse_table[start_at][j],
            self.sparse_table[end_at - (1 << j) + 1][j],
        )
    }
}

fn main() {
    let nums = vec![1, 3, 2, 7, 9, 11, 3, 5, 6, 4, 8];
    let sparse_table = SparseTable::new(nums);

    assert_eq!(sparse_table.range_min_query(0, 5), 1);
    assert_eq!(sparse_table.range_min_query(3, 8), 3);
}
