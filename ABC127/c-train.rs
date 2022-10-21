use std::cmp;

fn main() {
    proconio::input! {
        n: usize, m: usize,
        lr: [(u32, u32); m]
    }
    let (l_max, r_min) = lr.into_iter().fold((0_u32, n as u32), |(l, r), (li, ri)| {
        (cmp::max(l, li), cmp::min(r, ri))
    });
    if l_max <= r_min {
        println!("{}", r_min - l_max + 1);
    } else {
        println!("0");
    }
}
