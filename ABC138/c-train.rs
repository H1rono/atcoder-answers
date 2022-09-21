use std::io;

fn read_line(cin: &io::Stdin) -> String {
    let mut s = String::new();
    cin.read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn main() {
    let cin = io::stdin();
    let n: usize = read_line(&cin).parse().unwrap();
    let mut v: Vec<i32> = read_line(&cin)
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    v.sort();
    let mut ans: f64 = v[0] as f64;
    for i in 1..n {
        ans = (ans + v[i] as f64) / 2.0;
    }
    println!("{:.5}", ans);
}
