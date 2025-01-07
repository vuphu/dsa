from typing import List


def topological_sort(n: int, edges: List[List[int]]) -> List[int]:
    pass


if __name__ == "__main__":
    n = 6
    edges = [[1, 2], [2, 3], [3, 4], [4, 5]]
    assert topological_sort(n, edges) == [1, 2, 3, 4, 5]
