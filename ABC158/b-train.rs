use std::cmp;
use proconio::input;

fn main() {
    input! {
        n: u128, a: u128, b: u128
    }
    let ans = a * (n / (a + b));
    let n = n % (a + b);
    let ans = ans + cmp::min(n, a);
    println!("{}", ans);
}
