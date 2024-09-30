from typing import List


def cross_product(point1: List[int], point2: List[int], point3: List[int]) -> int:
    return (point2[0] - point1[0]) * (point3[1] - point1[1]) - (point3[0] - point1[0]) * (point2[1] - point1[1])


def convex_hull(points: List[List[int]]) -> List[List[int]]:
    n = len(points)

    points = sorted(points)
    hull = [points[0]]

    for i in range(1, n):
        while len(hull) >= 2 and cross_product(hull[-2], hull[-1], points[i]) > 0:
            hull.pop()
        hull.append(points[i])

    for i in range(n - 2, -1, -1):
        while len(hull) >= 2 and cross_product(hull[-2], hull[-1], points[i]) > 0:
            hull.pop()
        hull.append(points[i])

    if n > 1:
        hull.pop()

    return hull


if __name__ == "__main__":
    points = [[1, 1], [2, 2], [2, 0], [2, 4], [3, 3], [4, 2]]
    hull = sorted(convex_hull(points))
    assert hull == [[1, 1], [2, 0], [2, 4], [3, 3], [4, 2]]
