use std::cmp::max;

fn longest_subsequence(nums: &Vec<i32>) -> usize {
    let n = nums.len();
    let mut dp = vec![0; n];

    dp[0] = 1;
    for i in 1..n {
        let mut length = 0;
        for j in 0..i {
            if nums[j] < nums[i] {
                length = max(length, dp[j]);
            }
        }
        dp[i] = length + 1;
    }

    *dp.iter().max().unwrap_or(&0)
}

fn fast_longest_subsequence(nums: &Vec<i32>) -> usize {
    let mut stack: Vec<i32> = vec![];
    for &num in nums {
        if stack.is_empty() || *stack.last().unwrap() < num {
            stack.push(num);
        } else {
            let pos = stack.binary_search(&num).unwrap_or_else(|pos| pos);
            stack[pos] = num;
        }
    }
    return stack.len();
}

fn main() {
    let nums = vec![10, 9, 2, 5, 3, 7, 101, 18];

    assert!(longest_subsequence(&nums) == 4);
    assert!(fast_longest_subsequence(&nums) == 4);
}
