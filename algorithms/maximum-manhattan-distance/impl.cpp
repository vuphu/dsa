#include <climits>
#include <vector>
#include <algorithm>
#include <cassert>

typedef std::vector<int> Point;

// naive solution
int maximum_distance(const std::vector<Point>& points) {
    int n = points.size();
    int ans = INT_MIN;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int distance = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
            ans = std::max(ans, distance);
        }
    }

    return ans;
}

// optional solution
int optimal_maximum_distance(const std::vector<Point>& points) {
    int min_sum = INT_MAX;
    int min_diff = INT_MAX;
    int max_sum = INT_MIN;
    int max_diff = INT_MIN;

    for (const auto& point : points) {
        int sum = point[0] + point[1];
        int diff = point[0] - point[1];
        min_sum = std::min(min_sum, sum);
        max_sum = std::max(max_sum, sum);
        min_diff = std::min(min_diff, diff);
        max_diff = std::max(max_diff, diff);
    }

    return std::max(max_sum - min_sum, max_diff - min_diff);
}

int main() {
    std::vector<Point> points = {{0, 0}, {0, 1}, {1, 0}, {2, 2}};
    assert(maximum_distance(points) == 4);
    assert(optimal_maximum_distance(points) == 4);
    return 0;
}
