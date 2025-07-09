#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <functional>

typedef std::vector<std::vector<int>> Board;

void print_board(const Board &board) {
    for (const auto &row : board) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void solve_sudoku(Board &board) {
    int n = board.size();
    int n_box = int(sqrt(n));

    auto get_start_box = [&](int r, int c) -> std::pair<int, int> {
        return std::make_pair((r / n_box) * n_box, (c / n_box) * n_box);
    };

    auto is_safe = [&](int r, int c, int num) -> bool {
        for (int i = 0; i < n; i++) {
            if (board[r][i] == num || board[i][c] == num) {
                return false;
            }
        }

        auto[r_start_box, c_start_box] = get_start_box(r, c);
        for (int i = 0; i < n_box; i++) {
            for (int j = 0; j < n_box; j++) {
                if (board[r_start_box + i][c_start_box + j] == num) {
                    return false;
                }
            }
        }

        return true;
    };

    std::function<bool()> attempt = [&]() -> bool {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 0) {
                    continue;
                }
                for (int k = 1; k <= n; k++) {
                    if (is_safe(i, j, k)) {
                        board[i][j] = k;
                        if (attempt()) {
                            return true;
                        }
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
        return true;
    };

    attempt();
}


int main() {
    Board board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    print_board(board);
    solve_sudoku(board);
    print_board(board);

    return 0;
}