use std::cmp;

fn main() {
    proconio::input! { s: String }
    let mut lefts = vec![0_u64];
    let mut v = 0;
    for c in s.chars() {
        v = if c == '<' { v + 1 } else { 0 };
        lefts.push(v);
    }
    let mut rights = vec![0];
    v = 0;
    for c in s.chars().rev() {
        v = if c == '>' { v + 1 } else { 0 };
        rights.push(v);
    }
    let ans = lefts
        .into_iter()
        .zip(rights.into_iter().rev())
        .map(|(l, r)| cmp::max(l, r))
        .sum::<u64>();
    println!("{}", ans);
}
