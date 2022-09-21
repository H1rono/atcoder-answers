use std::io;

fn read_line(cin: &io::Stdin) -> String {
    let mut s = String::new();
    cin.read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn main() {
    let cin = io::stdin();
    let (n, x) = {
        let v: Vec<usize> = read_line(&cin)
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        (v[0], v[2])
    };
    let a: Vec<usize> = read_line(&cin)
        .split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut costs = vec![0; n];
    for &i in a.iter() {
        costs[i] += 1;
    }
    let cost_l = (0 .. x)
        .map(|i| costs[i])
        .sum::<i32>();
    let cost_r = (x + 1 .. n)
        .map(|i| costs[i])
        .sum::<i32>();
    let ans = std::cmp::min(cost_l, cost_r);
    println!("{}", ans);
}