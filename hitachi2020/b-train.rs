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
            match r {
                Ok(v) => {
                    res.push(v);
                },
                Err(e) => {
                    return Err(e);
                }
            }
        }
        Ok(res)
    }
}

use std::cmp;

fn main() {
    let cin = io::stdin();
    let (_fridge_num, _microwave_num, coupon_num) = {
        let v: Vec<usize> = cin.input().to_vec().unwrap();
        (v[0], v[1], v[2])
    };
    let fridge_prices: Vec<u32> = cin.input().to_vec().unwrap();
    let microwave_prices: Vec<u32> = cin.input().to_vec().unwrap();
    let mut ans =
        fridge_prices.iter().min().unwrap()
        + microwave_prices.iter().min().unwrap();
    for _ in 0..coupon_num {
        let (fridge, microwave, discount) = {
            let v: Vec<u32> = cin.input().to_vec().unwrap();
            (v[0] as usize - 1, v[1] as usize - 1, v[2])
        };
        ans = cmp::min(
            ans,
            fridge_prices[fridge] + microwave_prices[microwave] - discount
        );
    }
    println!("{}", ans);
}
