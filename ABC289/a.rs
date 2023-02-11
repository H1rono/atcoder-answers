fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s: String = s
        .chars()
        .map(|c| match c {
            '0' => "1".to_string(),
            '1' => "0".to_string(),
            _ => c.to_string(),
        })
        .collect::<Vec<_>>()
        .join("");
    print!("{}", s);
}
