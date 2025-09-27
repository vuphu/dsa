#include <climits>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>

std::vector<int> dijkstra(int n, std::vector<std::vector<int>> edges, int node) {
    std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heap;
    std::vector<int> dist(n, INT_MAX);

    for (auto const &edge : edges) {
        graph[edge[0]].push_back(std::make_pair(edge[1], edge[2]));
        graph[edge[1]].push_back(std::make_pair(edge[0], edge[2]));
    }

    dist[node] = 0;
    heap.push(std::make_pair(0, node));

    while (!heap.empty()) {
        auto[d, u] = heap.top();
        heap.pop();

        if (dist[u] < d) {
            continue;
        }

        for (const auto[v, w] : graph[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                heap.push(std::make_pair(d + w, v));
            }
        }
    }

    return dist;
}

int main() {
    int n = 4;
    std::vector<std::vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};

    std::vector<int> dist = dijkstra(n, edges, 0);
    assert(dist == (std::vector<int>{0, 3, 4, 5}));

    return 0;
}