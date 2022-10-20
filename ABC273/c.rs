use std::cmp::Ordering;
use std::collections::HashMap;

fn main() {
    proconio::input! {
        n: usize,
        a: [i64; n],
    }
    let mut a_sorted = a.clone();
    a_sorted.sort();
    let mut a_counts = HashMap::new();
    let mut a_uniq = vec![];
    for i in 0..n {
        let count = a_counts.entry(a_sorted[i]).or_insert(0);
        *count += 1;
        if *count == 1 {
            a_uniq.push(a_sorted[i]);
        }
    }
    let a_kinds = a_uniq.len();
    let solve = |k: usize| {
        let border_i = match a_kinds.cmp(&k) {
            Ordering::Less => a_kinds,
            Ordering::Equal => a_kinds,
            Ordering::Greater => a_kinds - k - 1,
        };
        match a_uniq.get(border_i) {
            Some(x) => *a_counts.get(x).unwrap(),
            None => 0,
        }
    };
    for k in 0..n {
        println!("{}", solve(k));
    }
}
