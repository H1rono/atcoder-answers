fn main() {
    proconio::input! {
        h: usize, _: usize,
        s: [String; h],
    }
    let ans = s.iter().map(|s| s.replace("TT", "PC"));
    for s in ans {
        println!("{}", s);
    }
}
