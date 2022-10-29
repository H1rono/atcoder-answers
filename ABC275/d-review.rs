use std::collections::{BinaryHeap, HashMap, HashSet};

fn main() {
    proconio::input! {
        n: u64
    }
    let mut dp: HashMap<u64, u64> = HashMap::new();
    let mut seen: HashSet<u64> = HashSet::new();
    let mut bque: BinaryHeap<u64> = BinaryHeap::new();
    dp.insert(0, 1);
    seen.insert(0);
    bque.push(n);
    let mut orders = vec![];
    while let Some(k) = bque.pop() {
        if seen.contains(&k) {
            continue;
        }
        orders.push(k);
        seen.insert(k);
        bque.push(k / 2);
        bque.push(k / 3);
    }
    for k in orders.into_iter().rev() {
        let v = dp[&(k / 2)] + dp[&(k / 3)];
        dp.insert(k, v);
    }
    println!("{}", dp[&n]);
}
