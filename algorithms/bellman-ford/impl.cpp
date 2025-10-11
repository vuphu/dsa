#include <vector>
#include <cassert>
#include <climits>

std::vector<int> bellman_ford(int n, std::vector<std::vector<int>> edges, int node) {
    std::vector<int> dist(n, INT_MAX);
    dist[node] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return std::vector<int>();
        }
    }

    return dist;
}

int main() {
    int n = 5;
    std::vector<std::vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    assert(bellman_ford(n, edges, 0) == (std::vector<int>{0, -1, 2, -2, 1}));
}