from copy import deepcopy
from typing import List


def print_board(board: List[List[int]]):
    for row in board:
        print(row)
    print()


def knight_tour(n: int) -> List[List[List[str]]]:
    offsets = [-2, -1, 1, 2]
    knight_moves = [(x, y) for x in offsets for y in offsets if abs(x) != abs(y)]
    board = [[0] * n for _ in range(n)]

    ans = []

    def attempt(step: int, x: int, y: int) -> None:
        if step == n * n:
            ans.append(deepcopy(board))
            return
        board[x][y] = step
        for dx, dy in knight_moves:
            next_x, next_y = x + dx, y + dy
            if (0 <= next_x < n) and (0 <= next_y < n) and board[next_x][next_y] == 0:
                attempt(step + 1, next_x, next_y)
        board[x][y] = 0

    for i in range(n):
        for j in range(n):
            attempt(1, i, j)

    return ans


if __name__ == "__main__":
    boards = knight_tour(5)
    print('Found {} solutions'.format(len(boards)))
    print_board(boards[0])
