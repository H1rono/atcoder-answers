use std::cmp;

fn main() {
    proconio::input! {
        n: usize,
        nums: [i32; n]
    }
    let props: Vec<_> = nums
        .iter()
        .map(|&a| {
            let mut a = a;
            let mut f2 = 0;
            while a & 1 == 0 {
                a >>= 1;
                f2 += 1;
            }
            let mut f3 = 0;
            while a % 3 == 0 {
                a /= 3;
                f3 += 1;
            }
            (a, f2, f3)
        })
        .collect();
    let (f2_min, f3_min) = props
        .iter()
        .fold((None, None), |(f2_min, f3_min), (_, f2, f3)| {
            let f2 = cmp::min(f2_min.unwrap_or(f2), f2);
            let f3 = cmp::min(f3_min.unwrap_or(f3), f3);
            (Some(f2), Some(f3))
        });
    let &f2_min = f2_min.unwrap();
    let &f3_min = f3_min.unwrap();
    let (_, ans) = props.iter().fold((-1, Some(0)), |(v, cnt), &(a, f2, f3)| {
        if v != -1 && v != a {
            return (0, None);
        }
        let cnt = cnt.unwrap() + (f2 - f2_min) + (f3 - f3_min);
        (a, Some(cnt))
    });
    if let Some(ans) = ans {
        println!("{}", ans);
    } else {
        println!("-1");
    }
}
