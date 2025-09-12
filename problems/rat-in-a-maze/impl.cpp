#include <vector>
#include <string>
#include <functional>
#include <cassert>

std::vector<std::string> rat_in_a_maze(std::vector<std::vector<int>> maze) {
    int n = maze.size();
    std::vector<std::tuple<int, int, char>> steps = {
        std::make_tuple(1, 0, 'D'),
        std::make_tuple(0, -1, 'L'),
        std::make_tuple(0, 1, 'R'),
        std::make_tuple(-1, 0, 'U'),
    };
    std::vector<std::string> paths;

    std::function<void(int, int, std::string)> dfs = [&](int r, int c, std::string current_path) {
        if (r == n - 1 && c == n - 1) {
            paths.push_back(current_path);
            return;
        }

        maze[r][c] = 0;

        for (auto &step : steps) {
            int nr = r + std::get<0>(step), nc = c + std::get<1>(step);
            std::string next_path = current_path + std::get<2>(step);
            if (!(0 <= nr && nr < n && 0 <= nc && nc < n)) {
                continue;
            }
            if (maze[nr][nc] == 0) {
                continue;
            }
            dfs(nr, nc, next_path);
        }

        maze[r][c] = 1;
    };

    dfs(0, 0, std::string());
    return paths;
}

int main() {
    std::vector<std::vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
    };
    assert(rat_in_a_maze(maze) == std::vector<std::string>({"DDRDRR", "DRDDRR"}));
    return 0;
}