use std::collections::HashMap;

fn topological_sort(n: usize, edges: &Vec<(usize, usize)>) -> Vec<usize> {
    let mut graph: HashMap<usize, Vec<usize>> = HashMap::new();
    let mut visited = vec![false; n];
    let mut stack = vec![];

    for &(u, v) in edges {
        graph.entry(u).or_default().push(v);
    }

    fn dfs(
        node: usize,
        graph: &HashMap<usize, Vec<usize>>,
        visited: &mut Vec<bool>,
        stack: &mut Vec<usize>,
    ) {
        visited[node] = true;
        for &neighbor in graph.get(&node).unwrap_or(&Vec::new()) {
            if !visited[neighbor] {
                dfs(neighbor, graph, visited, stack);
            }
        }
        stack.push(node);
    }

    for v in 0..n {
        if !visited[v] {
            dfs(v, &graph, &mut visited, &mut stack);
        }
    }

    stack.reverse();
    stack
}

fn main() {
    let n = 6;
    let edges = vec![(0, 1), (0, 2), (1, 2), (2, 3), (3, 4), (4, 5)];
    assert!(topological_sort(n, &edges) == vec![0, 1, 2, 3, 4, 5]);
}
