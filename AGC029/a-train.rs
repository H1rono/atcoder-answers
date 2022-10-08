use proconio::input;

fn main() {
    input! {
        s: String
    }
    let mut ans: u64 = 0;
    let mut black_count = 0;
    for c in s.chars() {
        if c == 'W' {
            ans += black_count;
        } else {
            black_count += 1;
        }
    }
    println!("{}", ans);
}
