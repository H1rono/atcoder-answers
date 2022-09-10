use std::collections::HashSet;

fn main() {
    let a: Vec<i32> = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().split_whitespace().map(|x| x.parse().unwrap()).collect()
    };
    let a_set: HashSet<i32> = a.iter().cloned().collect();
    println!("{}", a_set.len());
}
