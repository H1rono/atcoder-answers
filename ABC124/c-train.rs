use proconio::marker::Chars;
use std::cmp;

fn main() {
    proconio::input! {
        s: Chars
    }
    let s: Vec<_> = s.into_iter().map(|c| c == '1').collect();
    let ans1 = s
        .iter()
        .enumerate()
        .map(|(i, &c)| (i % 2) ^ c as usize)
        .sum::<usize>();
    let ans2 = s
        .iter()
        .enumerate()
        .map(|(i, &c)| (1 - i % 2) ^ c as usize)
        .sum::<usize>();
    let ans = cmp::min(ans1, ans2);
    println!("{}", ans);
}
