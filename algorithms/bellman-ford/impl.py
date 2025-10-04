INF = 10 ** 18


def bellman_ford(n: int, edges: list[list[int]], node: int) -> list[int]:
    dist = [INF] * n
    dist[node] = 0

    for _ in range(n - 1):
        for u, v, w in edges:
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for u, v, w in edges:
        if dist[u] != INF and dist[u] + w < dist[v]:
            return []

    return dist


if __name__ == "__main__":
    n = 5
    edges = [[0, 1, -1], [0, 2, 4], [1, 2, 3], [1, 3, 2], [1, 4, 2], [3, 2, 5], [3, 1, 1], [4, 3, -3]]

    assert bellman_ford(n, edges, 0) == [0, -1, 2, -2, 1]
