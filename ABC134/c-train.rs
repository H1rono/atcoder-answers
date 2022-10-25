fn main() {
    proconio::input! {
        n: usize,
        a: [i32; n]
    }
    let mut a_sorted = a.clone();
    a_sorted.sort();
    for v in a {
        if a_sorted[n - 1] == v {
            println!("{}", a_sorted[n - 2]);
        } else {
            println!("{}", a_sorted[n - 1]);
        }
    }
}
