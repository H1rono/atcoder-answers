fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let n: u64 = s.trim().parse().unwrap();
    let mut cands: Vec<u64> = vec![0];
    for i in 0..n {
        let m = n >> i;
        if m == 0 {
            break;
        }
        if m & 1 == 0 {
            continue;
        }
        for cand in cands.clone() {
            cands.push(cand | (1 << i));
        }
    }
    let mut ans = String::new();
    for cand in cands {
        ans += &cand.to_string();
        ans += "\n";
    }
    print!("{}", ans);
}
