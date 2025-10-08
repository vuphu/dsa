from copy import deepcopy

type Board = list[list[bool]]


def solve_n_queens(n: int) -> list[Board]:
    board = [[False] * n for _ in range(n)]
    solutions = []

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
            solutions.append(deepcopy(board))
            return
        for c in range(n):
            if is_safe(r, c):
                board[r][c] = True
                attempt(r + 1)
                board[r][c] = False

    attempt(0)
    return solutions


if __name__ == "__main__":
    solutions = solve_n_queens(4)
    assert len(solutions) == 2
