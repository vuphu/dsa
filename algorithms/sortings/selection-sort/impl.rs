fn selection_sort(nums: &mut Vec<i32>) {
    let n = nums.len();

    for i in 0..n {
        let mut min_index = i;
        for j in (i + 1)..n {
            if nums[j] < nums[min_index] {
                min_index = j;
            }
        }
        nums.swap(i, min_index);
    }
}

fn main() {
    let mut nums = vec![4, 2, 1, 3, 5];

    selection_sort(&mut nums);

    assert!(nums.is_sorted());
}
