use proconio::marker::Chars;
use std::cmp;

fn main() {
    proconio::input! {
        _: usize,
        s: Chars
    }
    let ans = s
        .iter()
        .scan(0, |state, &x| {
            *state += if x == 'I' { 1 } else { -1 };
            Some(*state)
        })
        .fold(0, cmp::max);
    println!("{}", ans);
}
