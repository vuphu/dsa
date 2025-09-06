fn merge(fronts: &Vec<i32>, backs: &Vec<i32>) -> Vec<i32> {
    let mut nums = vec![];
    let (mut i, mut j) = (0, 0);

    while i < fronts.len() && j < backs.len() {
        if fronts[i] <= backs[j] {
            nums.push(fronts[i]);
            i += 1;
        } else {
            nums.push(backs[j]);
            j += 1;
        }
    }

    while i < fronts.len() {
        nums.push(fronts[i]);
        i += 1;
    }

    while j < backs.len() {
        nums.push(backs[j]);
        j += 1;
    }

    return nums;
}

fn merge_sort(nums: &mut Vec<i32>) {
    let n = nums.len();
    let mid = n / 2;

    if n <= 1 {
        return;
    }

    let (mut fronts, mut backs) = (nums[..mid].to_vec(), nums[mid..].to_vec());
    merge_sort(&mut fronts);
    merge_sort(&mut backs);

    let sorted_nums = merge(&fronts, &backs);
    nums.copy_from_slice(&sorted_nums);
}

fn main() {
    let mut nums = vec![4, 2, 1, 3, 5];

    merge_sort(&mut nums);

    assert!(nums.is_sorted());
}
