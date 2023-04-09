fn main() {
    proconio::input! {
        a: u64, b: u64
    };
    let (mut a, mut b) = (a, b);
    let mut ans: u64 = 0;
    while a != b {
        ans += a / b + b / a;
        let c = (a % b, b % a);
        if c.0 == 0 || c.1 == 0 {
            ans -= 1;
            break;
        }
        a = c.0;
        b = c.1;
    }
    println!("{}", ans);
}
