fn ceil10(n: i32) -> i32 {
    (n as f64 / 10.0).ceil() as i32 * 10
}

fn main() {
    proconio::input! {
        ts: [i32; 5]
    }
    let dig1 = |n: i32| match n % 10 {
        0 => 10,
        x => x,
    };
    let mut ts = ts;
    ts.sort_by(|&a, &b| dig1(a).partial_cmp(&dig1(b)).unwrap());
    let ans = ts[0] + ceil10(ts[1]) + ceil10(ts[2]) + ceil10(ts[3]) + ceil10(ts[4]);
    println!("{}", ans);
}
