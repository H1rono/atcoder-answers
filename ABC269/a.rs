fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let v: Vec<i32> = s.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let ans = (v[0] + v[1]) * (v[2] - v[3]);
    println!("{}", ans);
    println!("{}", "Takahashi");
}
