use std::collections::HashSet;

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut s: u32 = s.trim().parse().unwrap();
    let mut nums: HashSet<u32> = HashSet::new();
    nums.insert(s);
    let mut ans = 1;
    loop {
        s = if s % 2 == 0 {
            s / 2
        } else {
            3 * s + 1
        };
        ans += 1;
        if nums.contains(&s) {
            break;
        }
        nums.insert(s);
    }
    println!("{}", ans);
}
