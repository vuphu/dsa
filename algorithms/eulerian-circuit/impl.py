import collections


def build_graph(edges: list[list[int]]) -> dict[int, list[int]]:
    graph = collections.defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    return graph


def find_eulerian_circuit(edges: list[list[int]]) -> list[int]:
    graph = build_graph(edges)

    for vertex in graph:
        if len(graph[vertex]) % 2 != 0:
            return []

    def traverse(node: int, path: list[int]) -> None:
        stack = [node]
        while stack:
            u = stack[-1]
            if graph[u]:
                node = graph[u].pop()
                graph[node].remove(u)
                stack.append(node)
            else:
                path.append(stack.pop())

    start_node, path = min(graph.keys()), []
    traverse(start_node, path)

    return path[::-1] if len(path) == len(edges) + 1 else []


if __name__ == "__main__":
    edges = [[0, 1], [1, 2], [2, 0]]
    circuit = find_eulerian_circuit(edges)
    assert circuit == [0, 2, 1, 0]
