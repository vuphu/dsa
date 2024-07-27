import collections
import heapq
import math
from typing import List


# noinspection PyShadowingNames
def dijkstra(n: int, graph: dict, node: int) -> List[float]:
    dist = [math.inf] * n
    dist[node] = 0
    heap = []
    heapq.heappush(heap, (0, node))

    while heap:
        d, u = heapq.heappop(heap)
        for v, w in graph[u]:
            if d + w < dist[v]:
                dist[v] = d + w
                heapq.heappush(heap, (d + w, v))

    return dist


if __name__ == "__main__":
    n = 4
    edges = [[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]]
    graph = collections.defaultdict(list)

    for u, v, w in edges:
        graph[u].append((v, w))
        graph[v].append((u, w))

    dist = dijkstra(n, graph, 0)
    print(dist[3])
