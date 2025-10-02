use std::collections::HashMap;

fn find_subset_sums(nums: &Vec<i32>) -> Vec<i32> {
    let mut sums = vec![];

    fn attempt(i: usize, s: i32, nums: &Vec<i32>, sums: &mut Vec<i32>) {
        if i == nums.len() {
            sums.push(s);
            return;
        }
        attempt(i + 1, s, nums, sums);
        attempt(i + 1, s + nums[i], nums, sums);
    }

    attempt(0, 0, nums, &mut sums);
    return sums;
}

fn count_target_subsets(nums: &Vec<i32>, target: i32) -> i32 {
    let n = nums.len();
    let front_sums = find_subset_sums(&nums[..(n / 2)].to_vec());
    let back_sums = find_subset_sums(&nums[(n / 2)..].to_vec());

    let mut back_sum_counter: HashMap<i32, i32> = HashMap::new();
    for sum in back_sums {
        *back_sum_counter.entry(sum).or_default() += 1;
    }

    let mut subset_count = 0;
    for sum in front_sums {
        if let Some(value) = back_sum_counter.get(&(target - sum)) {
            subset_count += value;
        }
    }

    subset_count
}

fn main() {
    let nums = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    assert!(count_target_subsets(&nums, 10) == 10);
}
