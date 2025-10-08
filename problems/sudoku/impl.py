from math import sqrt

type Board = list[list[int]]


def solve_sudoku(board: Board) -> None:
    n = len(board)
    n_box = int(sqrt(n))

    def get_start_box(r: int, c: int) -> list[int]:
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


def has_correct_values(values: list[int]) -> bool:
    return sorted(values) == list(range(1, len(values) + 1))


if __name__ == "__main__":
    n = 9
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

    solve_sudoku(board)

    assert has_correct_values(board[0]) == True
    assert has_correct_values([board[i][0] for i in range(n)]) == True
    assert has_correct_values([board[i][j] for i in range(int(sqrt(n))) for j in range(int(sqrt(n)))]) == True
