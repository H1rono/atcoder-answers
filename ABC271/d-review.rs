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
    let (n, s) = {
        let v = cin.input().to_vec::<usize>().unwrap();
        (v[0], v[1])
    };
    let cards = (0..n)
        .map(|_| {
            let v = cin.input().to_vec::<u32>().unwrap();
            (v[0], v[1])
        })
        .collect::<Vec<_>>();
    let mut dp: Vec<Vec<bool>> = Vec::new();
    dp.push(vec![false; s + 1]);
    dp[0][0] = true;
    for (i, (a, b)) in cards.iter().enumerate() {
        dp.push(vec![false; s + 1]);
        for j in 0..=s {
            if !dp[i][j] { continue; }
            let ja = j + *a as usize;
            let jb = j + *b as usize;
            if ja <= s { dp[i + 1][ja] = true; }
            if jb <= s { dp[i + 1][jb] = true; }
        }
    }
    if !dp[n][s] {
        println!("No");
        return;
    }
    println!("Yes");
    let mut is_front = vec![false; n];
    let mut v = s;
    for i in (0..n).rev() {
        let (a, b) = cards[i];
        let (a, b) = (a as usize, b as usize);
        if v >= a && dp[i][v - a] {
            is_front[i] = true;
            v -= a;
        } else {
            is_front[i] = false;
            v -= b;
        }
    }
    let ans: String = is_front
        .into_iter()
        .map(|b| if b { 'H' } else { 'T' })
        .collect();
    println!("{}", ans);
}
