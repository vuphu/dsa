import collections


def is_bipartite(n: int, edges: list[list[int]]) -> bool:
    graph = collections.defaultdict(list)
    colors = [-1] * n

    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    for node in graph:
        if colors[node] == -1:
            queue = collections.deque([node])
            colors[node] = 0

            while queue:
                current = queue.popleft()
                for neighbor in graph[current]:
                    if colors[neighbor] == -1:
                        colors[neighbor] = 1 - colors[current]
                        queue.append(neighbor)
                    elif colors[neighbor] == colors[current]:
                        return False
    return True


if __name__ == '__main__':
    edges = [[0, 1], [1, 2], [2, 3], [3, 0]]
    assert is_bipartite(4, edges) == True

    edges = [[0, 1], [1, 2], [2, 3], [3, 4], [4, 0]]
    assert is_bipartite(5, edges) == False
