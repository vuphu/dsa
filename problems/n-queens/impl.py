from copy import deepcopy
from typing import List


def print_board(board: List[List[int]]):
    for row in board:
        print(row)
    print()


def solve_n_queens(n: int) -> List[List[List[str]]]:
    queen_symbol, dot_symbol = 'Q', '.'
    board = [[dot_symbol] * n for _ in range(n)]
    ans = []

    def is_inside_board(r: int, c: int) -> bool:
        return 0 <= r < n and 0 <= c < n

    def can_put_queen(r: int, c: int) -> bool:
        # 8-directions in which the queen can move
        steps = [(i, j) for i in range(-1, 2) for j in range(-1, 2) if (i, j) != (0, 0)]

        for dx, dy in steps:
            k = 1
            while is_inside_board(r + k * dx, c + k * dy):
                if board[r + k * dx][c + k * dy] == queen_symbol:
                    return False
                k += 1

        return True

    def attemp(r: int) -> None:
        if r == n:
            ans.append(deepcopy(board))
            return

        for c in range(n):
            if board[r][c] == dot_symbol and can_put_queen(r, c):
                board[r][c] = queen_symbol
                attemp(r + 1)
                board[r][c] = dot_symbol

    attemp(0)
    return ans


if __name__ == "__main__":
    boards = solve_n_queens(4)
    for board in boards:
        print_board(board)
