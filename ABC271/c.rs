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

use std::collections::VecDeque;

const MAX: u32 = 10_0000_0000;

fn main() {
    let cin = io::stdin();
    cin.input();
    let mut a: Vec<u32> = cin.input().to_vec().unwrap();
    a.sort();
    let mut a: VecDeque<_> = a.into_iter().collect();
    let mut ans = 0;
    let mut sold_count: u32 = 0;
    loop {
        if a.len() as u32 + sold_count < 2 || ans == MAX {
            break;
        }
        if let Some(v) = a.pop_front() {
            if v == ans + 1 {
                // 持ってる
                ans += 1;
                continue;
            } else if v <= ans {
                // 既巻なので売る
                sold_count += 1;
                if sold_count < 2 {
                    continue;
                }
            } else {
                // 入れ直し
                a.push_front(v);
            }
        }
        // 2巻売る
        match sold_count {
            0 => {
                a.pop_back().unwrap();
                a.pop_back().unwrap();
            },
            1 => {
                a.pop_back().unwrap();
                sold_count = 0;
            },
            _ => {
                sold_count -= 2;
            }
        };
        ans += 1;
    }
    println!("{}", ans);
}
