#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Board;


void print_board(const Board &board) {
    for (const auto &row : board) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<Board> knight_tour(int n) {
    std::vector<std::pair<int, int>> knight_moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    Board board(n, std::vector<int>(n, 0));
    std::vector<Board> ans;

    std::function<void(int,int,int)> attempt = [&](int step, int x, int y) -> void {
        if (step == n * n) {
            ans.push_back(board);
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

    return ans;
}

int main() {
    int n = 5;
    auto boards = knight_tour(n);
    std::cout << "Found " << boards.size() << " solutions" << std::endl;
    if (!boards.empty()) {
        print_board(boards.front());
    }
    return 0;
}
