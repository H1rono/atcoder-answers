use std::error::Error;

fn split_by(list: &[u8], len: usize) -> impl Iterator<Item = (usize, &[u8])> {
    let split_len = list.len() / len + (list.len() % len != 0) as usize;
    (0..split_len).map(move |i| {
        let split_left = i * len;
        let split_right = usize::min((i + 1) * len, list.len());
        (i, &list[split_left..split_right])
    })
}

fn main() -> Result<(), Box<dyn Error>> {
    let line = {
        let mut buf = String::new();
        std::io::stdin().read_line(&mut buf)?;
        buf.trim_end().to_string()
    };
    let (template, target) = {
        let p = line.split(' ').collect::<Vec<_>>();
        (p[0].as_bytes(), p[1].as_bytes())
    };
    let it = (1..template.len()).flat_map(|r| (0..r).map(move |c| (r, c)));
    for (r, c) in it {
        // println!("{r}, {c}");
        let it_inner = split_by(template, r);
        let cond = it_inner.fold(Some(0), |acc, (r2, row)| {
            let a = acc?;
            if row.len() <= c {
                Some(a)
            } else if target.len() <= r2 {
                None
            } else if target[r2] == row[c] {
                Some(r2)
            } else {
                None
            }
        });
        if cond.is_some_and(|i| i + 1 == target.len()) {
            println!("Yes");
            return Ok(());
        }
    }
    println!("No");
    Ok(())
}
