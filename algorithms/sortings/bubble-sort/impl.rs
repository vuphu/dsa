fn bubble_sort(nums: &mut Vec<i32>) {
    let n = nums.len();

    for i in 0..n {
        for j in 0..(n - i - 1) {
            if nums[j] > nums[j + 1] {
                nums.swap(j, j + 1);
            }
        }
    }
}

fn main() {
    let mut nums = vec![4, 2, 1, 3, 5];

    bubble_sort(&mut nums);

    assert!(nums.is_sorted());
}
