use std::collections::BinaryHeap;

fn main() {
    proconio::input! {
        n: usize, m: usize,
        prices: [u32; n]
    }
    let mut prices_pq = BinaryHeap::new();
    for p in prices {
        prices_pq.push(p);
    }
    for _ in 0..m {
        let p = prices_pq.pop().unwrap() >> 1;
        prices_pq.push(p);
    }
    let ans = prices_pq.into_iter().fold(0_u64, |acc, m| acc + m as u64);
    println!("{}", ans);
}
