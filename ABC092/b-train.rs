use std::io;

trait StdinExt {
    fn input(&self) -> String;
}

impl StdinExt for io::Stdin {
    fn input(&self) -> String {
        let mut s = String::new();
        self.read_line(&mut s).unwrap();
        s.trim().to_string()
    }
}

fn main() {
    let cin = io::stdin();
    let n: usize = cin.input().parse().unwrap();
    let (d, x) = {
        let v: Vec<u32> = cin.input().split_whitespace().map(|x| x.parse().unwrap()).collect();
        (v[0], v[1])
    };
    let mut ans = x;
    for _ in 0..n {
        let a: u32 = cin.input().parse().unwrap();
        ans += (d - 1) / a + 1;
    }
    println!("{}", ans);
}