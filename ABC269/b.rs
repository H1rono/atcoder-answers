fn main() {
    let mut ss: Vec<String> = vec![];
    let cin = std::io::stdin();
    for _ in 0..10 {
        let mut s = String::new();
        cin.read_line(&mut s).unwrap();
        ss.push(s);
    }
    let mut a = 0;
    let mut b = 0;
    let mut c = 0;
    let mut d = 0;
    // search a, c
    for (i, s) in ss.clone().into_iter().enumerate() {
        let mut ac_defined = false;
        for (j, ch) in s.chars().enumerate() {
            if ch == '#' {
                a = i + 1;
                c = j + 1;
                ac_defined = true;
                break;
            }
        }
        if ac_defined {
            break;
        }
    }
    // search b, d
    for (i, s) in ss.into_iter().enumerate().rev() {
        let mut bd_defined = false;
        for (j, ch) in s.chars().collect::<Vec<_>>().into_iter().enumerate().rev() {
            if ch == '#' {
                b = i + 1;
                d = j + 1;
                bd_defined = true;
                break;
            }
        }
        if bd_defined {
            break;
        }
    }
    println!("{} {}", a, b);
    println!("{} {}", c, d);
}
