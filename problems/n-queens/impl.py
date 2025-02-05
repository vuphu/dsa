from copy import deepcopy
from typing import List


def print_board(board: List[List[bool]]):
    for row in board:
        for cell in row:
            print("Q" if cell else '.', end=' ')
        print()
    print()


def solve_n_queens(n: int) -> List[List[List[bool]]]:
    board = [[False] * n for _ in range(n)]
    ans = []

    def has_queen(r: int, c: int) -> bool:
        if not (0 <= r < n) or not (0 <= c < n):
            return False
        return board[r][c]

    def is_safe(r: int, c: int) -> bool:
        for i in range(r - 1, -1, -1):
            step = r - i
            if has_queen(i, c) or has_queen(i, c - step) or has_queen(i, c + step):
                return False
        return True

    def attempt(r: int) -> None:
        if r == n:
            ans.append(deepcopy(board))
            return
        for c in range(n):
            if is_safe(r, c):
                board[r][c] = True
                attempt(r + 1)
                board[r][c] = False

    attempt(0)
    return ans


if __name__ == "__main__":
    boards = solve_n_queens(4)
    for board in boards:
        print_board(board)
