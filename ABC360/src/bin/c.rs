use std::error::Error;

fn main() -> Result<(), Box<dyn Error>> {
    let buf = std::io::read_to_string(std::io::stdin())?;
    let mut lines = buf.lines();
    let n: usize = lines.next().unwrap().parse()?;
    let ats = lines
        .next()
        .unwrap()
        .split(' ')
        .map(|a| a.parse())
        .collect::<Result<Vec<usize>, _>>()?;
    let weights = lines
        .next()
        .unwrap()
        .split(' ')
        .map(|a| a.parse())
        .collect::<Result<Vec<u32>, _>>()?;
    let mut boxes = (0..n).map(|_| vec![]).collect::<Vec<_>>();
    for i in 0..n {
        boxes[ats[i] - 1].push(weights[i]);
    }
    let mut sum: u32 = 0;
    for b in boxes.iter() {
        if b.len() < 2 {
            continue;
        }
        let s: u32 = b.iter().sum();
        sum += s - b.iter().fold(b[0], |a, b| u32::max(a, *b));
    }
    println!("{sum}");
    Ok(())
}
