fn bucket_sort(nums: &mut Vec<f64>) {
    let n = nums.len();
    let mut buckets: Vec<Vec<f64>> = vec![Vec::new(); n];

    for &num in nums.iter() {
        let index = (num * n as f64) as usize;
        buckets[index].push(num);
    }

    for bucket in buckets.iter_mut() {
        bucket.sort_by(f64::total_cmp);
    }

    nums.clear();
    for bucket in buckets {
        nums.extend(bucket);
    }
}

fn main() {
    let mut nums = vec![0.5, 0.99, 0.75, 0.25, 0.01];

    bucket_sort(&mut nums);

    assert!(nums.is_sorted());
}
