fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let x: usize = s.trim().parse().unwrap();
    let max_num = 2 * x + 1;
    let mut prime = vec![true; max_num];
    prime[0] = false;
    prime[1] = false;
    for i in 2..max_num {
        if !prime[i] {
            continue;
        }
        if i >= x {
            println!("{}", i);
            break;
        }
        for j in 2..(max_num / i) {
            prime[i * j] = false;
        }
    }
}
