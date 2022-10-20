fn main() {
    proconio::input! {
        h: usize, w: usize, r: usize, c: usize,
        n: usize,
        walls: [(usize, usize); n],
        q: usize,
        queries: [(char, u64); q],
    }
    let (mut r, mut c) = (r - 1, c - 1);
    let mut iswall = vec![vec![false; w]; h];
    for (i, j) in walls {
        iswall[i - 1][j - 1] = true;
    }
    for (d, l) in queries {
        let (dr, dc) = match d {
            'U' => (-1, 0),
            'D' => (1, 0),
            'L' => (0, -1),
            'R' => (0, 1),
            _ => unreachable!(),
        };
        let mut nr = r as i64;
        let mut nc = c as i64;
        for _ in 0..l {
            nr += dr;
            nc += dc;
            if (nr < 0 || nr >= h as i64)
                || (nc < 0 || nc >= w as i64)
                || iswall[nr as usize][nc as usize]
            {
                nr -= dr;
                nc -= dc;
                break;
            }
        }
        r = nr as usize;
        c = nc as usize;
        println!("{} {}", r + 1, c + 1);
    }
}
