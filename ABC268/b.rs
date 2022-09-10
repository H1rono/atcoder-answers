fn main() {
    let cin = std::io::stdin();
    let mut s = String::new();
    cin.read_line(&mut s).unwrap();
    let mut t = String::new();
    cin.read_line(&mut t).unwrap();
    let s = s.trim().chars().collect::<Vec<char>>();
    let t = t.trim().chars().collect::<Vec<char>>();
    let (sl, tl) = (s.len(), t.len());
    if sl > tl {
        println!("No");
        return;
    }
    for i in 0..sl {
        if s[i] != t[i] {
            println!("No");
            return;
        }
    }
    println!("Yes");
}
