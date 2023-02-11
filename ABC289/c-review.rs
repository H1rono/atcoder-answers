use std::collections::HashSet;

fn main() {
    let mut line = String::new();
    let stdin = std::io::stdin();
    stdin.read_line(&mut line).unwrap();
    let (n, m) = {
        let v = line
            .trim()
            .split_ascii_whitespace()
            .map(|x| x.parse::<u32>().unwrap())
            .collect::<Vec<_>>();
        (v[0], v[1])
    };
    let mut sets = vec![];
    for _ in 0..m {
        line.clear();
        stdin.read_line(&mut line).unwrap();
        line.clear();
        stdin.read_line(&mut line).unwrap();
        let set: HashSet<u32> = line
            .trim()
            .split_ascii_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        sets.push(set);
    }
    let bits_max = 1 << m;
    let mut ans = 0;
    for b in 0..bits_max {
        let s = (0..m)
            .filter(|i| (b >> i) & 1 == 1)
            .map(|i| &sets[i as usize])
            .fold(HashSet::new(), |state, x| state.union(x).copied().collect());
        if s.len() == n as usize {
            ans += 1;
        }
    }
    println!("{}", ans);
}
