fn main() {
    proconio::input! {
        n: usize,
        a: [usize; n]
    }
    let mut seen = vec![false; n];
    let mut next = 0;
    let mut ans = 0;
    while !seen[next] {
        ans += 1;
        seen[next] = true;
        if next == 1 {
            ans -= 1;
            break;
        }
        next = a[next] - 1;
    }
    if next == 1 {
        println!("{}", ans);
    } else {
        println!("-1");
    }
}