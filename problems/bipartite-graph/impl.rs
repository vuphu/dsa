use std::collections::VecDeque;

fn is_bipartite(n: usize, edges: &Vec<(usize, usize)>) -> bool {
    let mut graph = vec![Vec::new(); n];
    let mut colors = vec![-1; n];

    for &(u, v) in edges {
        graph[u].push(v);
        graph[v].push(u);
    }

    for node in 0..n {
        if colors[node] == -1 {
            let mut queue = VecDeque::new();
            queue.push_back(node);
            colors[node] = 0;

            while let Some(current) = queue.pop_front() {
                for &neighbor in &graph[current] {
                    if colors[neighbor] == -1 {
                        colors[neighbor] = 1 - colors[current];
                        queue.push_back(neighbor);
                    } else if colors[neighbor] == colors[current] {
                        return false;
                    }
                }
            }
        }
    }

    true
}

fn main() {
    let mut edges = vec![(0, 1), (1, 2), (2, 3), (3, 0)];
    assert!(is_bipartite(4, &edges));

    edges = vec![(0, 1), (1, 2), (2, 3), (3, 4), (4, 0)];
    assert!(!is_bipartite(5, &edges));
}
