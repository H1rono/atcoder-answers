use proconio::marker::Chars;

fn main() {
    const N: usize = 9;
    proconio::input! {
        grid: [Chars; N]
    }
    let ispone_at = |r: usize, c: usize| r < N && c < N && grid[r][c] == '#';
    let pone_indices: Vec<_> = (0..N)
        .flat_map(|r| {
            (0..N)
                // .filter(|&c| ispone_at(r, c)).map(|c| r * N + c)
                .filter_map(move |c| {
                    if !ispone_at(r, c) {
                        return None;
                    }
                    Some(r * N + c)
                })
        })
        .collect();
    let ln = pone_indices.len();
    let mut ans = 0;
    for i in 0..ln {
        let ri = pone_indices[i] / N;
        let ci = pone_indices[i] % N;
        for j in i + 1..ln {
            let rj = pone_indices[j] / N;
            let cj = pone_indices[j] % N;
            let dr = rj as isize - ri as isize;
            let dc = cj as isize - ci as isize;
            let rk = ri as isize + dc;
            let ck = ci as isize - dr;
            if !ispone_at(rk as usize, ck as usize) {
                continue;
            }
            let rl = rk + dr;
            let cl = ck + dc;
            if !ispone_at(rl as usize, cl as usize) {
                continue;
            }
            // println!("({} {}) ({} {})", ri, ci, rj, cj);
            ans += 1;
        }
    }
    println!("{}", ans >> 1)
}
