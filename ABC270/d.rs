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

fn main() {
    let cin = io::stdin();
    let (mut n, k) = {
        let v = cin.input().to_vec::<usize>().unwrap();
        (v[0], v[1])
    };
    let a = cin.input().to_vec::<usize>().unwrap();
    let mut takahashi = 0;
    let find = |n: usize| -> usize {
        let (mut l, mut r) = (0, k as i32);
        loop {
            let mid = ((r + l) / 2) as usize;
            if a[mid] <= n {
                l = mid as i32;
            } else {
                r = mid as i32;
            }
            if r - l <= 1 {
                break;
            }
        }
        a[l as usize]
    };
    loop {
        let dtakahashi = find(n);
        takahashi += dtakahashi;
        n -= dtakahashi;
        let daoki = find(n);
        if n <= daoki {
            break;
        }
        n -= daoki;
    }
    println!("{}", takahashi);
}
