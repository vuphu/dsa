fn next_greater_element(nums: &Vec<i32>) -> Vec<i32> {
    let mut stack: Vec<usize> = vec![];
    let mut next_greater = vec![-1; nums.len()];

    for i in 0..nums.len() {
        while !stack.is_empty() && nums[*stack.last().unwrap()] < nums[i] {
            next_greater[stack.pop().unwrap()] = nums[i];
        }
        stack.push(i);
    }

    next_greater
}

fn main() {
    let nums = vec![4, 1, 2];
    assert!(next_greater_element(&nums) == vec![-1, 2, -1]);
}
