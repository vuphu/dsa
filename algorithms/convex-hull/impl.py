def cross_product(point1: list[int], point2: list[int], point3: list[int]) -> int:
    return (point2[0] - point1[0]) * (point3[1] - point1[1]) - (point3[0] - point1[0]) * (point2[1] - point1[1])


def convex_hull(points: list[list[int]]) -> list[list[int]]:
    n = len(points)

    if n <= 3:
        return points

    points = sorted(points)
    hull = []

    for point in points:
        while len(hull) >= 2 and cross_product(hull[-2], hull[-1], point) > 0:
            hull.pop()
        hull.append(point)

    hull_size = len(hull)
    for i in range(n - 2, -1, -1):
        p = points[i]
        while len(hull) > hull_size and cross_product(hull[-2], hull[-1], p) > 0:
            hull.pop()
        hull.append(p)

    hull.pop()
    return hull


if __name__ == "__main__":
    points = [[1, 1], [2, 2], [2, 0], [2, 4], [3, 3], [4, 2]]
    hull = sorted(convex_hull(points))
    assert hull == [[1, 1], [2, 0], [2, 4], [3, 3], [4, 2]]
