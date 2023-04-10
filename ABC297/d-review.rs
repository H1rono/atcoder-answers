fn main() {
    proconio::input! {
        a: u64, b: u64
    }
    let d = |a: u64, b: u64| a / b - (a % b == 0) as u64;
    let ans = std::iter::repeat(4)
        .scan((a, b), |state, _| {
            let &mut (a, b) = state;
            if a == 0 || b == 0 {
                return None;
            }
            *state = (a % b, b % a);
            Some(d(a, b) + d(b, a))
        })
        .sum::<u64>();
    println!("{}", ans);
}
