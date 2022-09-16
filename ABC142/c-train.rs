fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let n = s.trim().parse::<usize>().unwrap();
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let a = s.trim().split_whitespace().map(|x| x.parse::<usize>().unwrap()).collect::<Vec<_>>();
    let mut a_inv = vec![0_usize; n];
    for i in 0..n {
        a_inv[a[i] - 1] = i + 1;
    }
    let mut ans = a_inv[0].to_string();
    for i in 1..n {
        ans += " ";
        ans += &a_inv[i].to_string();
    }
    println!("{}", ans);
}
