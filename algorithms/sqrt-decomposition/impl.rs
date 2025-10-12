use std::collections::HashMap;

struct SqrtDecomposition {
    nums: Vec<i32>,
    block_size: usize,
    blocks: Vec<HashMap<i32, i32>>,
}

impl SqrtDecomposition {
    fn new(nums: Vec<i32>) -> Self {
        let n = nums.len();
        let block_size = (n as f64).sqrt() as usize;
        let mut blocks = vec![HashMap::new(); (n + block_size - 1) / block_size];

        for (i, &value) in nums.iter().enumerate() {
            let block_index = i / block_size;
            *blocks[block_index].entry(value).or_insert(0) += 1;
        }

        Self {
            nums,
            block_size,
            blocks,
        }
    }

    fn query(&self, left: usize, right: usize, k: i32) -> i32 {
        let left_block = left / self.block_size;
        let right_block = right / self.block_size;
        let mut value_count = 0;

        if left_block == right_block {
            value_count = self.nums[left..=right].iter().filter(|&&x| x == k).count() as i32;
        } else {
            let end_of_left_block = (left_block + 1) * self.block_size;
            let start_of_right_block = right_block * self.block_size;

            value_count += self.nums[left..end_of_left_block]
                .iter()
                .filter(|&&x| x == k)
                .count() as i32;
            value_count += self.nums[start_of_right_block..=right]
                .iter()
                .filter(|&&x| x == k)
                .count() as i32;

            for block_id in (left_block + 1)..right_block {
                value_count += *self.blocks[block_id].get(&k).unwrap_or(&0);
            }
        }

        value_count
    }
}

fn main() {
    let nums = vec![1, 2, 1, 3, 2, 1, 3, 1, 2];
    let sd = SqrtDecomposition::new(nums);
    assert_eq!(sd.query(2, 6, 1), 2);
    assert_eq!(sd.query(2, 7, 1), 3);
}
