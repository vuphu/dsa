use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};

fn dijkstra(n: usize, edges: &Vec<(usize, usize, i32)>, node: usize) -> Vec<i32> {
    let mut graph: HashMap<usize, Vec<(usize, i32)>> = HashMap::new();
    let mut heap = BinaryHeap::new();
    let mut dist = vec![i32::MAX; n];

    for &(u, v, w) in edges {
        graph.entry(u).or_default().push((v, w));
        graph.entry(v).or_default().push((u, w));
    }

    dist[node] = 0;
    heap.push((Reverse(0), node));

    while let Some((Reverse(d), u)) = heap.pop() {
        if d > dist[u] {
            continue;
        }
        for &(v, w) in graph.get(&u).unwrap_or(&Vec::new()) {
            if d + w < dist[v] {
                dist[v] = d + w;
                heap.push((Reverse(d + w), v));
            }
        }
    }

    dist
}

fn main() {
    let n = 4;
    let edges = vec![(0, 1, 3), (1, 2, 1), (1, 3, 4), (2, 3, 1)];

    let dist = dijkstra(n, &edges, 0);
    assert!(dist == vec![0, 3, 4, 5])
}
