use proconio::marker::Chars;

fn judge(left: &[char], center: char, right: &[char]) -> bool {
    if center != '-' {
        return false;
    }
    let ls: String = left.iter().collect();
    let rs: String = right.iter().collect();
    ls.parse::<i32>().is_ok() && rs.parse::<i32>().is_ok()
}

fn main() {
    proconio::input! {
        a: usize, _: usize,
        s: Chars
    }
    if judge(&s[..a], s[a], &s[a + 1..]) {
        println!("Yes");
    } else {
        println!("No");
    }
}
