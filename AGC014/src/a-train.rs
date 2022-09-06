use std::io::stdin;
use std::collections::HashSet;

fn is_even(n: i32) -> bool {
    n % 2 == 0
}

fn main() {
    let mut l = String::new();
    stdin().read_line(&mut l).unwrap();
    let nums: Vec<i32> = l
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    let (mut a, mut b, mut c) = (nums[0], nums[1], nums[2]);
    let mut set = HashSet::<(i32, i32, i32)>::new();
    let mut count = 0;
    while is_even(a) && is_even(b) && is_even(c) {
        if set.contains(&(a, b, c)) {
            println!("-1");
            return;
        }
        set.insert((a, b, c));
        count += 1;
        let (a_, b_, c_) = (a, b, c);
        a = (b_ + c_) / 2;
        b = (c_ + a_) / 2;
        c = (a_ + b_) / 2;
    }
    println!("{}", count);
}
