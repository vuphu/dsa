#include <vector>
#include <algorithm>
#include <cassert>

long long cross_product(const std::vector<int> &point1, const std::vector<int> &point2, const std::vector<int> &point3) {
    return (long long)(point2[0] - point1[0]) * (point3[1] - point1[1]) - (long long)(point3[0] - point1[0]) * (point2[1] - point1[1]);
}

std::vector<std::vector<int>> convex_hull(std::vector<std::vector<int>> &points) {
    int n = points.size();

    if (n <= 3) {
        return points;
    }

    sort(points.begin(), points.end());
    std::vector<std::vector<int>> hull = {};

    for (const auto &point : points) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull[hull.size() - 1], point) > 0)
            hull.pop_back();
        hull.push_back(point);
    }

    int hull_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > hull_size && cross_product(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) > 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back();
    return hull;
}

int main() {
    std::vector<std::vector<int>> points = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};

    std::vector<std::vector<int>> hull = convex_hull(points);
    sort(hull.begin(), hull.end());
    assert(hull == (std::vector<std::vector<int>>{{1, 1}, {2, 0}, {2, 4}, {3, 3}, {4, 2}}));

    return 0;
}
