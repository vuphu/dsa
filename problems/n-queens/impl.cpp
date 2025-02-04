#include <iostream>
#include <vector>

typedef std::vector<std::vector<char>> Board;

void print_board(const Board &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<Board> solve_n_queens(int n) {
    Board board(n, std::vector<char>(n, '.'));
    std::vector<Board> ans;

    auto is_inside_board = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    };

    auto can_put_queen = [&](const Board &board, int r, int c) {
        static const std::vector<std::pair<int, int>> steps = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (const auto & [ dx, dy ] : steps) {
            int k = 1;
            while (is_inside_board(r + k * dx, c + k * dy)) {
                if (board[r + k * dx][c + k * dy] == 'Q') {
                    return false;
                }
                k++;
            }
        }
        return true;
    };

    std::function<void(int)> attempt = [&](int r) -> void {
        if (r == n) {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (board[r][c] == '.' && can_put_queen(board, r, c)) {
                board[r][c] = 'Q';
                attempt(r + 1);
                board[r][c] = '.';
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
