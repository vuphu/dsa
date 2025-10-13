use std::cmp::min;

struct SegmentTree {
    n: usize,
    tree: Vec<i32>,
}

impl SegmentTree {
    fn new(nums: &Vec<i32>) -> Self {
        let n = nums.len();
        let tree = vec![0; 2 * n];
        let mut segment_tree = SegmentTree { n, tree };
        segment_tree.build(nums);
        segment_tree
    }

    fn build(&mut self, nums: &Vec<i32>) {
        for i in 0..self.n {
            self.tree[self.n + i] = nums[i];
        }
        for i in (1..self.n).rev() {
            self.tree[i] = min(self.tree[2 * i], self.tree[2 * i + 1]);
        }
    }

    fn update(&mut self, mut pos: usize, value: i32) {
        pos += self.n;
        self.tree[pos] = value;
        while pos > 1 {
            pos /= 2;
            self.tree[pos] = min(self.tree[2 * pos], self.tree[2 * pos + 1]);
        }
    }

    fn range_min_query(&self, mut start_at: usize, mut end_at: usize) -> i32 {
        start_at += self.n;
        end_at += self.n + 1;
        let mut value = i32::MAX;

        while start_at < end_at {
            if start_at % 2 == 1 {
                value = min(value, self.tree[start_at]);
                start_at += 1;
            }
            if end_at % 2 == 1 {
                end_at -= 1;
                value = min(value, self.tree[end_at]);
            }
            start_at /= 2;
            end_at /= 2;
        }

        value
    }
}

fn main() {
    let nums = vec![1, 3, 2, 7, 9, 11, 3, 5, 6, 4, 8];
    let mut segment_tree = SegmentTree::new(&nums);

    assert_eq!(segment_tree.range_min_query(0, 5), 1);

    segment_tree.update(0, 10);
    assert_eq!(segment_tree.range_min_query(0, 5), 2);
}
