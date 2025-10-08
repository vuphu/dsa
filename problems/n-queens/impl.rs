type Board = Vec<Vec<bool>>;

fn solve_n_queens(n: usize) -> Vec<Board> {
    let mut board = vec![vec![false; n]; n];
    let mut solutions = Vec::new();

    fn has_queen(r: isize, c: isize, n: usize, board: &Board) -> bool {
        if r < 0 || r >= n as isize || c < 0 || c >= n as isize {
            return false;
        }
        board[r as usize][c as usize]
    }

    fn is_safe(r: usize, c: usize, n: usize, board: &Board) -> bool {
        for i in (0..r).rev() {
            let step = r - i;
            if has_queen(i as isize, c as isize, n, board)
                || has_queen(i as isize, c as isize - step as isize, n, board)
                || has_queen(i as isize, c as isize + step as isize, n, board)
            {
                return false;
            }
        }
        true
    }

    fn attempt(r: usize, n: usize, board: &mut Board, solutions: &mut Vec<Board>) {
        if r == n {
            solutions.push(board.clone());
            return;
        }
        for c in 0..n {
            if is_safe(r, c, n, board) {
                board[r][c] = true;
                attempt(r + 1, n, board, solutions);
                board[r][c] = false;
            }
        }
    }

    attempt(0, n, &mut board, &mut solutions);
    solutions
}

fn main() {
    let solutions = solve_n_queens(4);
    assert!(solutions.len() == 2);
}
