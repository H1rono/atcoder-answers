use std::cmp;
use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let s: Vec<_> = s.chars().map(|x| x as i32 - '0' as i32).collect();
    let mut ans = 753;
    let diff = |v: i32| (v - 753).abs();
    for i in 0..s.len() - 3 {
        let v = s[i] * 100 + s[i + 1] * 10 + s[i + 2];
        ans = cmp::min(diff(v), ans);
    }
    println!("{}", ans);
}
