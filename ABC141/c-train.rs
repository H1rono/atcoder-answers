fn main() {
    proconio::input! {
        n: usize, k: i32, q: usize,
        corrects: [usize; q]
    }
    let mut correct_count = vec![0; n];
    for i in corrects {
        correct_count[i - 1] += 1;
    }
    for i in 0..n {
        if k + correct_count[i] > q as i32 {
            println!("Yes");
        } else {
            println!("No");
        }
    }
}
