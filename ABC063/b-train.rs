use std::collections::HashSet;
use std::io;

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let s: Vec<_> = s.trim().chars().collect();
    let t: HashSet<_> = s.iter().collect();
    if s.len() == t.len() {
        println!("yes");
    } else {
        println!("no")
    }
}
