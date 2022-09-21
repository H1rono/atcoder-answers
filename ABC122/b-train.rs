use std::cmp;

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s = s.trim().to_string();
    let mut ans = 0;
    let mut cand_begin: usize = 0;
    for (i, c) in s.chars().enumerate() {
        match c {
            'A' | 'C' | 'G' | 'T' => {
                ans = cmp::max(ans, i - cand_begin + 1);
            },
            _ => {
                cand_begin = i + 1;
            }
        }
    }
    println!("{}", ans);
}