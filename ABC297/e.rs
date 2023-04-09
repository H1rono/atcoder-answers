use std::collections;

fn gen(len: usize, min: usize, max: usize) -> Vec<Vec<usize>> {
    if len == 0 {
        return vec![vec![]];
    }
    let mut res = vec![];
    for i in min..max {
        let it = gen(len - 1, i, max);
        for mut v in it.into_iter() {
            let mut r = vec![i];
            r.append(&mut v);
            res.push(r);
        }
    }
    res
}

fn main() {
    proconio::input! {
        n: usize, k: usize,
        prices: [u64; n]
    }
    let mut billings = collections::HashSet::new();
    for i in 1.. {
        let it = gen(i, 0, n);
        for v in it {
            let sum = v.iter().map(|&i| prices[i]).sum::<u64>();
            billings.insert(sum);
        }
        if billings.len() >= k {
            break;
        }
    }
    let mut billings = billings.into_iter().collect::<Vec<_>>();
    billings.sort();
    println!("{}", billings[k - 1]);
}
