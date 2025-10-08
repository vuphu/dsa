from copy import deepcopy

type Board = list[list[int]]


def knight_tour(n: int) -> list[Board]:
    knight_moves = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]
    board = [[0] * n for _ in range(n)]
    solutions = []

    def attempt(step: int, x: int, y: int) -> None:
        if step == n * n:
            solutions.append(deepcopy(board))
            return
        for dx, dy in knight_moves:
            next_x, next_y = x + dx, y + dy
            if (0 <= next_x < n) and (0 <= next_y < n) and board[next_x][next_y] == 0:
                board[next_x][next_y] = step + 1
                attempt(step + 1, next_x, next_y)
                board[next_x][next_y] = 0

    for x in range(n):
        for y in range(n):
            board[x][y] = 1
            attempt(1, x, y)
            board[x][y] = 0

    return solutions


if __name__ == "__main__":
    solutions = knight_tour(5)
    assert len(solutions) == 1728
