use std::cmp;

fn main() {
    proconio::input! {
        n: usize,
        a: [u64; n]
    }
    let mut evens = vec![]; // 偶数
    let mut odds  = vec![]; // 奇数
    for &v in &a {
        if v % 2 == 0 {
            evens.push(v);
        } else {
            odds.push(v);
        }
    }
    if evens.len() < 2 && odds.len() < 2 {
        println!("-1");
        return;
    }
    let ans_even = if evens.len() < 2 {
        0
    } else {
        evens.sort();
        let l = evens.len();
        evens[l - 1] + evens[l - 2]
    };
    let ans_odd = if odds.len() < 2 {
        0
    } else {
        odds.sort();
        let l = odds.len();
        odds[l - 1] + odds[l - 2]
    };
    let ans = cmp::max(ans_even, ans_odd);
    println!("{}", ans);
}
