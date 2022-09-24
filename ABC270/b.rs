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

fn solve(x: i32, y: i32, z: i32) -> i32 {
    if x * y < 0 || x.abs() < y.abs() {
        // 壁がゴールを塞いでいない -> ゴールに直行
        return x.abs();
    }
    // 壁がゴールを塞いでいる -> ハンマーが必要
    if y * z > 0 && y.abs() < z.abs() {
        // 壁がハンマーを塞いでいる -> ゴール不可能
        return -1;
    }
    // ハンマー -> ゴールの順に移動してゴール
    return z.abs() + (x - z).abs();
}

fn main() {
    let cin = io::stdin();
    let (x, y, z) = {
        let v = cin.input().to_vec::<i32>().unwrap();
        (v[0], v[1], v[2])
    };
    println!("{}", solve(x, y, z));
}
