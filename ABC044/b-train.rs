use proconio::marker::Chars;

fn main() {
    proconio::input! {
        w: Chars
    }
    let mut counts = [0; 26];
    for c in w {
        let i = c as usize - 'a' as usize;
        counts[i] += 1;
    }
    for &c in &counts {
        if c % 2 == 1 {
            println!("No");
            return;
        }
    }
    println!("Yes");
}
