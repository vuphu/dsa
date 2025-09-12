def rat_in_a_maze(maze: list[list[int]]) -> list[str]:
    n = len(maze)
    steps = [(1, 0, 'D'), (0, -1, 'L'), (0, 1, 'R'), (-1, 0, 'U')]
    paths = []

    def dfs(r: int, c: int, current_path: str = str()) -> None:
        if r == n - 1 and c == n - 1:
            paths.append(current_path)
            return

        maze[r][c] = 0

        for dr, dc, move in steps:
            if not (0 <= r + dr < n) or not (0 <= c + dc < n):
                continue
            if not maze[r + dr][c + dc]:
                continue
            dfs(r + dr, c + dc, current_path + move)

        maze[r][c] = 1

    dfs(0, 0)
    return paths


if __name__ == "__main__":
    maze = [
        [1, 0, 0, 0],
        [1, 1, 0, 1],
        [1, 1, 0, 0],
        [0, 1, 1, 1]
    ]
    assert rat_in_a_maze(maze) == ["DDRDRR", "DRDDRR"]
