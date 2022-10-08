fn main() {
    proconio::input! {
        n: usize,
        a: [i32; n]
    }
    let ans = a.into_iter().sum::<i32>();
    println!("{}", ans);
}