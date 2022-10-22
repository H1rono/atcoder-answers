use proconio::marker::Chars;

fn main() {
    proconio::input! {
        h: usize, w: usize,
        grid: [Chars; h]
    }
    let ans = (0..w)
        .map(|c| (0..h).filter(|&r| grid[r][c] == '#').count())
        .fold(String::new(), |mut acc, m| {
            if acc.len() > 0 {
                acc.push(' ');
            }
            acc += &m.to_string();
            acc
        });
    println!("{}", ans);
}
