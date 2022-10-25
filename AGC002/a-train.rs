fn main() {
    proconio::input! {
        a: i64, b: i64
    }
    if a > 0 {
        println!("Positive");
        return;
    } else if a == 0 || b >= 0 {
        println!("Zero");
        return;
    }
    let count = b - a + 1;
    if count % 2 == 0 {
        println!("Positive");
    } else {
        println!("Negative");
    }
}
