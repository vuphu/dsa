fn insertion_sort(nums: &mut Vec<i32>) {
    let n = nums.len();

    for i in 1..n {
        let value = nums[i];
        let mut j = i;
        while j > 0 && nums[j - 1] > value {
            nums[j] = nums[j - 1];
            j -= 1;
        }
        nums[j] = value;
    }
}

fn main() {
    let mut nums = vec![4, 2, 1, 3, 5];

    insertion_sort(&mut nums);

    assert!(nums.is_sorted());
}
