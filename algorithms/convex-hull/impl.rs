fn cross_product(point1: &(i32, i32), point2: &(i32, i32), point3: &(i32, i32)) -> i64 {
    (point2.0 - point1.0) as i64 * (point3.1 - point1.1) as i64
        - (point3.0 - point1.0) as i64 * (point2.1 - point1.1) as i64
}

fn convex_hull(mut points: Vec<(i32, i32)>) -> Vec<(i32, i32)> {
    let n = points.len();

    if n <= 3 {
        return points;
    }

    points.sort();
    let mut hull: Vec<(i32, i32)> = Vec::new();

    for &point in &points {
        while hull.len() >= 2
            && cross_product(&hull[hull.len() - 2], &hull[hull.len() - 1], &point) > 0
        {
            hull.pop();
        }
        hull.push(point);
    }

    let hull_size = hull.len();
    for i in (0..n - 1).rev() {
        let point = points[i];
        while hull.len() > hull_size
            && cross_product(&hull[hull.len() - 2], &hull[hull.len() - 1], &point) > 0
        {
            hull.pop();
        }
        hull.push(point);
    }

    hull.pop();
    hull
}

fn main() {
    let points = vec![(1, 1), (2, 2), (2, 0), (2, 4), (3, 3), (4, 2)];

    let mut hull = convex_hull(points);
    hull.sort();

    assert_eq!(hull, vec![(1, 1), (2, 0), (2, 4), (3, 3), (4, 2)]);
}
