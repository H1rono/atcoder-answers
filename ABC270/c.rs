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

fn main() {
    let cin = io::stdin();
    let (n, x, y) = {
        let v = cin.input().to_vec::<usize>().unwrap();
        (v[0], v[1] - 1, v[2] - 1)
    };
    let mut graph: Vec<Vec<usize>> = (0..n).map(|_| Vec::new()).collect();
    for _ in 1..n {
        let (u, v) = {
            let v = cin.input().to_vec::<usize>().unwrap();
            (v[0] - 1, v[1] - 1)
        };
        graph[u].push(v);
        graph[v].push(u);
    }
    let mut seen = vec![false; n];
    let mut que: VecDeque<Vec<usize>> = vec![vec![x]].into_iter().collect();
    loop {
        if let Some(v) = que.pop_front() {
            if let Some(&i) = v.last() {
                seen[i] = true;
                for &j in &graph[i] {
                    if !seen[j] {
                        let mut nv = v.clone();
                        nv.push(j);
                        if j == y {
                            println!("{}", nv.into_iter().fold(String::from(""), |acc, m| format!("{} {}", acc, m + 1)));
                            return;
                        } else {
                            que.push_back(nv);
                        }
                    }
                }
            }
        }
    }
}
