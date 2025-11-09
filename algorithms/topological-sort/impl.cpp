#include <vector>
#include <unordered_map>
#include <cassert>

std::vector<int> topologicalSort(int n, const std::vector<std::pair<int, int>>& edges) {
    std::unordered_map<int, std::vector<int>> graph;
    std::vector<bool> visited(n, false);
    std::vector<int> stack;

    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
    }

    auto dfs = [&](auto &&self, int node) -> void {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                self(self, neighbor);
            }
        }
        stack.push_back(node);
    };

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            dfs(dfs, v);
        }
    }

    reverse(stack.rbegin(), stack.rend());
    return stack;
}

int main() {
    int n = 6;
    std::vector<std::pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    assert(topologicalSort(n, edges) == (std::vector<int>{0, 1, 2, 3, 4, 5}));
    return 0;
}
