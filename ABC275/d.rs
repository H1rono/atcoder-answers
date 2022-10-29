use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap, HashSet};

fn main() {
    proconio::input! {
        n: u64
    }
    let mut dp: HashMap<u64, u64> = HashMap::new();
    let mut seen: HashSet<u64> = HashSet::new();
    let mut que: BinaryHeap<Reverse<u64>> = BinaryHeap::new();
    dp.insert(0, 1);
    que.push(Reverse(1));
    que.push(Reverse(2));
    while let Some(Reverse(i)) = que.pop() {
        if seen.contains(&i) {
            continue;
        }
        let v = dp[&(i / 2)] + dp[&(i / 3)];
        seen.insert(i);
        dp.insert(i, v);
        if i * 2 > n {
            continue;
        }
        que.push(Reverse(i * 2 + 0));
        que.push(Reverse(i * 2 + 1));
        que.push(Reverse(i * 3 + 0));
        que.push(Reverse(i * 3 + 1));
        que.push(Reverse(i * 3 + 2));
    }
    println!("{}", dp[&n]);
}
