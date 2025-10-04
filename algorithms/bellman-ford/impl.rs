fn bellman_ford(n: usize, edges: &Vec<(usize, usize, i32)>, node: usize) -> Vec<i32> {
    let mut dist = vec![i32::MAX; n];
    dist[node] = 0;

    for _ in 0..(n - 1) {
        for &(u, v, w) in edges {
            if dist[u] != i32::MAX && dist[u] + w < dist[v] {
                dist[v] = dist[u] + w;
            }
        }
    }

    for &(u, v, w) in edges {
        if dist[u] != i32::MAX && dist[u] + w < dist[v] {
            return vec![];
        }
    }

    dist
}

fn main() {
    let n = 5;
    let edges = vec![
        (0, 1, -1),
        (0, 2, 4),
        (1, 2, 3),
        (1, 3, 2),
        (1, 4, 2),
        (3, 2, 5),
        (3, 1, 1),
        (4, 3, -3),
    ];

    assert!(bellman_ford(n, &edges, 0) == vec![0, -1, 2, -2, 1]);
}
