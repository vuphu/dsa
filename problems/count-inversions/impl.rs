use std::collections::{BTreeSet, HashMap};

// naive solution
fn count_inversions(nums: &Vec<i32>) -> i32 {
    let n = nums.len();
    let mut inversion_count = 0;

    for i in 0..n {
        for j in (i + 1)..n {
            if nums[i] > nums[j] {
                inversion_count += 1;
            }
        }
    }

    inversion_count
}

// optimal solution use binary search
// notes: the time complexity is O(N²); we can use third-party libraries for optimization
fn count_inversions_bs(nums: &Vec<i32>) -> i32 {
    let mut sorted_nums: Vec<i32> = vec![];
    let mut inversion_count = 0;

    for &num in nums.iter().rev() {
        let pos = sorted_nums.partition_point(|&x| x < num);
        inversion_count += pos as i32;
        sorted_nums.insert(pos, num);
    }

    inversion_count
}

// optimal solution use BIT (Binary Indexed Tree or Fenwick Tree)
fn count_inversions_bit(nums: &Vec<i32>) -> i32 {
    let n = nums.len();
    let mut bit = vec![0; n + 1];
    let mut ranks: HashMap<i32, usize> = HashMap::new();
    let mut inversion_count = 0;

    let unique_nums = nums.iter().cloned().collect::<BTreeSet<_>>();
    let mut rank = 1;
    for &num in unique_nums.iter() {
        ranks.insert(num, rank);
        rank += 1;
    }

    fn update(bit: &mut Vec<i32>, mut i: isize) {
        let n = bit.len() - 1;
        while i <= n as isize {
            bit[i as usize] += 1;
            i += i & (-i);
        }
    }

    fn query(bit: &Vec<i32>, mut i: isize) -> i32 {
        let mut s = 0;
        while i > 0 {
            s += bit[i as usize];
            i -= i & (-i)
        }
        s
    }

    for &num in nums.iter().rev() {
        let rank = ranks[&num] as isize;
        inversion_count += query(&bit, rank - 1);
        update(&mut bit, rank);
    }

    inversion_count
}

fn main() {
    let nums = vec![5, 4, 3, 2, 1, 2, 3, 4, 5];

    assert_eq!(count_inversions(&nums), 16);
    assert_eq!(count_inversions_bs(&nums), 16);
    assert_eq!(count_inversions_bit(&nums), 16);
}
