#include <iostream>
#include <vector>
#include <functional>

typedef std::vector<std::vector<bool>> Board;

void print_board(const Board &board) {
    for (const auto &row : board) {
        for (auto cell : row) {
            std::cout << (cell ? "Q" : ".") << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<Board> solve_n_queens(int n) {
    Board board(n, std::vector<bool>(n, false));
    std::vector<Board> ans;

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
            ans.push_back(board);
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
    return ans;
}

int main() {
    int n = 4;
    auto boards = solve_n_queens(n);
    for (const auto &board : boards) {
        print_board(board);
    }
    return 0;
}
