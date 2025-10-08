type Board = Vec<Vec<usize>>;

fn knight_tour(n: usize) -> Vec<Board> {
    let knight_moves = [
        (-2, -1),
        (-2, 1),
        (-1, -2),
        (-1, 2),
        (1, -2),
        (1, 2),
        (2, -1),
        (2, 1),
    ];
    let mut board = vec![vec![0; n]; n];
    let mut solutions = Vec::new();

    fn attempt(
        step: usize,
        x: usize,
        y: usize,
        n: usize,
        board: &mut Board,
        solutions: &mut Vec<Board>,
        knight_moves: &[(isize, isize)],
    ) {
        if step == n * n {
            solutions.push(board.clone());
            return;
        }

        for &(dx, dy) in knight_moves {
            let next_x = x as isize + dx;
            let next_y = y as isize + dy;

            if next_x >= 0
                && next_x < n as isize
                && next_y >= 0
                && next_y < n as isize
                && board[next_x as usize][next_y as usize] == 0
            {
                board[next_x as usize][next_y as usize] = step + 1;
                attempt(
                    step + 1,
                    next_x as usize,
                    next_y as usize,
                    n,
                    board,
                    solutions,
                    knight_moves,
                );
                board[next_x as usize][next_y as usize] = 0;
            }
        }
    }

    for x in 0..n {
        for y in 0..n {
            board[x][y] = 1;
            attempt(1, x, y, n, &mut board, &mut solutions, &knight_moves);
            board[x][y] = 0;
        }
    }

    solutions
}

fn main() {
    let solutions = knight_tour(5);
    assert!(solutions.len() == 1728);
}
