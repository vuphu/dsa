from typing import List

import math


# naive solution
def maximum_distance(points: List[List[int]]) -> int:
    n = len(points)
    ans = -math.inf

    for i in range(n):
        for j in range(i + 1, n):
            distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
            ans = max(ans, distance)

    return ans


# optimal solution
def optimal_maximum_distance(points: List[List[int]]) -> int:
    min_sum = min_diff = math.inf
    max_sum = max_diff = -math.inf

    for point in points:
        s, diff = point[0] + point[1], point[0] - point[1]
        min_sum = min(min_sum, s)
        max_sum = max(max_sum, s)
        min_diff = min(min_diff, diff)
        max_diff = max(max_diff, diff)

    return max(max_sum - min_sum, max_diff - min_diff)


if __name__ == "__main__":
    points = [[0, 0], [0, 1], [1, 0], [2, 2]]
    assert maximum_distance(points) == 4
    assert optimal_maximum_distance(points) == 4
