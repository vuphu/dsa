from math import sqrt
from typing import List


def print_board(board: List[List[int]]):
    for row in board:
        print(row)
    print()


def solve_sudoku(board: List[List[int]]) -> None:
    n = len(board)
    n_box = int(sqrt(n))

    def get_start_box(r: int, c: int) -> List[int]:
        return [r // n_box * n_box, c // n_box * n_box]

    def is_safe(r: int, c: int, num: int) -> bool:
        for i in range(n):
            values = [board[r][i], board[i][c]]
            if num in values:
                return False

        r_start_box, c_start_box = get_start_box(r, c)
        for i in range(n_box):
            for j in range(n_box):
                if board[r_start_box + i][c_start_box + j] == num:
                    return False

        return True

    def attempt() -> bool:
        for i in range(n):
            for j in range(n):
                if board[i][j] > 0:
                    continue
                for k in range(1, n + 1):
                    if is_safe(i, j, k):
                        board[i][j] = k
                        if attempt():
                            return True
                        board[i][j] = 0
                return False

        return True

    attempt()


if __name__ == "__main__":
    board = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]
    ]

    print_board(board)
    solve_sudoku(board)
    print_board(board)
