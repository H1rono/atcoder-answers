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
    let n: u8 = cin.input().parse().unwrap();
    let hex = format!("{:#04X}", n);
    println!("{}", &hex[2..]);
}
