#include <vector>
#include <queue>
#include <cassert>

bool is_bipartite(int n, const std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<int>> graph(n);
    std::vector<int> colors(n, -1);

    for (const auto &edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int node = 0; node < n; ++node) {
        if (colors[node] == -1) {
            std::queue<int> queue;
            queue.push(node);
            colors[node] = 0;

            while (!queue.empty()) {
                int current = queue.front();
                queue.pop();

                for (int neighbor : graph[current]) {
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[current];
                        queue.push(neighbor);
                    } else if (colors[neighbor] == colors[current]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    assert(is_bipartite(4, edges) == true);

    edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    assert(is_bipartite(5, edges) == false);

    return 0;
}
