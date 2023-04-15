use num_bigint::BigUint;
use std::collections::VecDeque;

fn q2i(q: &VecDeque<i8>) -> BigUint {
    let n = q
        .iter()
        .map(|x| x.to_string())
        .collect::<Vec<_>>()
        .join("")
        .parse::<BigUint>()
        .unwrap();
    n % BigUint::from(998244353u32)
}

fn main() {
    let stdin = std::io::stdin();
    let q: usize = {
        let mut line = String::new();
        stdin.read_line(&mut line).unwrap();
        line.trim().parse().unwrap()
    };
    let mut queue = VecDeque::from(vec![1]);
    for _ in 0..q {
        let mut line = String::new();
        stdin.read_line(&mut line).unwrap();
        let mut iter = line
            .split_whitespace()
            .map(|s| s.trim().parse::<i8>().unwrap());
        let n: i8 = iter.next().unwrap();
        match n {
            1 => {
                let x: i8 = iter.next().unwrap();
                queue.push_back(x);
                if queue.len() > 20 {
                    let n = q2i(&queue);
                    queue = VecDeque::from(
                        n.to_string()
                            .chars()
                            .map(|x| x.to_digit(10).unwrap() as i8)
                            .collect::<Vec<_>>(),
                    );
                }
            }
            2 => {
                queue.pop_front();
            }
            3 => {
                let n = q2i(&queue);
                println!("{}", n);
            }
            _ => unreachable!(),
        }
    }
}
