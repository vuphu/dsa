fn counting_sort(nums: &Vec<i32>, exp: i32) -> Vec<i32> {
    let n = nums.len();
    let mut counter = vec![0; 10];
    let mut sorted_nums = vec![0; n];

    for &num in nums.iter() {
        let bucket = (num / exp) % 10;
        counter[bucket as usize] += 1;
    }

    for i in 1..10 {
        counter[i] += counter[i - 1];
    }

    for i in (0..n).rev() {
        let bucket = (nums[i] / exp) % 10;
        sorted_nums[counter[bucket as usize] - 1] = nums[i];
        counter[bucket as usize] -= 1;
    }

    return sorted_nums;
}

fn radix_sort(nums: &mut Vec<i32>) {
    let max_num = *nums.iter().max().unwrap();
    let mut exp = 1;

    while max_num / exp > 0 {
        *nums = counting_sort(&nums, exp);
        exp *= 10;
    }
}

fn main() {
    let mut nums = vec![64, 2, 16, 512, 1024];

    radix_sort(&mut nums);

    assert!(nums.is_sorted());
}
