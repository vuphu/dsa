fn dfs(
    r: usize,
    c: usize,
    current_path: String,
    maze: &mut Vec<Vec<i32>>,
    paths: &mut Vec<String>,
) {
    let n = maze.len();
    let steps = vec![(1, 0, 'D'), (0, -1, 'L'), (0, 1, 'R'), (-1, 0, 'U')];

    if r == n - 1 && c == n - 1 {
        paths.push(current_path);
        return;
    }

    maze[r][c] = 0;

    for step in steps.iter() {
        let (nr, nc) = (r as isize + step.0, c as isize + step.1);
        let next_path = format!("{}{}", current_path, step.2);
        if !(0 <= nr && nr < n as isize && 0 <= nc && nc < n as isize) {
            continue;
        }
        if maze[nr as usize][nc as usize] == 0 {
            continue;
        }
        dfs(nr as usize, nc as usize, next_path, maze, paths);
    }

    maze[r][c] = 1;
}

fn rat_in_a_maze(maze: &mut Vec<Vec<i32>>) -> Vec<String> {
    let mut paths = vec![];
    dfs(0, 0, String::default(), maze, &mut paths);
    paths
}

fn main() {
    let mut maze = vec![
        vec![1, 0, 0, 0],
        vec![1, 1, 0, 1],
        vec![1, 1, 0, 0],
        vec![0, 1, 1, 1],
    ];
    assert!(rat_in_a_maze(&mut maze) == vec!["DDRDRR", "DRDDRR"]);
}
