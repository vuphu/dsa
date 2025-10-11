use std::collections::HashMap;

fn build_graph(edges: &Vec<(i32, i32)>) -> HashMap<i32, Vec<i32>> {
    let mut graph = HashMap::new();
    for &(u, v) in edges {
        graph.entry(u).or_insert_with(Vec::new).push(v);
        graph.entry(v).or_insert_with(Vec::new).push(u);
    }
    graph
}

fn find_eulerian_circuit(edges: Vec<(i32, i32)>) -> Vec<i32> {
    let mut graph = build_graph(&edges);

    if graph.values().any(|neighbors| neighbors.len() % 2 != 0) {
        return vec![];
    }

    fn traverse(graph: &mut HashMap<i32, Vec<i32>>, node: i32, path: &mut Vec<i32>) {
        let mut stack = vec![node];
        while let Some(&u) = stack.last() {
            if let Some(neighbors) = graph.get_mut(&u) {
                if !neighbors.is_empty() {
                    let node = neighbors.pop().unwrap();
                    graph
                        .get_mut(&node)
                        .map(|nodes| nodes.retain(|&it| it != u));
                    stack.push(node);
                } else {
                    path.push(stack.pop().unwrap());
                }
            }
        }
    }

    let start_node = *graph.keys().min().unwrap();
    let mut path = Vec::new();
    traverse(&mut graph, start_node, &mut path);

    if path.len() != edges.len() + 1 {
        return vec![];
    }

    path.reverse();
    path
}

fn main() {
    let edges = vec![(0, 1), (1, 2), (2, 0)];
    let circuit = find_eulerian_circuit(edges);
    assert_eq!(circuit, vec![0, 2, 1, 0]);
}
