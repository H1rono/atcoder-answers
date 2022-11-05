use proconio::marker::Chars;

fn main() {
    proconio::input! {
        s: Chars
    }
    let mut ans = None;
    for (i, c) in s.into_iter().enumerate() {
        if c == 'a' {
            ans = Some(i + 1);
        }
    }
    if let Some(i) = ans {
        println!("{}", i);
    } else {
        println!("-1");
    }
}
