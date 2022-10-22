fn main() {
    proconio::input! {
        n: usize,
        records: [usize; n]
    }
    let mut dp = vec![-1; 2 * n + 2];
    dp[1] = 0;
    for (i, &a) in records.iter().enumerate() {
        let i = i + 1;
        dp[2 * i] = dp[a] + 1;
        dp[2 * i + 1] = dp[a] + 1;
    }
    for &ans in &dp[1..] {
        println!("{}", ans);
    }
}
