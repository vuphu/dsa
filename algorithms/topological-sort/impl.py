import collections


def topological_sort(n: int, edges: list[list[int]]) -> list[int]:
    graph = collections.defaultdict(list)
    visited = [False] * n
    stack = []

    for u, v in edges:
        graph[u].append(v)

    def dfs(node) -> None:
        visited[node] = True
        for neighbor in graph[node]:
            if not visited[neighbor]:
                dfs(neighbor)
        stack.append(node)

    for v in range(n):
        if not visited[v]:
            dfs(v)

    return stack[::-1]


if __name__ == "__main__":
    n = 6
    edges = [[0, 1], [0, 2], [1, 2], [2, 3], [3, 4], [4, 5]]
    assert topological_sort(n, edges) == [0, 1, 2, 3, 4, 5]
