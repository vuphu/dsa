// nums is already sorted
fn binary_search(nums: &Vec<i32>, target: i32) -> bool {
    let (mut left, mut right) = (0, nums.len() - 1);

    while left < right {
        let mid = (left + right) / 2;
        if nums[mid] == target {
            return true;
        } else if nums[mid] > target {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    false
}

fn main() {
    let nums = vec![1, 2, 4, 8, 16, 32, 64, 128];

    assert!(binary_search(&nums, 32) == true);
    assert!(binary_search(&nums, 31) == false);
}
