import math
from typing import List


def bellman_ford(n: int, edges: List[List[int]], src: int) -> List[float] | None:
    dist = [math.inf] * n
    dist[src] = 0

    for _ in range(n - 1):
        for u, v, w in edges:
            if dist[u] != math.inf and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for u, v, w in edges:
        if dist[u] != math.inf and dist[u] + w < dist[v]:
            return None

    return dist


if __name__ == "__main__":
    n = 4
    edges = [[0, 1, -1], [0, 2, 4], [1, 2, 3], [1, 3, 2], [1, 4, 2], [3, 2, 5], [3, 1, 1], [4, 3, -3]]

    dist = bellman_ford(5, edges, 0)
    assert dist == [0, -1, 2, -2, 1]
