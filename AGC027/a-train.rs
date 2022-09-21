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
    let (n, x) = {
        let v: Vec<usize> = cin.input().split_whitespace().map(|x| x.parse().unwrap()).collect();
        (v[0], v[1] as u64)
    };
    let mut a: Vec<u64> = cin.input().split_whitespace().map(|x| x.parse().unwrap()).collect();
    a.sort();
    let mut accum = 0;
    for (i, &v) in a.iter().enumerate() {
        accum += v;
        if accum > x {
            println!("{}", i);
            return;
        }
    }
    println!("{}", if accum == x { n } else { n - 1 });
}
