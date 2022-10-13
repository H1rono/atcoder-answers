use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines().map(|l| l.unwrap());
    let (h, w) = {
        let v = lines
            .next().unwrap()
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap())
            .collect::<Vec<_>>();
        (v[0], v[1])
    };
    let mut grid = (0..h)
        .map(|_| lines.next().unwrap().chars().collect::<Vec<_>>())
        .collect::<Vec<_>>();
    let dpos = [
        (-1, -1), (-1, 0), (-1, 1),
        ( 0, -1),          ( 0, 1),
        ( 1, -1), ( 1, 0), ( 1, 1)
    ];
    for r in 0..h {
        for c in 0..w {
            let mut bomb_count: u8 = 0;
            for &(dr, dc) in &dpos {
                let (nr, nc) = (r as isize + dr, c as isize + dc);
                if nr < 0 || nr >= h as isize || nc < 0 || nc >= w as isize {
                    continue;
                }
                if grid[nr as usize][nc as usize] == '#' {
                    bomb_count += 1;
                }
            }
            if grid[r][c] == '.' {
                grid[r][c] = (bomb_count + '0' as u8) as char;
            }
        }
    }
    grid.into_iter()
        .for_each(move |row| println!("{}", row.into_iter().collect::<String>()));
}
