fn next_permutation(nums: &mut Vec<i32>) {
    let n = nums.len();
    let mut i = n as isize - 2;

    while i >= 0 && nums[i as usize] >= nums[i as usize + 1] {
        i -= 1;
    }

    if i >= 0 {
        let mut j = n as isize - 1;
        while nums[j as usize] <= nums[i as usize] {
            j -= 1;
        }
        nums.swap(i as usize, j as usize);
    }

    nums[(i + 1) as usize..].reverse();
}

fn main() {
    let mut nums = vec![1, 2, 3, 4, 5];

    next_permutation(&mut nums);
    assert!(nums == vec![1, 2, 3, 5, 4]);

    next_permutation(&mut nums);
    assert!(nums == vec![1, 2, 4, 3, 5]);
}
