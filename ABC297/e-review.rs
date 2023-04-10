use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashSet};

fn main() {
    proconio::input! {
        n: usize, k: usize,
        prices: [u64; n],
    };
    let mut heap = BinaryHeap::new();
    let mut pushed = HashSet::new();
    heap.push(Reverse(0));
    pushed.insert(0);
    let mut ans = 0;
    for _ in 0..=k {
        let Reverse(price) = heap.pop().unwrap();
        ans = price;
        for &p in prices.iter() {
            let new_price = price + p;
            if !pushed.contains(&new_price) {
                heap.push(Reverse(new_price));
                pushed.insert(new_price);
            }
        }
    }
    println!("{}", ans);
}
