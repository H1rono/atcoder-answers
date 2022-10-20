use std::cmp;

/// vにxを挿入しても順序が保たれる最小の位置を返す
fn lower_bound(v: &[i64], x: i64) -> usize {
    let mut ng = -1;
    let mut ok = v.len() as isize;
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        if v[mid as usize] >= x {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    ok as usize
}

fn main() {
    proconio::input! {
        h: i64, w: i64, r: i64, c: i64,
        n: usize,
        walls: [(i64, i64); n],
        q: usize,
        queries: [(char, i64); q],
    }
    let mut walls_rc = vec![0; n];
    let mut walls_cr = vec![0; n];
    for (i, &(r, c)) in walls.iter().enumerate() {
        let r = r - 1;
        let c = c - 1;
        walls_rc[i] = r + c * h;
        walls_cr[i] = c + r * w;
    }
    walls_rc.sort();
    walls_cr.sort();
    let mut r = r - 1;
    let mut c = c - 1;
    for (d, l) in queries {
        match d {
            'U' => {
                let i = lower_bound(&walls_rc, r + c * h);
                let border = if i == 0 || walls_rc[i - 1] / h != c {
                    0
                } else {
                    (walls_rc[i - 1] % h) + 1
                };
                r = cmp::max(cmp::max(0, r - l), border);
            }
            'D' => {
                let i = lower_bound(&walls_rc, r + c * h);
                let border = if i == walls_rc.len() || walls_rc[i] / h != c {
                    h - 1
                } else {
                    (walls_rc[i] % h) - 1
                };
                r = cmp::min(cmp::min(h - 1, r + l), border);
            }
            'L' => {
                let i = lower_bound(&walls_cr, c + r * w);
                let border = if i == 0 || walls_cr[i - 1] / w != r {
                    0
                } else {
                    walls_cr[i - 1] % w + 1
                };
                c = cmp::max(cmp::max(0, c - l), border);
            }
            'R' => {
                let i = lower_bound(&walls_cr, c + r * w);
                let border = if i == walls_cr.len() || walls_cr[i] / w != r {
                    w - 1
                } else {
                    walls_cr[i] % w - 1
                };
                c = cmp::min(cmp::min(w - 1, c + l), border);
            }
            _ => unreachable!(),
        }
        println!("{} {}", r + 1, c + 1);
    }
}
