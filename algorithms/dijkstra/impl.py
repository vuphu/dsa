import collections
import heapq

INF = 10 ** 18


def dijkstra(n: int, edges: list[list[int]], node: int) -> list[int]:
    graph = collections.defaultdict(list)
    heap = []
    dist = [INF] * n

    for u, v, w in edges:
        graph[u].append((v, w))
        graph[v].append((u, w))

    dist[node] = 0
    heapq.heappush(heap, (0, node))

    while heap:
        d, u = heapq.heappop(heap)
        if dist[u] < d:
            continue
        for v, w in graph[u]:
            if d + w < dist[v]:
                dist[v] = d + w
                heapq.heappush(heap, (d + w, v))

    return dist


if __name__ == "__main__":
    n = 4
    edges = [[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]]

    dist = dijkstra(n, edges, 0)
    assert dist == [0, 3, 4, 5]
