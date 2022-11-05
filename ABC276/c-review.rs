use std::cmp;

fn main() {
    proconio::input! {
        n: usize,
        perm: [usize; n]
    }
    let mut perm: Vec<_> = perm.into_iter().map(|i| i - 1).collect();
    let i = perm
        .iter()
        .rev()
        .scan(n, |state, &m| {
            let mi = cmp::min(*state, m);
            let v = *state == mi;
            *state = mi;
            Some(v)
        })
        .collect::<Vec<_>>()
        .into_iter()
        .rev()
        .rposition(|c| c)
        .unwrap_or(0);
    let slice = &mut perm[i..];
    let head = slice[0];
    slice.sort();
    let i = slice.binary_search(&head).unwrap() - 1;
    slice.swap(0, i);
    let slice = &mut slice[1..];
    slice.sort();
    slice.reverse();
    let mut perm: Vec<_> = perm.into_iter().map(|a| (a + 1).to_string()).collect();
    let slice = &mut perm[..n - 1];
    slice.iter_mut().for_each(|s| s.push(' '));
    let ans: String = perm.into_iter().collect();
    println!("{}", ans);
}
