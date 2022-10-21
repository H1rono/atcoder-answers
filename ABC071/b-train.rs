use proconio::marker::Chars;

fn main() {
    proconio::input! {
        s: Chars
    }
    let mut contains_char = vec![false; 26];
    for c in s {
        let i = c as usize - 'a' as usize;
        contains_char[i] = true;
    }
    let mut ans = None;
    for (i, b) in contains_char.into_iter().enumerate() {
        if b {
            continue;
        }
        let c = std::char::from_u32(i as u32 + 'a' as u32).unwrap();
        ans = Some(c);
        break;
    }
    match ans {
        Some(c) => println!("{}", c),
        None => println!("None"),
    };
}
