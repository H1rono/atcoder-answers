fn read_line() -> std::io::Result<String> {
    let mut s = String::new();
    match std::io::stdin().read_line(&mut s) {
        Ok(_) => Ok(s.trim().to_string()),
        Err(e) => Err(e),
    }
}

fn main() {
    let (x, k): (u64, u64) = {
        let s = read_line().unwrap();
        let mut ws = s.split_whitespace();
        (ws.next().unwrap().parse().unwrap(), ws.next().unwrap().parse().unwrap())
    };
    let x = x % k;
    println!("{}", std::cmp::min(x, k - x));
}
