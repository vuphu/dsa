type Board = Vec<Vec<i32>>;

fn solve_sudoku(board: &mut Board) {
    let n = board.len();
    let n_box = (n as f64).sqrt() as usize;

    let get_start_box =
        |r: usize, c: usize| -> (usize, usize) { ((r / n_box) * n_box, (c / n_box) * n_box) };

    let is_safe = |r: usize, c: usize, num: i32, board: &Board| -> bool {
        for i in 0..n {
            if board[r][i] == num || board[i][c] == num {
                return false;
            }
        }
        let (r_start_box, c_start_box) = get_start_box(r, c);
        for i in 0..n_box {
            for j in 0..n_box {
                if board[r_start_box + i][c_start_box + j] == num {
                    return false;
                }
            }
        }
        true
    };

    fn attempt(
        board: &mut Board,
        n: usize,
        n_box: usize,
        is_safe: &dyn Fn(usize, usize, i32, &Board) -> bool,
    ) -> bool {
        for i in 0..n {
            for j in 0..n {
                if board[i][j] > 0 {
                    continue;
                }
                for k in 1..=n as i32 {
                    if is_safe(i, j, k, board) {
                        board[i][j] = k;
                        if attempt(board, n, n_box, is_safe) {
                            return true;
                        }
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
        true
    }

    attempt(board, n, n_box, &is_safe);
}

fn has_correct_values(values: &[i32]) -> bool {
    let mut sorted_values = values.to_vec();
    sorted_values.sort();
    sorted_values
        .iter()
        .enumerate()
        .all(|(i, &val)| val == i as i32 + 1)
}

fn main() {
    let n = 9;
    let mut board: Vec<Vec<i32>> = vec![
        vec![5, 3, 0, 0, 7, 0, 0, 0, 0],
        vec![6, 0, 0, 1, 9, 5, 0, 0, 0],
        vec![0, 9, 8, 0, 0, 0, 0, 6, 0],
        vec![8, 0, 0, 0, 6, 0, 0, 0, 3],
        vec![4, 0, 0, 8, 0, 3, 0, 0, 1],
        vec![7, 0, 0, 0, 2, 0, 0, 0, 6],
        vec![0, 6, 0, 0, 0, 0, 2, 8, 0],
        vec![0, 0, 0, 4, 1, 9, 0, 0, 5],
        vec![0, 0, 0, 0, 8, 0, 0, 7, 9],
    ];

    solve_sudoku(&mut board);

    let (mut row, mut column, mut _box) = (Vec::new(), Vec::new(), Vec::new());
    for i in 0..n {
        let n_box = (n as f64).sqrt() as usize;
        row.push(board[0][i]);
        column.push(board[i][0]);
        _box.push(board[i / n_box][i % n_box]);
    }

    assert!(has_correct_values(&row));
    assert!(has_correct_values(&column));
    assert!(has_correct_values(&_box));
}
