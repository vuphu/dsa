#include <vector>
#include <functional>
#include <cassert>

typedef std::vector<std::vector<int>> Board;

std::vector<Board> knight_tour(int n) {
    std::vector<std::pair<int, int>> knight_moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    Board board(n, std::vector<int>(n, 0));
    std::vector<Board> solutions;

    std::function<void(int, int, int)> attempt = [&](int step, int x, int y) -> void {
        if (step == n * n) {
            solutions.push_back(board);
            return;
        }
        for (const auto & [ dx, dy ] : knight_moves) {
            int next_x = x + dx;
            int next_y = y + dy;
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && board[next_x][next_y] == 0) {
                board[next_x][next_y] = step + 1;
                attempt(step + 1, next_x, next_y);
                board[next_x][next_y] = 0;
            }
        }
    };

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            board[x][y] = 1;
            attempt(1, x, y);
            board[x][y] = 0;
        }
    }

    return solutions;
}

int main() {
    std::vector<Board> solutions = knight_tour(5);
    assert(solutions.size() == 1728);
    return 0;
}
