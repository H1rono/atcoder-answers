fn is_palindromic(s: &str) -> bool {
    let s: Vec<_> = s.chars().collect();
    let ln = s.len();
    let mid = ln / 2;
    for i in 0..mid {
        if s[i] != s[ln - i - 1] {
            return false;
        }
    }
    return true;
}

fn main() {
    proconio::input! {
        a: i32, b: i32
    }
    let mut ans = 0;
    for i in a..=b {
        let i_str = i.to_string();
        if is_palindromic(&i_str) {
            ans += 1;
        }
    }
    println!("{}", ans);
}
