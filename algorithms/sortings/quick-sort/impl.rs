fn bucket_sort(nums: &mut Vec<i32>) {}

fn main() {
    let mut nums = vec![4, 2, 1, 3, 5];

    bucket_sort(&mut nums);

    assert!(nums.is_sorted());
}
