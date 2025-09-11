use std::cmp::{max, min};

fn maximum_distance(points: &Vec<Vec<i32>>) -> i32 {
    let n = points.len();
    let mut ans = i32::MIN;

    for i in 0..n {
        for j in (i + 1)..n {
            let distance =
                (points[i][0] - points[j][0]).abs() + (points[i][1] - points[j][1]).abs();
            ans = max(ans, distance);
        }
    }

    ans
}

// optimal solution
fn optimal_maximum_distance(points: &Vec<Vec<i32>>) -> i32 {
    let (mut min_sum, mut min_diff) = (i32::MAX, i32::MAX);
    let (mut max_sum, mut max_diff) = (i32::MIN, i32::MIN);

    for point in points.iter() {
        let (sum, diff) = (point[0] + point[1], point[0] - point[1]);
        min_sum = min(min_sum, sum);
        max_sum = max(max_sum, sum);
        min_diff = min(min_diff, diff);
        max_diff = max(max_diff, diff);
    }

    max(max_sum - min_sum, max_diff - min_diff)
}

fn main() {
    let points = vec![vec![0, 0], vec![0, 1], vec![1, 0], vec![2, 2]];
    assert!(maximum_distance(&points) == 4);
    assert!(optimal_maximum_distance(&points) == 4);
}
