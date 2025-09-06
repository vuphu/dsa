fn partition(nums: &mut Vec<i32>, low: usize, high: usize) -> usize {
    let pivot = nums[high];
    let mut i: i32 = low as i32 - 1;

    for j in low..high {
        if nums[j] < pivot {
            i += 1;
            nums.swap(i as usize, j)
        }
    }

    nums.swap((i + 1) as usize, high);
    (i + 1) as usize
}

fn quick_sort(nums: &mut Vec<i32>) {
    fn sort_partition(nums: &mut Vec<i32>, low: usize, high: usize) {
        if low < high {
            let pivot_index = partition(nums, low, high);
            if pivot_index > 0 {
                sort_partition(nums, low, pivot_index - 1);
            }
            sort_partition(nums, pivot_index, high);
        }
    }
    sort_partition(nums, 0, nums.len() - 1);
}

fn main() {
    let mut nums = vec![4, 2, 1, 3, 5];

    quick_sort(&mut nums);

    assert!(nums.is_sorted());
}
