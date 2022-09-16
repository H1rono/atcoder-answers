fn read_line() -> std::io::Result<String> {
    let mut s = String::new();
    match std::io::stdin().read_line(&mut s) {
        Ok(_) => Ok(s.trim().to_string()),
        Err(e) => Err(e),
    }
}

fn read_vec() -> std::io::Result<Vec<i32>> {
    let s = read_line()?;
    Ok(s.split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect())
}

fn main() {
    let n: usize = read_line().unwrap().parse().unwrap();
    let mut d = read_vec().unwrap();
    d.sort();
    let mid = n / 2;
    println!("{}", d[mid] - d[mid - 1]);
}
