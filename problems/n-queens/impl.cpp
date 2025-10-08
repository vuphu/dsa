#include <vector>
#include <functional>
#include <cassert>

typedef std::vector<std::vector<bool>> Board;

std::vector<Board> solve_n_queens(int n) {
    Board board(n, std::vector<bool>(n, false));
    std::vector<Board> solutions;

    auto has_queen = [&](int r, int c) -> bool {
        if (r < 0 || r >= n || c < 0 || c >= n) {
            return false;
        }
        return board[r][c];
    };

    auto is_safe = [&](const Board &board, int r, int c) -> bool {
        for (int i = r - 1; i >= 0; i--) {
            int step = r - i;
            if (has_queen(i, c) || has_queen(i, c - step) || has_queen(i, c + step)) {
                return false;
            }
        }
        return true;
    };

    std::function<void(int)> attempt = [&](int row) -> void {
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (is_safe(board, row, col)) {
                board[row][col] = true;
                attempt(row + 1);
                board[row][col] = false;
            }
        }
    };

    attempt(0);
    return solutions;
}

int main() {
    std::vector<Board> solutions = solve_n_queens(4);
    assert(solutions.size() == 2);
    return 0;
}
