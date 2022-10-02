use std::io;
use std::str::FromStr;

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

trait StringExt {
    fn to_vec<T: FromStr>(&self) -> Result<Vec<T>, T::Err>;
}

impl StringExt for String {
    fn to_vec<T: FromStr>(&self) -> Result<Vec<T>, T::Err> {
        let mut res = vec![];
        for r in self.split_whitespace().map(|x| x.parse::<T>()) {
            res.push(r?);
        }
        Ok(res)
    }
}

use std::collections::{VecDeque, HashSet};

fn main() {
    let cin = io::stdin();
    let n: usize = cin.input().parse().unwrap();
    let a: HashSet<u32> = cin
        .input()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .filter(|&x| x as usize <= n)
        .collect();
    let mut a: Vec<_> = a.into_iter().collect();
    a.sort();
    let mut a: VecDeque<_> = a.into_iter().collect();
    // 売却ストック
    let mut sold_count = (n - a.len()) as u32;
    let mut next_vol = 1;
    loop {
        if let Some(&x) = a.front() { // a.len() >= 1
            if x > next_vol { // 次の巻が手元にない
                match sold_count {
                    0 => {
                        if a.len() < 2 { // もう売っても意味なし
                            break;
                        }
                        a.pop_back().unwrap();
                        a.pop_back().unwrap();
                    },
                    1 => { // 1冊売れば買える
                        a.pop_back().unwrap();
                        sold_count = 0;
                    },
                    _ => { // 何もしなくても買える
                        sold_count -= 2;
                    }
                }
            } else { // 次の巻が手元にある
                a.pop_front().unwrap();
            }
        } else { // 巻のストックなし
            if sold_count < 2 { // 売却ストックもない
                break;
            }
            sold_count -= 2;
        }
        next_vol += 1;
    }
    println!("{}", next_vol - 1);
}
