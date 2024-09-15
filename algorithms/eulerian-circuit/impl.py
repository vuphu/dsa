import collections
from typing import List


def build_graph(edges: List[List[int]]) -> dict:
    graph = collections.defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    return graph


def find_eulerian_circuit(n: int, edges: List[List[int]]):
    graph = build_graph(edges)

    for vertex in graph:
        if len(graph[vertex]) % 2 != 0:
            return None

    def traverse(node: int, path: List[int]):
        stack = [node]
        while stack:
            u = stack[-1]
            if graph[u]:
                node = graph[u].pop()
                graph[node].remove(u)
                stack.append(node)
            else:
                path.append(stack.pop())

    start_node, path = next(iter(graph)), []
    traverse(start_node, path)

    return path[::-1] if len(path) == len(edges) + 1 else None


if __name__ == "__main__":
    edges = [[0, 1], [1, 2], [2, 0]]
    circuit = find_eulerian_circuit(3, edges)
    assert circuit == [0, 2, 1, 0]
