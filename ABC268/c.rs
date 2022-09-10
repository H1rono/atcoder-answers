use std::collections::HashMap;

fn main() {
    let cin = std::io::stdin();
    let mut s = String::new();
    cin.read_line(&mut s).unwrap();
    let n = s.trim().parse::<usize>().unwrap();
    cin.read_line(&mut s).unwrap();
    let a: Vec<i32> = s
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let trans = |x: i32| -> i32 {
        if x < 0 {
            x + n as i32
        } else {
            x % n as i32
        }
    };

    let mut a_inv = vec![0_i32; n];
    for i in 0..n {
        a_inv[a[i] as usize % n] = i as i32;
    }
    let mut diffs: HashMap<i32, i32> = HashMap::new();
    for i in 0..n {
        let diff = trans(a_inv[i] - i as i32);
        *diffs.entry(diff).or_insert(0) += 1;
    }
    let mut ans = 0;
    let get_diffs = |i: i32| -> i32 {
        *diffs.get(&trans(i as i32)).unwrap_or(&0)
    };
    for i in 0_i32..n as i32 {
        let _ans = get_diffs(i - 1) + get_diffs(i) + get_diffs(i + 1);
        ans = std::cmp::max(ans, _ans);
    }
    println!("{}", ans);
}
