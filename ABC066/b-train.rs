fn is_even_str(s: &str) -> bool {
    let n = s.len();
    if n % 2 == 1 {
        return false;
    }
    let (a, b) = s.split_at(n / 2);
    a == b
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s = s.trim().to_string();
    let mut n = s.len();
    while n > 0 {
        n -= 2;
        if is_even_str(&s[..n]) {
            println!("{}", n);
            return;
        }
    }
    println!("0");
}