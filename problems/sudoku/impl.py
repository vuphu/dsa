from math import sqrt
from typing import List


def print_board(board: List[List[str]]):
    for row in board:
        print(row)
    print()


def solve_sudoku(board: List[List[str]]) -> None:
    n = len(board)
    n_box = int(sqrt(n))

    def get_start_box(r: int, c: int) -> List[int]:
        return [
            r // n_box * n_box,
            c // n_box * n_box
        ]

    def can_put(r: int, c: int, num: int) -> bool:
        for i in range(n):
            values = [board[r][i], board[i][c]]
            if str(num) in values:
                return False

        r_start_box, c_start_box = get_start_box(r, c)
        for i in range(n_box):
            for j in range(n_box):
                if str(num) == board[r_start_box + i][c_start_box + j]:
                    return False

        return True

    def attempt() -> bool:
        for i in range(n):
            for j in range(n):
                if board[i][j] == '.':
                    for k in range(1, n + 1):
                        if can_put(i, j, k):
                            board[i][j] = str(k)
                            if attempt():
                                return True
                            board[i][j] = '.'
                    return False
        return True

    attempt()


if __name__ == "__main__":
    board = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"]
    ]

    print_board(board)
    solve_sudoku(board)
    print_board(board)
