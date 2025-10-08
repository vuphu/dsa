#include <vector>
#include <functional>
#include <cassert>
#include <algorithm>

typedef std::vector<std::vector<int>> Board;

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

bool has_correct_values(std::vector<int> &values) {
    std::vector<int> sorted_values = values;
    sort(sorted_values.begin(), sorted_values.end());
    for (int i = 0; i < sorted_values.size(); i++) {
        if (sorted_values[i] != i + 1) {
            return false;
        }
    }
    return true;
};


int main() {
    int n = 9;
    Board board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };

    solve_sudoku(board);

    std::vector<int> row, column, box;
    for (int i = 0; i < n; i++) {
        int n_box = (int)sqrt(n);
        row.push_back(board[0][i]);
        column.push_back(board[i][0]);
        box.push_back(board[i / n_box][i % n_box]);
    }

    assert(has_correct_values(row) == true);
    assert(has_correct_values(column) == true);
    assert(has_correct_values(box) == true);

    return 0;
}