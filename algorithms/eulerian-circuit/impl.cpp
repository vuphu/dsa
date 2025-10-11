#include <functional>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

std::map<int, std::vector<int>> build_graph(const std::vector<std::pair<int, int>> &edges) {
    std::map<int, std::vector<int>> graph;
    for (const auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

std::vector<int> find_eulerian_circuit(const std::vector<std::pair<int, int>> &edges) {
    auto graph = build_graph(edges);

    for (const auto &item : graph) {
        if (item.second.size() % 2 != 0)
            return std::vector<int>();
    }

    std::function<void(int, std::vector<int> &)> traverse = [&](int node, std::vector<int> &path) -> void {
        std::vector<int> stack = {node};
        while (!stack.empty()) {
            int u = stack.back();
            if (!graph[u].empty()) {
                int node = graph[u].back();
                graph[u].pop_back();
                graph[node].erase(std::find(graph[node].begin(), graph[node].end(), u));
                stack.push_back(node);
            } else {
                path.push_back(stack.back());
                stack.pop_back();
            }
        }
    };

    int start_node = graph.begin()->first;
    std::vector<int> path;
    traverse(start_node, path);

    if (path.size() != edges.size() + 1) {
        return std::vector<int>();
    }

    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    std::vector<std::pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}};

    std::vector<int> circuit = find_eulerian_circuit(edges);
    assert(circuit == (std::vector<int>{0, 2, 1, 0}));

    return 0;
}
