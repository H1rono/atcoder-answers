use std::collections::{HashSet, VecDeque};

fn solve_axis(goal: i32, ps: &[i32]) -> bool {
    let l = ps.len();
    let mut seen: Vec<_> = (0..l + 1).map(|_| HashSet::new()).collect();
    let mut que: VecDeque<(usize, i32)> = VecDeque::new();
    que.push_back((0, 0));
    while let Some((i, p)) = que.pop_front() {
        if seen[i].contains(&p) {
            continue;
        }
        seen[i].insert(p);
        if i == l {
            if p == goal {
                return true;
            }
            continue;
        }
        let dp = ps[i];
        que.push_back((i + 1, p + dp));
        que.push_back((i + 1, p - dp));
    }
    return false;
}

fn main() {
    proconio::input! {
        n: usize, x: i32, y: i32,
        nums: [i32; n]
    }
    let mut xs = vec![];
    let mut ys = vec![];
    for (i, &a) in nums.iter().enumerate() {
        if i % 2 == 0 {
            xs.push(a);
        } else {
            ys.push(a);
        }
    }
    if solve_axis(x - xs[0], &xs[1..]) && solve_axis(y, &ys) {
        println!("Yes");
    } else {
        println!("No");
    }
}
